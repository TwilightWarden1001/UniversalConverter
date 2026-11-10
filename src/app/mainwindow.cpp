#include "mainwindow.h"
#include "convertermiddleman.h"
#include <QMessageBox>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QStringList> 
#include <string>
using namespace std;

// Constructor
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) 
{
    // 1. Initialize the tab widget
    tabs = new QTabWidget(this);

    // 2. Create the Database Connection
    units_DB_connection = QSqlDatabase::addDatabase("QSQLITE");
    units_DB_connection.setDatabaseName("units.db");
    if (units_DB_connection.open() == true) {
        qDebug() << "Database is connected";
    } else {
        qDebug() << units_DB_connection.lastError().text();
    }

    // 3. Create The Tabs
    tabs->addTab(CreateTab("temperature"), "Temperature");
    tabs->addTab(CreateTab("distance"), "Distance");

    // 4. Set the Central Widget
    setCentralWidget(tabs);
}

// Destructor
MainWindow::~MainWindow() {}

QWidget* MainWindow::CreateTab(string tableName) 
{
    // 1. Create the tab
    QWidget *tab = new QWidget;
        
    // 2. Create the layouts
    QVBoxLayout *mainLayout = new QVBoxLayout();
    QHBoxLayout *unitLayout = new QHBoxLayout();
    QHBoxLayout *userLayout = new QHBoxLayout();

    // 3. Create the widgets
    QComboBox *unit1 = new QComboBox(); 
    QComboBox *unit2 = new QComboBox();
    QLineEdit *input = new QLineEdit();
    QLineEdit *result = new QLineEdit();
    QPushButton *convertButton = new QPushButton("Convert");
    result->setReadOnly(true);

    // 4. Give all the widgets names
    unit1->setObjectName("fromBox");
    unit2->setObjectName("toBox");
    input->setObjectName("userInput");
    result->setObjectName("result");

    // 5. Query all the units for that table and add them
    QString qStringTable = QString::fromStdString(tableName);
    QString queryText = "SELECT * FROM " + qStringTable;
    units_DB_connection.open();
    QSqlQuery readUnits(units_DB_connection);
    if (readUnits.exec(queryText)) {
        while (readUnits.next()) {
            qDebug() << readUnits.value(0) << readUnits.value(1) << readUnits.value(2);
            QString unit = readUnits.value("name").toString();
            unit1->addItem(unit);
            unit2->addItem(unit);
        }
    } else {
        qDebug() << readUnits.lastError().text();
        qDebug() << readUnits.lastError().databaseText();
        qDebug() << readUnits.lastError().driverText();
    }
    units_DB_connection.close();
        
    // 6. Add the Widgets
    unitLayout->addWidget(unit1);
    unitLayout->addWidget(unit2);
    userLayout->addWidget(input);
    userLayout->addWidget(result);
    mainLayout->addLayout(unitLayout);
    mainLayout->addLayout(userLayout);
    mainLayout->addWidget(convertButton);
    mainLayout->addStretch(1);
    tab->setLayout(mainLayout);

    // 7. Connect the button and return the tab
    connect(convertButton, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    return tab;
}

void MainWindow::onButtonClicked() {   
    qDebug() << "Convert Button Clicked";

    // 1. Get the current tabs index, name and widget
    int index = tabs->currentIndex();
    QString tabName = tabs->tabText(index);
    QWidget* tab = tabs->widget(index);

    // 2. Get the text from the two combo boxes and the user input
    QString input = tab->findChild<QLineEdit*>("userInput")->text();
    QString fromUnit = tab->findChild<QComboBox*>("fromBox")->currentText();
    QString toUnit = tab->findChild<QComboBox*>("toBox")->currentText();

    // 3. Convert the QStrings to normal strings
    string tabString = tabName.toStdString();
    string inputString = input.toStdString();
    string fromString = fromUnit.toStdString();
    string toString = toUnit.toStdString();

    // 4. Get the result widget for later
    QLineEdit* result = tab->findChild<QLineEdit*>("result");

    // Check if we have no input
    if (input.isEmpty()) {
        QMessageBox::warning(this, "Null/Empty Input", "Input field cannot be empty.");   
        return;
    }
    
    // 5. Create the ConverterMiddleman object
    ConverterMiddleman router;
    
    // 6. Call our router
    string text = router.route(tabString, inputString, fromString, toString);

    // Basic error handling
    if (text.substr(0, 6) == "ERROR:") {
        QMessageBox::warning(this, "Invalid Input", QString::fromStdString(text));
        return;
    }

    // 7. Write the result to the Line Edit
    result->setText(QString::fromStdString(text));
}