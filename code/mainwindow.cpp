#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addstationdialog.h"
#include "ui_addstationdialog.h" //这个很重要,ui也自带一个头文件！！！！
#include "ui_transferinquiryform.h"
#include "ui_addlinesdialog.h"
#include "ui_attractioninquirydialog.h"//景点查询ui文件

#include <QGraphicsItem>
#include <QMessageBox>
#include <QColorDialog>
#include <QTimer>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(1000,700);
    setWindowTitle("长沙地铁换乘系统");
    setWindowIcon(QIcon(":/Images/Images/mainwindowIcon.png"));

    myView = new Graphics_view_zoom(ui->graphicsView);
    myView->set_modifiers(Qt::NoModifier);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing); //painter->setRenderHints(QPainter::SmoothPixmapTransform);//消锯齿



    scene=new QGraphicsScene;
    scene->setSceneRect(-LINE_INFO_WIDTH,0,SCENE_WIDTH,SCENE_HEIGHT);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);//ScrollHandDrag(光标变为指向手，然后拖动鼠标将滚动滚动条，此模式在交互和非交互模式下均有效)

    subwayGraph=new SubwayGraph;
    addStation=new addStationDialog(this);
    transfer=new TransferInquiryForm;
    addLineto=new addlinesDialog(this);
    apphelp=new AppHelpDialog(this);
    attractDialog=new AttractionInquiryDialog(this); //景点查询

    transferView= new Graphics_view_zoom(transfer->ui->graphicsView);
    transferView->set_modifiers(Qt::NoModifier);
    transfer->ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    transferscene=new QGraphicsScene;
    transferscene->setSceneRect(-LINE_INFO_WIDTH,0,SCENE_WIDTH,SCENE_HEIGHT);
    transfer->ui->graphicsView->setScene(transferscene);
    transfer->ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

    bool flag = subwayGraph->readFileData(":/data/data/LineCS.txt");
    if (!flag)
    {
        QMessageBox box;
        box.setWindowTitle(tr("error information"));
        box.setIcon(QMessageBox::Warning);
        box.setText("读取数据错误!\n将无法展示内置线路！");
        box.addButton(tr("确定"), QMessageBox::AcceptRole);
        if (box.exec() == QMessageBox::Accepted)
        {
            box.close();
        }
    }
   ui->mainToolBar->hide();  //隐藏主工具栏
   createAds();
   createActions();
   createMenus();
   createToolBars();

   anyconnect();

   on_actionLineMap_triggered();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createAds(){
    QString StrWidth,StrHeigth;
    QString filename="Images/adImages";
    QImage* img=new QImage,* scaledimg=new QImage;//分别保存原图和缩放之后的图片
    if(! ( img->load(filename) ) ) //加载图像
    {
     QMessageBox::information(this, tr("打开图像失败"),tr("打开图像失败!"));
     delete img;
     return;
    }
    int Owidth=img->width(),Oheight=img->height();
    int Fwidth,Fheight;       //缩放后的图片大小
    ui->adLabel->setGeometry(0,0,400,300);
    int Mul;            //记录图片与label大小的比例，用于缩放图片
    if(Owidth/400>=Oheight/300)
       Mul=Owidth/400;
    else
       Mul=Oheight/300;
    Fwidth=Owidth/Mul;
    Fheight=Oheight/Mul;
    *scaledimg=img->scaled(Fwidth,Fheight,Qt::KeepAspectRatio);
    ui->adLabel->setPixmap(QPixmap::fromImage(*scaledimg));
}

