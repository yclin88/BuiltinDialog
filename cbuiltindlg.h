#ifndef CBUILTINDLG_H
#define CBUILTINDLG_H

#include <QDialog>
#include <QtWidgets>

class CBuiltinDlg : public QDialog
{
    Q_OBJECT //巨集(Qt定義的)

public:
    explicit CBuiltinDlg(QWidget *parent = nullptr);
    ~CBuiltinDlg() override;
private:
    QTextEdit*   displayTextEdit;
    QPushButton* colorPushBtn;
    QPushButton* errorPushBtn;
    QPushButton* filePushBtn;
    QPushButton* fontPushBtn;
    QPushButton* inputPushBtn;
    QPushButton* pagePushBtn;
    QPushButton* progressPushBtn;
    QPushButton* printPushBtn;
private slots:
    void doPushBtn();
};
#endif // CBUILTINDLG_H
