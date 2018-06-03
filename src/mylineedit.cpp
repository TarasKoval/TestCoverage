#include "include/mylineedit.h"

myLineEdit::myLineEdit(QWidget *obj) :
        QLineEdit(obj), timeTemp(0), keyPressesCounter(2), timeVector(new std::vector<ulong>) {}

void myLineEdit::keyPressed(QKeyEvent *event) {
    ulong difference = 0;
    difference = event->timestamp() - timeTemp;
    timeVector->push_back(difference);
}

void myLineEdit::keyReleased(QKeyEvent *event) {
    timeTemp = event->timestamp();
    if (keyPressesCounter == 11) {
        if (text() != "demolition") {
            QMessageBox::warning(this, "Error", "You need to input \"demolition\" without errors");
            keyPressesCounter = 0;
            timeVector->clear();
            clear();
            this->setFocus();
        } else {
            timeVector->erase(timeVector->begin());
            emit timeVectorDone();
        }
    }
    keyPressesCounter++;
}

void myLineEdit::keyReleaseEvent(QKeyEvent *event) {

    QLineEdit::keyReleaseEvent(event);
    keyReleased(event);
}


void myLineEdit::keyPressEvent(QKeyEvent *event) {

    QLineEdit::keyPressEvent(event);
    keyPressed(event);
}

const std::vector<ulong> &myLineEdit::getTimeVector() const {
    return *timeVector;
}