void MainWindow::createActions(){
    //主要设置每个action的 图标，名称，快捷键，状态栏
    //设置动作的图标，名称和父窗口,而且必须是这个顺序，先图标，再名称，再父窗口
    exitAction = new QAction(QIcon("Images/exitIcon.png"),"退出",this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("退出程序"));


    //功能action
    transferInquiryAction = new QAction(QIcon(":/Images/Images/transferInquiryIcon-modified"),tr("换乘线路查询"),this);
    addCircuitAction = new QAction(QIcon(":/Images/Images/lineIcon-modified"),tr("添加线路"),this);
    addStationAction = new QAction(QIcon(":/Images/Images/stationIcon-modified"),tr("添加站点"),this);
    transferInquiryAction->setShortcut(tr("ctrl+t"));
    addCircuitAction->setShortcut(tr("ctrl+y"));
    addStationAction->setShortcut(tr("ctrl+u"));
    transferInquiryAction->setStatusTip(tr("查询换乘线路"));
    addCircuitAction->setStatusTip(tr("添加线路"));
    addStationAction->setStatusTip(tr("添加站点"));

    //地铁线路action
    subwayMapViewAction = new QAction(QIcon(":/Images/Images/subwayMapViewIcon-modified"),tr("查看长沙地铁线路图"),this);
    subwayMapViewAction->setShortcut(tr("ctrl+m"));
    subwayMapViewAction->setStatusTip(tr("查看长沙地铁线路图"));

    //景点查询
    attractionInquiryAction = new QAction(QIcon(":/Images/Images/attractionInquiryIcon-modified"),tr("站点景点查询"),this);
    attractionInquiryAction->setShortcut(tr("ctrl+g"));
    attractionInquiryAction->setStatusTip(tr("站点景点查询"));
    //视图action
    zoomInAction = new QAction(QIcon(":/Images/Images/zoomInIcon-modified"),tr("放大"),this);
    zoomOutAction = new QAction(QIcon(":/Images/Images/zoomOutIcon-modified"),tr("缩小"),this);
    restoreDefaultSizeAction = new QAction(QIcon(":/Images/Images/restoreDefaultSizeIcon-modified"),tr("恢复默认大小"),this);
    zoomInAction->setShortcut(tr("ctrl+i"));
    zoomOutAction->setShortcut(tr("ctrl+o"));
    restoreDefaultSizeAction->setShortcut(tr("ctrl+p"));
    zoomInAction->setStatusTip(tr("放大地图"));
    zoomOutAction->setStatusTip(tr("缩小地图"));
    restoreDefaultSizeAction->setStatusTip(tr("恢复默认大小"));

    //查看action
    isShowToolBarAction = new QAction(tr("显示工具栏"),this);
    isShowStatusTipAction = new QAction(tr("显示状态栏"),this);

    isShowToolBarAction->setCheckable(true);  //设置是否可以选中
    isShowStatusTipAction->setCheckable(true);
    isShowToolBarAction->setChecked(true);  //设置为默认选中状态
    isShowStatusTipAction->setChecked(true);

    isShowToolBarAction->setStatusTip(tr("显示工具栏"));
    isShowStatusTipAction->setStatusTip(tr("显示状态栏"));

    //帮助action
    appHelpAction = new QAction(QIcon(":/Images/Images/appHelpIcon-modified"),tr("帮助"),this);
    appHelpAction->setStatusTip(tr("查看帮助"));

    //关于
    aboutQtAction = new QAction(QIcon(":/Images/Images/QtIcon"),tr("关于QT"),this);
    aboutAuthorAction = new QAction(QIcon(":/Images/Images/mainwindowIcon"),tr("关于作者"),this);
    aboutQtAction->setStatusTip(tr("关于Qt"));
    aboutAuthorAction->setStatusTip(tr("关于作者"));
}

void MainWindow::createMenus(){
    //创建菜单
    //设置菜单
    setUpMenu = menuBar()->addMenu(tr("设置(&F)")); //顺便设置快捷键 alt+F
    setUpMenu->addAction(exitAction);

    //功能菜单
    functionMenu = menuBar()->addMenu(tr("功能(&T)"));
    functionMenu->addAction(transferInquiryAction); //添加换乘查询动作
    functionMenu->addAction(addCircuitAction);
    functionMenu->addAction(addStationAction);

    subwayMapMenu = menuBar()->addMenu(tr("地铁线路图(&M)"));
    subwayMapMenu->addAction(subwayMapViewAction);

    attractionInquiryMenu = menuBar()->addMenu(tr("景点查询(&G)"));
    attractionInquiryMenu->addAction(attractionInquiryAction);

    viewMenu = menuBar()->addMenu(tr("视图(&V)"));
    viewMenu->addAction(zoomInAction);
    viewMenu->addAction(zoomOutAction);
    viewMenu->addAction(restoreDefaultSizeAction); //恢复默认视图



    observeMenu = menuBar()->addMenu(tr("查看(&O)"));
    observeMenu->addAction(isShowToolBarAction);
    observeMenu->addAction(isShowStatusTipAction);

    appHelpMenu = menuBar()->addMenu(tr("帮助(&H)"));
    appHelpMenu->addAction(appHelpAction);

    aboutMenu = menuBar()->addMenu(tr("关于(&B)"));
    aboutMenu->addAction(aboutQtAction);
    aboutMenu->addAction(aboutAuthorAction); //添加关于作者动作



}

