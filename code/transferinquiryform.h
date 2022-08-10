#ifndef TRANSFERINQUIRYFORM_H
#define TRANSFERINQUIRYFORM_H

#include <QWidget>
#include "graphics_view_zoom.h"
#include "subwaygraph.h"
#include "addstationdialog.h"


namespace Ui {
class TransferInquiryForm;
}

class TransferInquiryForm : public QWidget
{
    Q_OBJECT

public:
    explicit TransferInquiryForm(QWidget *parent = nullptr);
    ~TransferInquiryForm();



private:
    Ui::TransferInquiryForm *ui;

    Graphics_view_zoom *myView;     //自定义视图，用于鼠标缩放
    QGraphicsScene *scene;          //场景
    SubwayGraph* subwayGraph;       //后端管理类

    friend class MainWindow;

private slots:


};

#define LINE_INFO_WIDTH 0   //预留边框用于信息展示
#define MARGIN 30           //视图左边距
#define NET_WIDTH 2000      //网络图最大宽度
#define NET_HEIGHT 2000     //网络图最大高度
#define SCENE_WIDTH (LINE_INFO_WIDTH+MARGIN*2+NET_WIDTH)    //视图宽度
#define SCENE_HEIGHT (MARGIN*2+NET_HEIGHT)                  //视图高度

#define EDGE_PEN_WIDTH 2    //线路边宽
#define NODE_HALF_WIDTH 3   //节点大小

#endif // TRANSFERINQUIRYFORM_H
