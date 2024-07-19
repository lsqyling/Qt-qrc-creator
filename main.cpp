#include <QApplication>
#include <QPushButton>
#include <QTextCodec>
#include <QFileDialog>
#include "qrc_dialog.h"
#include "QTextStream"
#include "QMessageBox"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QString qrc_path(argv[1]);
    QString dir_path(argv[2]);

    qrc_path = qrc_path.replace('\\', '/');
    dir_path = dir_path.replace('\\', '/');

    if (qrc_dialog::entry(qrc_path, dir_path))
        return 0;
    return -1;
}