void MainWindow::createToolBars(){
    //直接调用ADDTOOLBAR()函数即可获得主窗口的工具条对象。每新增一个工具条调用一次addtoolbar函数，传参是工具条名称
    //放缩工具条
    zoomTool = addToolBar("放缩");
    zoomTool->addAction(zoomInAction);
    zoomTool->addAction(zoomOutAction);
    zoomTool->addAction(restoreDefaultSizeAction);

    //功能工具条
    functionTool = addToolBar("功能");
    functionTool->addAction(transferInquiryAction);
    functionTool->addAction(addCircuitAction);
    functionTool->addAction(addStationAction);

    //景点查询工具条
    attractionInquiryTool = addToolBar("景点查询");
    attractionInquiryTool->addAction(attractionInquiryAction);
}

void MainWindow::anyconnect(){
    //退出
    connect(exitAction,&QAction::triggered,this,&MainWindow::close);
    //显示状态栏和工作栏
    connect(isShowToolBarAction,&QAction::triggered,this,&MainWindow::on_isShowToolBarAction_triggered);
    connect(isShowStatusTipAction,&QAction::triggered,this,&MainWindow::on_isShowStatusTipAction_triggered);
    //关于
    connect(aboutQtAction,&QAction::triggered,this,&MainWindow::on_aboutQtAction_triggered);
    connect(aboutAuthorAction,&QAction::triggered,this,&MainWindow::on_aboutAuthorAction_triggered);
    //地图大小缩放
    connect(zoomInAction,&QAction::triggered,this,&MainWindow::on_zoomInAction_triggered);
    connect(zoomOutAction,&QAction::triggered,this,&MainWindow::on_zoomOutAction_triggered);
    connect(restoreDefaultSizeAction,&QAction::triggered,this,&MainWindow::on_restoreDefaultSizeAction_triggered);
    //换乘查询
    connect(transferInquiryAction,&QAction::triggered,this,&MainWindow::on_transferInquiryAction_triggered);
    connect(ui->transferInquiryBtn,&QPushButton::clicked,this,&MainWindow::on_transferInquiryAction_triggered);
    //点击换乘查询界面的按钮调用这个槽函数
    connect(transfer->ui->inquirypushButton,&QPushButton::clicked,this,&MainWindow::on_inquirypushButton_clicked);
    //查看所有线路图
    connect(subwayMapViewAction,&QAction::triggered,this,&MainWindow::on_subwayMapViewAction_triggered);
    //重置线路图
    connect(transfer->ui->restorepushButton,&QPushButton::clicked,this,&MainWindow::restore);
    //添加站点
    connect(addStationAction,&QAction::triggered,this,&MainWindow::on_addStationAction_triggered);
    connect(ui->addStationsBtn,&QPushButton::clicked,this,&MainWindow::on_addStationAction_triggered);
    //添加线路
    connect(addCircuitAction,&QAction::triggered,this,&MainWindow::on_addCircuitAction_triggered);
    connect(ui->addCircuitBtn,&QPushButton::clicked,this,&MainWindow::on_addCircuitAction_triggered);
    //添加站点功能槽函数
    connect(addStation->ui->addpushButton,&QPushButton::clicked,this,&MainWindow::addStations);
    //添加线路功能槽函数
    connect(addLineto->ui->addpushButton,&QPushButton::clicked,this,&MainWindow::addlines);
    //连接线路功能函数
    connect(addLineto->ui->pushButtonconnect,&QPushButton::clicked,this,&MainWindow::connectlines);
    //查看帮助槽函数
    connect(appHelpAction,&QAction::triggered,this,&MainWindow::on_appHelpAction_triggered);

    //连接景点查询槽函数
    connect(attractionInquiryAction,&QAction::triggered,this,&MainWindow::on_attractionInquiryAction_triggered);
    //景点查询功能函数
    connect(attractDialog->ui->attpushButton,&QPushButton::clicked,this,&MainWindow::attractionInquiry);

}

