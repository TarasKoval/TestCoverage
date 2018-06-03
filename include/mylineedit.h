#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include<QtWidgets>
#include<QDebug>
#include<QKeyEvent>
#include<QDateTime>

class myLineEdit : public QLineEdit {
Q_OBJECT
private:
    ulong timeTemp;
    int keyPressesCounter;
    std::vector<ulong> *timeVector;
public:
    explicit myLineEdit(QWidget *obj);

    const std::vector<ulong> &getTimeVector() const;

    void keyPressEvent(QKeyEvent *event) override;

    void keyReleaseEvent(QKeyEvent *event) override;

signals:

    void timeVectorDone();

public slots:

    void keyPressed(QKeyEvent *event);

    void keyReleased(QKeyEvent *event);
};

#endif // MYLINEEDIT_H
