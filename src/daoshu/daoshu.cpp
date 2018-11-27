#include <QtWidgets/QApplication>
#include "daoshu_window.h"
// #include "controls.h"
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    DaoshuWindow window{600};
    // Controls window;
    window.setWindowTitle("Daoshu");
    window.show();
    return app.exec();
}