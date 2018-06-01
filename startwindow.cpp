#include "startwindow.h"

startWindow::startWindow(QWidget *obj) : QMainWindow(obj),
                                         buttonLogIn(nullptr), buttonSignUp(nullptr), login(nullptr) {
    auto label = new QLabel("Welcome!");
    auto labelLogin = new QLabel("&Enter Login: ");
    login = new QLineEdit();
    buttonLogIn = new QRadioButton("&LogIn");
    buttonSignUp = new QRadioButton("&SignUp");
    auto buttonNext = new QPushButton("&Next");

    labelLogin->setBuddy(login);

    auto layout = new QGridLayout();
    auto hLayout = new QHBoxLayout();

    hLayout->setSpacing(30);
    hLayout->setMargin(30);
    hLayout->addWidget(buttonLogIn);
    hLayout->addWidget(buttonSignUp);
    buttonLogIn->setChecked(true);

    layout->columnMinimumWidth(100);
    layout->columnStretch(1);
    layout->rowMinimumHeight(300);
    layout->rowStretch(1);

    layout->setSpacing(30);
    layout->setMargin(30);
    layout->addWidget(label, 0, 0);
    layout->addLayout(hLayout, 0, 1);
    layout->addWidget(labelLogin, 1, 0);
    layout->addWidget(login, 1, 1);
    layout->addWidget(buttonNext, 2, 2);

    QObject::connect(buttonNext, SIGNAL(clicked(bool)), this, SLOT(openInputWindow()));

    auto central = new QWidget();
    setCentralWidget(central);
    centralWidget()->setLayout(layout);

    setWindowTitle("Main Window");
    setFixedSize(800, 600);
}


void startWindow::openInputWindow() {
    if (buttonLogIn->isChecked()) {

        QFile file1(QString("../data/" + login->text() + ".txt"));
        if (!file1.open(QIODevice::ReadOnly)) {
            QMessageBox::warning(this, "Error", "This user is not registered!");
            login->setFocus();
        } else {
            file1.close();
            hide();
            myInputWindow = new inputWindow(this, login->text(), false);
            myInputWindow->show();
            login->setFocus();
        }
    } else {

        QFile file1(QString("../data/" + login->text() + ".txt"));
        if (!file1.open(QIODevice::ReadOnly)) {
            file1.close();
            hide();
            myInputWindow = new inputWindow(this, login->text(), true);
            myInputWindow->show();
            login->setFocus();
        } else {
            QMessageBox::warning(this, "Error", "This user is already registered!");
            login->setFocus();
        }
    }
}
