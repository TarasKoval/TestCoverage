#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QtWidgets>
#include "inputwindow.h"
#include <QFile>

class startWindow : public QMainWindow {
Q_OBJECT
private:
    inputWindow *myInputWindow;
    QRadioButton *buttonLogIn;
    QRadioButton *buttonSignUp;
    QLineEdit *login;
public:
    explicit startWindow(QWidget *obj = nullptr);

public slots:

    void openInputWindow();
};

#endif // STARTWINDOW_H
