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

    qrc_dialog qd(qrc_path, dir_path);
    int ret = qd.exec();
    if (ret == QDialog::Accepted)
    {
        QFile file(qd.get_qrc_name());
        if (!file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text))
            QMessageBox::critical(&qd, "Error", "qrc文件保存失败");
        QTextStream ts(&file);

        ts << "<RCC>\n";
        ts << QString("\t<qresource prefix=\"%1\">\n").arg(qd.get_rcc_prefix());
        auto list = qd.get_rcc_file_list();
        for (const auto &item: list)
        {
            ts << "\t\t" + QString("<file>%1</file>\n").arg(item);
        }
        ts << "\t</qresource>\n";
        ts << "</RCC>\n";
    }
    return 0;
}