//设置isShowToolBarAction和isShowStatusAction选中状态发生变化槽函数
void MainWindow::on_isShowToolBarAction_triggered(bool checked){
    if (checked){
        zoomTool->show();  //隐藏所有工具栏,maintoolbar和zoomtool都是toolbar类型的
        functionTool->show();
        attractionInquiryTool->show();
    }else{
        zoomTool->hide();
        functionTool->hide();
        attractionInquiryTool->hide();
    }
}
void MainWindow::on_isShowStatusTipAction_triggered(bool checked){
    if (checked){
        ui->statusBar->show();

    }else{
        ui->statusBar->hide();
    }
}

//关于Qt槽函数
void MainWindow::on_aboutQtAction_triggered(){
    QMessageBox::aboutQt(this,tr("关于Qt"));
}
//关于作者槽函数
void MainWindow::on_aboutAuthorAction_triggered(){
    /*QMessageBox::about(this,tr("关于作者"),
                  tr("author:cds007\r\n"
                     "school:csu\r\n"
                     "email:2205175277@qq.com\r\n"));*/
    QMessageBox about(this);
    about.setIconPixmap(QPixmap(":/Images/Images/authorIcon-modified"));
    about.setText(tr("author:cds007\r\n"
                     "school:csu\r\n"
                     "email:2205175277@qq.com\r\n"));
    about.setWindowTitle(tr("关于作者"));
    about.exec();
}

//视图放大槽函数
void MainWindow::on_zoomInAction_triggered(){
    ui->graphicsView->scale(1.5,1.5);
    ui->statusBar->showMessage(tr("已放大"),2000);  //显示临时信息，2s后关闭
}
//视图缩小槽函数
void MainWindow::on_zoomOutAction_triggered(){
    ui->graphicsView->scale(0.75,0.75);
    ui->statusBar->showMessage(tr("已缩小"),2000);  //显示临时信息，2s后关闭
}
//恢复默认大小
void MainWindow::on_restoreDefaultSizeAction_triggered(){
    QGraphicsView *myview = ui->graphicsView;
    myview->setTransformationAnchor(QGraphicsView::AnchorViewCenter);
        QMatrix q;
        q.setMatrix(1,myview->matrix().m12(),myview->matrix().m21(),1,myview->matrix().dx(),myview->matrix().dy());
        myview->setMatrix(q,false);
}

