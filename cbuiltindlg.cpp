#include "cbuiltindlg.h"
#include <QDebug>

CBuiltinDlg::CBuiltinDlg(QWidget *parent) //建構函數
    : QDialog(parent)
{
    QGridLayout* gridLayout = new QGridLayout;
    displayTextEdit = new QTextEdit("Qt內建對話盒示範"); //產生物件實體於記憶體中，將記憶體的位址存於 displayTextEdit變數
    colorPushBtn    = new QPushButton("顏色對話盒");
    errorPushBtn    = new QPushButton("錯誤訊息對話盒");
    filePushBtn     = new QPushButton("檔案對話盒");
    fontPushBtn     = new QPushButton("字體對話盒");
    inputPushBtn    = new QPushButton("輸入對話盒");
    pagePushBtn     = new QPushButton("分頁設定對話盒");
    progressPushBtn = new QPushButton("進度對話盒");
    printPushBtn    = new QPushButton("列印對話盒");

    gridLayout->addWidget(colorPushBtn,0,0,1,1);
    gridLayout->addWidget(errorPushBtn,0,1,1,1);
    gridLayout->addWidget(filePushBtn,0,2,1,1);
    gridLayout->addWidget(fontPushBtn,1,0,1,1);
    gridLayout->addWidget(inputPushBtn,1,1,1,1);
    gridLayout->addWidget(pagePushBtn,1,2,1,1);
    gridLayout->addWidget(progressPushBtn,2,0,1,1);
    gridLayout->addWidget(printPushBtn,2,1,1,1);
    gridLayout->addWidget(displayTextEdit,3,0,3,3);

    setLayout(gridLayout);
    setWindowTitle("內建對話盒視窗示範");
    resize(800,600);
    connect(colorPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn())); //將訊號clicked()連接至槽函數doPushBtn()
    connect(errorPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(filePushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(fontPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(inputPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(pagePushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(progressPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(printPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));

}

CBuiltinDlg::~CBuiltinDlg() = default; //解構函數

void CBuiltinDlg::doPushBtn() //槽函數實作
    {
      QPushButton* btn = qobject_cast<QPushButton*>(sender());
      if (btn == colorPushBtn)
      {
          QPalette palette = displayTextEdit->palette(); //調出displayTextEdit所屬的調色盤物件
          const QColor& color = QColorDialog::getColor(palette.color(QPalette::Base),
                                                 this,"選擇顏色");
          if(color.isValid())
          {
              palette.setColor(QPalette::Text, color);
              displayTextEdit->setPalette(palette);
          }


      }
      if (btn == filePushBtn)
      {
          /*QString fileName =QFileDialog::getOpenFileName(this,"挑選檔案",".","任何檔案(*.*);;文字檔(*.txt);;HTML檔(*.html)");
          displayTextEdit->setText(fileName);*/
          QString fileName = QFileDialog::getSaveFileName(this,"儲存檔案", ".");
          displayTextEdit->setText(fileName);

      }

    }
