#include "mainwindow.h"
#include "convertermiddleman.h"
#include <QMessageBox>
#include <QFile>
#include <QByteArray>
#include <QJsonDocument>
#include <string>
using namespace std;

// Constructor
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) 
{
    // 1. Initialize the tab widget
    tabs = new QTabWidget(this);

    // 2. Get the JSON data
    QJsonObject jsonData;
    jsonData = ReadJSON();

    // 2. Get the data for each to pass
    QJsonArray tempArray = jsonData["temperature"].toArray();
    QJsonArray kitchenArray = jsonData["kitchen"].toArray();

    // 3. Create the tabs
    tabs->addTab(CreateTab(tempArray), "Temperature"); // index 0
    tabs->addTab(CreateTab(kitchenArray), "Kitchen");  // Index 1

    // 4. Set the Central Widget
    setCentralWidget(tabs);
}

// Destructor
MainWindow::~MainWindow() {}

QJsonObject MainWindow::ReadJSON() 
{
    // 1. Create a file and byte array object
    QFile file(":/json/units");
    QByteArray jsonBytes;

    // If it can't open the file, throw an error and return a blank QJsonObject
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file";
        return QJsonObject();
    }

    // 2. Read everything into bytes
    jsonBytes = file.readAll();
    
    // 3. Close the file
    file.close();

    // 4. Convert the bytes to a document object
    QJsonDocument doc = QJsonDocument::fromJson(jsonBytes);

    // 5. Convert the document object to a JSON object
    QJsonObject obj = doc.object();

    // Printing for debugging
    qDebug() << "Successfully loaded JSON data:" << obj;

    // Return the JSON object
    return obj;
}

QWidget* MainWindow::CreateTab(QJsonArray data) 
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

    // 5. Fill the combo boxes
    for (const QJsonValue &value : data) {
        unit1->addItem(value.toString());
        unit2->addItem(value.toString());
    }
        
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

void MainWindow::onButtonClicked() 
{
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

    // Check if the units are the same
    if (fromUnit == toUnit) {
        result->setText(input);
        return;
    }

    // 5. Create the ConverterMiddleman object
    ConverterMiddleman router;

    // 6. Call our router
    string text = router.route(tabString, inputString, fromString, toString);

    result->setText(QString::fromStdString(text));
}