//换乘查询槽函数，打开换乘界面
void MainWindow::on_transferInquiryAction_triggered(){
    transfer->show();
}
void MainWindow::attractionInquiry(){
     int s1=subwayGraph->getStationHash(attractDialog->ui->lineEdit->text());
     if (s1 == -1){
         //没有这个站点
         QMessageBox box;
         box.setWindowTitle(tr("景点查询"));
         box.setWindowIcon(QIcon(":/Images/Images/attractionInquiryIcon-modified"));
         box.setIcon(QMessageBox::Warning);
         box.setText(tr("请选择正确的站点"));
         box.addButton(tr("确定"),QMessageBox::AcceptRole);
         if (box.exec()==QMessageBox::Accepted){
             box.close();
         }
     }else{
         QList<int> stationsList;
         QList<Edge> edgesList;
         QString name = attractDialog->ui->lineEdit->text(); //获取站点名
         QList<QString> list = subwayGraph->getattractName(s1); //获取景点名表
         QList<double> list2  = subwayGraph->getattractDis(s1);
         QString text = "查询到附近的景点有：\n";
         for (int i = 0; i < list.size(); ++i) {
             text+="距离 "+list[i]+" "+QString::number(list2[i],'f',2)+"km\n\n";
         }
         QTextBrowser* browser=attractDialog->ui->textBrowser;
         browser->setText(text);
     }
}
//换乘查询 功能函数
void MainWindow::on_inquirypushButton_clicked(){
    int s1=subwayGraph->getStationHash(transfer->ui->SPlineEdit->text());
    int s2=subwayGraph->getStationHash(transfer->ui->FPlineEdit->text());
    int way=transfer->ui->timeradioButton->isChecked()?1:2;

    if(s1==-1||s2==-1)
    {   //没有这个站点
        QMessageBox box;
        box.setWindowTitle(tr("换乘查询"));
        box.setWindowIcon(QIcon(":/Images/Images/transferInquiryIcon-modified"));
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("请选择有站点的线路"));
        box.addButton(tr("确定"),QMessageBox::AcceptRole);
        if(box.exec()==QMessageBox::Accepted)
        {
            box.close();
        }
    }
    else
    {
        QList<int> stationsList;
        QList<Edge> edgesList;
        bool flag=true;
        if(way==1)  //最短时间
        {
            flag=subwayGraph->queryTransferMinTime(s1, s2, stationsList, edgesList);  //返回了站点的列表和边的列表给stationlist和edgelist
        }
        else
        {
            flag=subwayGraph->queryTransferMinTransfer(s1, s2, stationsList, edgesList);
        }

        if(flag)
        {

            transferscene->clear();
            drawEdges2(edgesList);
            drawStations2(stationsList);
            QString text=way==1?("以下线路时间最短，共换乘"+QString::number(stationsList.size()-1)+"个站点\n\n"):
                                ("以下线路换乘最少，共换乘"+QString::number(stationsList.size()-1)+"条线路\n\n");
            for(int i=0; i<stationsList.size(); ++i)
            {
                if(i)
                {
                    text+="\n  ↓\n";
                }
                text+=subwayGraph->getStationName(stationsList[i]);
                QString linesStr=getLinesName(subwayGraph->getStationLinesInfo(stationsList[i]));
                text+=linesStr;
            }
            QTextBrowser* browser=transfer->ui->textBrowserRoute;
            browser->clear();
            browser->setText(text);
        }
        else
        {   //没有线路
            QMessageBox box;
            box.setWindowTitle(tr("换乘查询"));
            box.setWindowIcon(QIcon(":/Images/Images/transferInquiryIcon-modified"));
            box.setIcon(QMessageBox::Warning);
            box.setText(tr("您选择的起始和终止站点暂时无法到达！"));
            box.addButton(tr("确定"),QMessageBox::AcceptRole);
            if(box.exec()==QMessageBox::Accepted)
            {
                box.close();
            }
        }
    }
}
//换乘查询，重置函数
void MainWindow::restore(){
    on_actionLineMap_triggered();
}

//查看景点查询界面槽函数
void MainWindow::on_attractionInquiryAction_triggered(){
    attractDialog->show();
}


//添加站点槽函数，打开添加站点界面
void MainWindow::on_addStationAction_triggered(){
    addStation->linesNameList=subwayGraph->getLinesNameList();
    addStation->updateLinesListWidget();
    addStation->show();
}
//打开站点动作
void MainWindow::addStations(){
    QMessageBox box;
    box.setWindowTitle(tr("添加站点"));
    box.setWindowIcon(QIcon(":/Images/Images/stationIcon-modified"));

    if(addStation->stationName.isEmpty())
    {
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("请输入站点名称！"));
    }
    else if(addStation->linesSelected.isEmpty())
    {
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("请选择站点所属线路！"));
    }
    else
    {
        if(subwayGraph->getStationHash(addStation->stationName)!=-1)
        {
            box.setIcon(QMessageBox::Critical);
            box.setText(tr("添加失败！\n错误原因：站点已存在！"));
        }
        else
        {
            QHash<QString,double> qsh;
            qsh.insert("暂未录入景点",-1);
            Station s(addStation->stationName, addStation->longitude, addStation->latitude,
                      subwayGraph->getLinesHash(addStation->linesSelected),qsh); //这里也要改别忘了
            subwayGraph->addStation(s);
            box.setText(tr("站点：")+addStation->stationName+tr(" 添加成功！"));
        }
    }

    box.addButton(tr("确定"),QMessageBox::AcceptRole);
    if(box.exec()==QMessageBox::Accepted)
    {
        box.close();
    }
    on_actionLineMap_triggered();
}

