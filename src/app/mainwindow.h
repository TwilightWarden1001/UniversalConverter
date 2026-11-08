#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QComboBox>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QMap>
#include <QString>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSqlDatabase>

class MainWindow : public QMainWindow 
{
    Q_OBJECT

// Constructor/destructor
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QSqlDatabase units_DB_connection;
    QTabWidget* tabs;
    QWidget* CreateTab(std::string);
    void onButtonClicked();
};
#endif