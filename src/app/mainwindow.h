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
#include <QJsonObject>
#include <QJsonArray>

class MainWindow : public QMainWindow 
{
    Q_OBJECT

// Constructor/destructor
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QTabWidget* tabs;
    QWidget* CreateTab(QJsonArray);
    QJsonObject ReadJSON();
    void onButtonClicked();
};
#endif