//添加线路槽函数，打开添加线路界面
void MainWindow::on_addCircuitAction_triggered(){
    updateComboBox();
    addLineto->show();
}
//添加线路功能函数
void MainWindow::addlines(){
    QMessageBox box;
    box.setWindowTitle(tr("添加线路"));
    box.setWindowIcon(QIcon(":/Images/Images/lineIcon-modified"));

    if(addLineto->lineName.isEmpty())
    {
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("请输入线路名称！"));
    }
    else if(subwayGraph->getLineHash(addLineto->lineName)==-1)
    {
        box.setIcon(QMessageBox::Information);
        box.setText(tr("线路：")+addLineto->lineName+tr(" 添加成功！"));
        subwayGraph->addLine(addLineto->lineName, addLineto->lineColor);
    }
    else
    {
        box.setIcon(QMessageBox::Critical);
        box.setText(tr("添加失败！\n错误原因：线路名已存在！"));
    }

    box.addButton(tr("确定"),QMessageBox::AcceptRole);
    if(box.exec()==QMessageBox::Accepted)
    {
        box.close();
    }
}

//查看帮助槽函数
void MainWindow::on_appHelpAction_triggered(){
    apphelp->show();
}

//连接线路功能函数
void MainWindow::connectlines(){
    QString station1=addLineto->ui->comboBoxstation1->currentText();
    QString station2=addLineto->ui->comboBoxstation2->currentText();
    int s1=subwayGraph->getStationHash(station1);
    int s2=subwayGraph->getStationHash(station2);
    int l=subwayGraph->getLineHash(addLineto->ui->comboBoxline->currentText());

    QMessageBox box;
    box.setWindowTitle(tr("添加连接"));
    box.setWindowIcon(QIcon(":/Images/Images/lineIcon-modified"));

    if(s1==-1||s2==-1||l==-1)
    {
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("请选择已有的站点和线路！"));
    }
    else if(s1==s2)
    {
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("同一站点不需要连接！"));
    }
    else if(!subwayGraph->getStationLinesInfo(s1).contains(l))
    {
        box.setIcon(QMessageBox::Critical);
        box.setText(tr("连接失败！\n错误原因：所属线路不包含站点1"));
    }
    else if(!subwayGraph->getStationLinesInfo(s2).contains(l))
    {
        box.setIcon(QMessageBox::Critical);
        box.setText(tr("连接失败！\n错误原因：所属线路不包含站点2"));
    }
    else
    {
        box.setIcon(QMessageBox::Information);
        box.setText(tr("添加连接成功！"));
        subwayGraph->addConnection(s1,s2,l);
    }
    if(box.exec()==QMessageBox::Accepted)
    {
        box.close();
    }
    on_actionLineMap_triggered();
}


//打开线路图界面
void MainWindow::on_subwayMapViewAction_triggered(){
    subwaymap = new SubwayMapView;
    subwaymap->show();
}

//更新选择部件
void MainWindow::updateComboBox(){
    addLineto->ui->comboBoxline->clear();
    addLineto->ui->comboBoxstation1->clear();
    addLineto->ui->comboBoxstation2->clear();
/*for(auto a:b)中b为一个容器，效果是利用a遍历并获得b容器中的每一个值，但是a无法影响到b容器中的元素。
  for(auto &a:b)中加了引用符号，可以对容器中的内容进行赋值，即可通过对a赋值来做到容器b的内容填充。*/
    QList<QString> stationsNameList;
    QList<QString> linesNameList;
    stationsNameList=subwayGraph->getStationsNameList();
    linesNameList=subwayGraph->getLinesNameList();
    for (auto &a: stationsNameList)
    {
         addLineto->ui->comboBoxstation1->addItem(a);
         addLineto->ui->comboBoxstation2->addItem(a);
    }
    for (auto &a: linesNameList)
    {
         addLineto->ui->comboBoxline->addItem(a);
    }
}


