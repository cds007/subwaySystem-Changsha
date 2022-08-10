#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graphics_view_zoom.h"
#include "subwaygraph.h"
#include "transferinquiryform.h"
#include "subwaymapview.h"
#include "addstationdialog.h"
#include "addlinesdialog.h"
#include "apphelpdialog.h"
#include "attractioninquirydialog.h"

#include <QLabel>

#include <QMainWindow>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createAds(); //创建广告
    void createActions();   //创建动作
    void createMenus();     //创建菜单
    void createToolBars();  //创建工具栏
    void anyconnect(); //所有槽函数


    //由线路表计算混合颜色
    QColor getLinesColor(const QList<int>& linesList);
    //获得线路表的名字集
    QString getLinesName(const QList<int>& linesList);
    //将站点的经纬度地理坐标转为视图坐标
    QPointF transferCoord(QPointF coord);
    //绘制网络图的边
    void drawEdges (const QList<Edge>& edgesList);
    //绘制网络图的站点节点
    void drawStations (const QList<int>& stationsList);

    //绘制网络图的边，换乘界面
    void drawEdges2 (const QList<Edge>& edgesList);
    //绘制网络图的站点节点，换乘界面
    void drawStations2 (const QList<int>& stationsList);


private slots:

    //action 槽函数
    //设置isShowToolBarAction和isShowStatusAction选中状态发生变化槽函数
    void on_isShowToolBarAction_triggered(bool checked);
    void on_isShowStatusTipAction_triggered(bool checked);

    //关于Qt槽函数
    void on_aboutQtAction_triggered();
    //关于作者槽函数
    void on_aboutAuthorAction_triggered();

    //视图放大槽函数
    void on_zoomInAction_triggered();
    //视图缩小槽函数
    void on_zoomOutAction_triggered();
    //视图恢复默认槽函数
    void on_restoreDefaultSizeAction_triggered();

    //打开换乘查询槽函数
    void on_transferInquiryAction_triggered();
    //换乘查询槽函数
    void on_inquirypushButton_clicked();

    //添加站点槽函数
    void on_addStationAction_triggered();
    //添加站点功能函数，点击addstation里的按钮之后会调用
    void addStations();

    //添加线路槽函数
    void on_addCircuitAction_triggered();
    //添加线路功能函数，点击添加线路按钮之后
    void addlines();
    //更新选择部件
    void updateComboBox();
    //换乘查询，重置函数
    void restore();
    //连接线路槽函数
    void connectlines();

    //查看长沙地铁线路图槽函数
    void on_subwayMapViewAction_triggered();

    //查看帮助槽函数
    void on_appHelpAction_triggered();

    //查看景点查询界面
    void on_attractionInquiryAction_triggered();
    //景点查询功能函数
    void attractionInquiry();


    //动作查看所有线路图槽函数
    void on_actionLineMap_triggered();



private:
    Ui::MainWindow *ui;

    //各项菜单
    QMenu *setUpMenu;
    QMenu *functionMenu;
    QMenu *subwayMapMenu;
    QMenu *attractionInquiryMenu; //景点查询菜单
    QMenu *viewMenu; //视图
    QMenu *observeMenu; //查看
    QMenu *appHelpMenu; //帮助
    QMenu *aboutMenu; //关于

    //各项工具栏
    QToolBar *zoomTool; //放大缩小工具栏
    QToolBar *functionTool; //功能工具栏
    QToolBar *attractionInquiryTool; //景点查询工具栏

    //设置action
    QAction *exitAction; //退出动作

    //功能action
    QAction *transferInquiryAction; //换乘地铁查询
    QAction *addCircuitAction; //添加线路动作
    QAction *addStationAction; //添加站点动作

    //地铁线路图查看action
    QAction *subwayMapViewAction;

    //景点查询动作action
    QAction *attractionInquiryAction;

    //视图action
    QAction *zoomInAction; //放大
    QAction *zoomOutAction; //缩小
    QAction *restoreDefaultSizeAction; //恢复默认大小

    //查看action
    QAction *isShowToolBarAction; //是否显示工具栏
    QAction *isShowStatusTipAction; //是否显示状态栏

    //帮助action
    QAction *appHelpAction; //使用说明动作

    //关于action
    QAction *aboutQtAction; //关于Qt动作
    QAction *aboutAuthorAction; //关于作者动作

    Graphics_view_zoom *myView;     //自定义视图，用于鼠标缩放
    QGraphicsScene *scene;          //场景
    SubwayGraph* subwayGraph;       //后端管理类


    //换乘查询指针
    TransferInquiryForm *transfer;
    //查看所有线路图指针
    SubwayMapView *subwaymap;
    //添加站点指针
    addStationDialog *addStation;
    //添加线路指针
    addlinesDialog *addLineto;
    //帮助指针
    AppHelpDialog *apphelp;
    //景点查询指针
    AttractionInquiryDialog *attractDialog;


    Graphics_view_zoom *transferView;     //自定义视图，用于鼠标缩放，换乘界面的
    QGraphicsScene *transferscene;          //场景，换乘界面场景



};

#define LINE_INFO_WIDTH 0   //预留边框用于信息展示
#define MARGIN 30           //视图左边距
#define NET_WIDTH 2000      //网络图最大宽度
#define NET_HEIGHT 2000     //网络图最大高度
#define SCENE_WIDTH (LINE_INFO_WIDTH+MARGIN*2+NET_WIDTH)    //视图宽度
#define SCENE_HEIGHT (MARGIN*2+NET_HEIGHT)                  //视图高度

#define EDGE_PEN_WIDTH 2    //线路边宽
#define NODE_HALF_WIDTH 3   //节点大小


#endif // MAINWINDOW_H
