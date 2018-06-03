#include <QtWidgets>
#include "include/startwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    startWindow win;


    win.show();
    return app.exec();
}