QColor MainWindow::getLinesColor(const QList<int>& linesList)
{
    QColor color1=QColor(255,255,255);
    QColor color2;
    for (int i=0; i<linesList.size(); ++i)
    {
        color2=subwayGraph->getLineColor(linesList[i]);
        color1.setRed(color1.red()*color2.red()/255);
        color1.setGreen(color1.green()*color2.green()/255);
        color1.setBlue(color1.blue()*color2.blue()/255);
    }
    return color1;
}

//获得线路表的名字集
QString MainWindow::getLinesName(const QList<int>& linesList)
{
    QString str;
    str+="\t";
    for (int i=0; i<linesList.size(); ++i)
    {
        str+=" ";
        str+=subwayGraph->getLineName(linesList[i]);
    }
//    qDebug()<<"tip="<<str<<"\n";
    return str;
}

//将站点的经纬度地理坐标转为视图坐标
QPointF MainWindow::transferCoord(QPointF coord)
{
    QPointF minCoord=subwayGraph->getMinCoord();
    QPointF maxCoord=subwayGraph->getMaxCoord();
    double x = (coord.x()-minCoord.x())/(maxCoord.x()-minCoord.x())*NET_WIDTH+MARGIN;
    double y = (maxCoord.y()-coord.y())/(maxCoord.y()-minCoord.y())*NET_HEIGHT+MARGIN;
    return QPointF(x,y);
}

void MainWindow::drawEdges(const QList<Edge>& edgesList)
{
    for(int i=0; i<edgesList.size(); ++i)
    {
        int s1=edgesList[i].first;
        int s2=edgesList[i].second;

        QList<int> linesList=subwayGraph->getCommonLines(s1, s2); //获取两个站点的公共所属线路
        QColor color=getLinesColor(linesList);
        QString tip="途经： "+subwayGraph->getStationName(s1)+"--"+subwayGraph->getStationName(s2)+"\n线路：";
        tip+=getLinesName(linesList);
        QPointF s1Pos=transferCoord(subwayGraph->getStationCoord(s1));    //getStationCoord获取站点地理坐标
        QPointF s2Pos=transferCoord(subwayGraph->getStationCoord(s2));

        QGraphicsLineItem* edgeItem=new QGraphicsLineItem;    //线图元
        edgeItem->setPen(QPen(color, EDGE_PEN_WIDTH));   //设置线图元的颜色，长度
        edgeItem->setCursor(Qt::PointingHandCursor);
        edgeItem->setToolTip(tip);    //tip是把鼠标悬停在线上面时显示的信息
        edgeItem->setPos(s1Pos);
        edgeItem->setLine(0, 0, s2Pos.x()-s1Pos.x(), s2Pos.y()-s1Pos.y());  //设置直线的两个点，就是方向
        scene->addItem(edgeItem);
    }
}

