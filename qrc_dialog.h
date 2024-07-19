//
// Created by 10580.
//

#ifndef QT_QRC_QRC_DIALOG_H
#define QT_QRC_QRC_DIALOG_H

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class qrc_dialog; }
QT_END_NAMESPACE

class qrc_dialog : public QDialog
{
Q_OBJECT

public:
    explicit qrc_dialog(const QString &qrc_path, const QString &dir,  QWidget *parent = nullptr);

    ~qrc_dialog() override;

    QString get_qrc_name() const;
    QString get_rcc_prefix() const;
    QStringList get_rcc_file_list() const;

    static bool entry(const QString &qrc_path, const QString &dir_path);



private:
    static QString get_relative_path(const QString &img_prefix, const QString &qrc_prefix);
    void on_push_button_clicked();


    Ui::qrc_dialog *ui;
    bool exit_{false};
    QString qrc_prefix_;
    QString img_prefix_;
    QStringList imgfiles_;
};


#endif //QT_QRC_QRC_DIALOG_H
