//
// Created by 10580.
//

// You may need to build the project (run Qt uic code generator) to get "ui_qrc_dialog.h" resolved
#include <QMessageBox>
#include "qrc_dialog.h"
#include "ui_qrc_dialog.h"
#include "QFileDialog"
#include "fmt/core.h"
#include "QTextStream"


qrc_dialog::qrc_dialog(const QString &qrc_path, const QString &dir, QWidget *parent) :
        QDialog(parent), ui(new Ui::qrc_dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("qrc文件生成器");

    imgfiles_ =
            QFileDialog::getOpenFileNames(this, "请选择要导入的资源文件", dir,
                                          "文件(*.*)");
    if (imgfiles_.isEmpty())
    {
        exit_ = true;
        return ;
    }

    img_prefix_ = imgfiles_[0].left(imgfiles_[0].lastIndexOf("/") + 1);
    qrc_prefix_ = qrc_path.left(qrc_path.lastIndexOf("/") + 1);
    on_push_button_clicked();
}

qrc_dialog::~qrc_dialog()
{
    delete ui;
}

QString qrc_dialog::get_qrc_name() const
{
    return qrc_prefix_ + ui->lineEditFileName->text() + ui->lineEditFileSuffixName->text();
}

QString qrc_dialog::get_relative_path(const QString &img_prefix, const QString &qrc_prefix)
{
    auto imglist = img_prefix.split("/", Qt::SkipEmptyParts);
    auto qrclist = qrc_prefix.split("/", Qt::SkipEmptyParts);
    int qrclen = qrclist.size();
    int imglen = imglist.size();
    QString relative;
    int i;
    for (i = 0; i < std::min(imglen, qrclen); ++i)
    {
        if (qrclist[i] != imglist[i])
            break;
    }
    int n = qrclen - i;
    while (n--) relative += "../";
    for (; i < imglen; ++i)
        relative += imglist[i] + "/";

    return relative;
}

QString qrc_dialog::get_rcc_prefix() const
{
    return ui->lineEditRccPrefix->text();
}

QStringList qrc_dialog::get_rcc_file_list() const
{
    QString relative = get_relative_path(img_prefix_, qrc_prefix_);
    QStringList list;
    for (const auto &file: imgfiles_)
    {
        auto filename = file.right(file.size() - file.lastIndexOf("/") - 1);
        list << (relative + filename);
    }
    return list;
}

bool qrc_dialog::entry(const QString &qrc_path, const QString &dir_path)
{
    qrc_dialog qd(qrc_path, dir_path);
    if (qd.exit_)
        return false;
    return (qd.exec() == QDialog::Accepted);
}

void qrc_dialog::on_push_button_clicked()
{
    connect(ui->pushButtonOk, &QPushButton::clicked,
            [=, this] {
                QFile file(get_qrc_name());
                if (file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text))
                {
                    QTextStream ts(&file);
                    ts << "<RCC>\n";
                    ts << QString("\t<qresource prefix=\"%1\">\n").arg(get_rcc_prefix());
                    auto list = get_rcc_file_list();
                    for (const auto &item: list)
                    {
                        ts << "\t\t" + QString("<file>%1</file>\n").arg(item);
                    }
                    ts << "\t</qresource>\n";
                    ts << "</RCC>\n";
                    file.close();
                    accept();
                }
                else
                {
                    QMessageBox::critical(this, "Error", "qrc文件保存失败");
                    reject();
                }
            });
}