//记录我那个经度0度，纬度0度的bug，这是个逻辑错误，因为我的坐标系按照最小经纬度和最大经纬度建立，最小的全部给我整成0度的话，那其他的坐标会挤在一块。
void MainWindow::drawEdges2(const QList<Edge>& edgesList)
{
    for(int i=0; i<edgesList.size(); ++i)
    {
        int s1=edgesList[i].first;
        int s2=edgesList[i].second;

        QList<int> linesList=subwayGraph->getCommonLines(s1, s2); //获取两个站点的公共所属线路
        QColor color=getLinesColor(linesList);
        QString tip="途经： "+subwayGraph->getStationName(s1)+"--"+subwayGraph->getStationName(s2)+"\n线路：";
        tip+=getLinesName(linesList);
        QPointF s1Pos=transferCoord(subwayGraph->getStationCoord(s1));    //getStationCoord获取站点地理坐标
        QPointF s2Pos=transferCoord(subwayGraph->getStationCoord(s2));

        QGraphicsLineItem* edgeItem=new QGraphicsLineItem;    //线图元
        edgeItem->setPen(QPen(color, EDGE_PEN_WIDTH));   //设置线图元的颜色，长度
        edgeItem->setCursor(Qt::PointingHandCursor);
        edgeItem->setToolTip(tip);    //tip是把鼠标悬停在线上面时显示的信息
        edgeItem->setPos(s1Pos);
        edgeItem->setLine(0, 0, s2Pos.x()-s1Pos.x(), s2Pos.y()-s1Pos.y());  //设置直线的两个点，就是方向

        transferscene->addItem(edgeItem);
    }
}
void MainWindow::drawStations2 (const QList<int>& stationsList)
{
    for (int i=0; i<stationsList.size(); ++i)
    {
        int s=stationsList[i];
        QString name=subwayGraph->getStationName(s);    //传入的是stations的下标
        QList<int> linesList=subwayGraph->getStationLinesInfo(s);
        QColor color=getLinesColor(linesList);
        QPointF longiLati=subwayGraph->getStationCoord(s);
        QPointF coord=transferCoord(longiLati);    //转成场景里的坐标点
        QString tip="站名：  "+name+"\n"+
                "经度：  "+QString::number(longiLati.x(),'f',7)+"\n"+
                "纬度：  "+QString::number(longiLati.y(),'f',7)+"\n"+
                "线路："+getLinesName(linesList);
        //tip是把鼠标悬停在点上面时显示的信息
        QGraphicsEllipseItem* stationItem=new QGraphicsEllipseItem;
        stationItem->setRect(-NODE_HALF_WIDTH, -NODE_HALF_WIDTH, NODE_HALF_WIDTH<<1, NODE_HALF_WIDTH<<1);
        stationItem->setPos(coord);
        stationItem->setPen(color);
        stationItem->setCursor(Qt::PointingHandCursor);
        stationItem->setToolTip(tip);

        if(linesList.size()<=1)  //所属的线路小于等于1，即不是换乘站
        {
            stationItem->setBrush(QColor(QRgb(0xffffff)));
        }


        transferscene->addItem(stationItem);

        QGraphicsTextItem* textItem=new QGraphicsTextItem;
        textItem->setPlainText(name);   //站名
        textItem->setFont(QFont("consolas",4,1));
        textItem->setPos(coord.x(),coord.y()-NODE_HALF_WIDTH*2);

        transferscene->addItem(textItem);
    }
}



void MainWindow::drawStations (const QList<int>& stationsList)
{
    for (int i=0; i<stationsList.size(); ++i)
    {
        int s=stationsList[i];
        QString name=subwayGraph->getStationName(s);    //传入的是stations的下标
        QList<int> linesList=subwayGraph->getStationLinesInfo(s);
        QColor color=getLinesColor(linesList);
        QPointF longiLati=subwayGraph->getStationCoord(s);
        QPointF coord=transferCoord(longiLati);    //转成场景里的坐标点
        QString tip="站名：  "+name+"\n"+
                "经度：  "+QString::number(longiLati.x(),'f',7)+"\n"+
                "纬度：  "+QString::number(longiLati.y(),'f',7)+"\n"+
                "线路："+getLinesName(linesList);
        //tip是把鼠标悬停在点上面时显示的信息
        QGraphicsEllipseItem* stationItem=new QGraphicsEllipseItem;
        stationItem->setRect(-NODE_HALF_WIDTH, -NODE_HALF_WIDTH, NODE_HALF_WIDTH<<1, NODE_HALF_WIDTH<<1);
        stationItem->setPos(coord);
        stationItem->setPen(color);
        stationItem->setCursor(Qt::PointingHandCursor);
        stationItem->setToolTip(tip);

        if(linesList.size()<=1)  //所属的线路小于等于1，即不是换乘站
        {
            stationItem->setBrush(QColor(QRgb(0xffffff)));
        }

        scene->addItem(stationItem);


        QGraphicsTextItem* textItem=new QGraphicsTextItem;
        textItem->setPlainText(name);   //站名
        textItem->setFont(QFont("consolas",4,1));
        textItem->setPos(coord.x(),coord.y()-NODE_HALF_WIDTH*2);
        scene->addItem(textItem);

    }
}



//动作查看所有线路图槽函数
void MainWindow::on_actionLineMap_triggered()
{
    scene->clear();
    transferscene->clear();
    QList<int> stationsList;
    QList<Edge> edgesList;
    subwayGraph->getGraph(stationsList,edgesList);
    drawEdges(edgesList);
    drawStations(stationsList);
   drawEdges2(edgesList);
    drawStations2(stationsList);
   qDebug()<<"stations.size()="<<stationsList.size()<<" edges.size()="<<edgesList.size();
}










