#include "inputwindow.h"

inputWindow::inputWindow(QWidget *obj, QString rhsFileName, bool rhsCreateNewUser) :
        QMainWindow(obj), fileName(std::move(rhsFileName)), createNewUser(rhsCreateNewUser),
        lineEdit(new myLineEdit(this)) {
    auto widget = new QWidget();

    auto label = new QLabel();
    label->setText("enter word:  \"demolition\"");
    label->setBuddy(lineEdit);

    auto layout = new QGridLayout();
    layout->setMargin(15);
    layout->setSpacing(30);
    layout->addWidget(label, 0, 0);
    layout->addWidget(lineEdit, 0, 1);

    QObject::connect(this, SIGNAL(windowCloses()), this->parentWidget(), SLOT(show()));

    QObject::connect(lineEdit, SIGNAL(timeVectorDone()), SLOT(timeVectorIsReady()));

    setCentralWidget(widget);
    centralWidget()->setLayout(layout);

    setWindowTitle("Input Window");
    setFixedSize(600, 400);
}

void inputWindow::closeEvent(QCloseEvent *event) {
    emit windowCloses();
    event->accept();
}

void inputWindow::timeVectorIsReady() {
    std::vector<ulong> perfectUserData;
    if (createNewUser) {
        Write(fileName, lineEdit->getTimeVector());
        QMessageBox::about(this, "Message", "Data was saved");
        close();
    } else {
        Read(fileName, perfectUserData);
        auto answer = fullCheck(perfectUserData, lineEdit->getTimeVector());
        if (answer) {
            QMessageBox::about(this, "Message", "Welcome!");
            close();
        } else {
            QMessageBox::warning(this, "Message", "Password incorect!");
            close();
        }
    }
}
