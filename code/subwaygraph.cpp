#include "subwaygraph.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <queue>
#include<QTextCodec>
//构造函数
SubwayGraph::SubwayGraph()
{
}

//从文件读取数据
bool SubwayGraph::readFileData(QString fileName)
{

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly))
        return false;
    QTextStream in(&file);
    while(!in.atEnd())
    {
        Line line; //线路类
        QString id, name, colour, fromTo, totalStations; //站点类属性
        QString color, froms, tos; //线路类属性
        bool ok;
        int total;
        Station station;
        int lvIndex, svIndex1, svIndex2;

        QByteArray line1 = file.readLine(); //将读取到的行数据转换为Unicode,line1存储第一次行原始数据
        QString str = codec->toUnicode(line1).trimmed();//str存储第二次行原始数据转码数据
        str.replace(QRegExp("[\\s]+"), " ");//去除多余的空格
        QStringList strList1 = str.split(" ");//以空格划分数组
        id=strList1[0];
        line.id=strList1[1].toInt();   //读线路id
        //读线路名
        line1 = file.readLine();
        str = codec->toUnicode(line1).trimmed();
        strList1 = str.split(" ");
        name=strList1[0];
        line.name=strList1[1];
        //读线路颜色
        line1 = file.readLine();
         str = codec->toUnicode(line1).trimmed();
        strList1 = str.split(" ");
        colour=strList1[0];
        color=strList1[1];
        //读取线路起始站点
        line1 = file.readLine();
         str = codec->toUnicode(line1).trimmed();
        strList1 = str.split(" ");
        fromTo = strList1[0];
        froms = strList1[1];
        tos = strList1[2];
        //读取线路总站点数
        line1 = file.readLine();
        str = codec->toUnicode(line1).trimmed();
        strList1 = str.split(" ");
        totalStations = strList1[0];
        total = strList1[1].toInt();




        //in>>id>>line.id;
       // in>>name>>line.name;

        //in>>colour>>color;
        line.color.setRgba(color.remove(0,1).toUInt(&ok, 16)); //设置线路颜色
        //in>>fromTo>>froms>>tos;
        //in>>totalStations>>total;

        //line.fromTo.push_back(froms);
        //line.fromTo.push_back(tos);
        if (linesHash.count(line.name))  //返回与键关联的项数。
        {
            lvIndex = linesHash[line.name];
            lines[lvIndex].fromTo.push_back(froms);
            lines[lvIndex].fromTo.push_back(tos);  //tos是总站点数
        }
        else
        {
            lvIndex = linesHash[line.name] = lines.size();  //给线路哈希表赋值，值是目前总线路数
            lines.push_back(line); //将线路置入线路向量lines中
        }

        QString longlat;
        QStringList strList;
        QString att;
        double attdis;
        for (int i=0; i<total; ++i)
        {
            line1 = file.readLine();
            str = codec->toUnicode(line1).trimmed();
            str.replace(QRegExp("[\\s]+"), " ");
            strList1 = str.split(" "); //同上操作

            station.id=strList1[0].toInt(); //一个局部变量station
            station.name=strList1[1];
            longlat = strList1[2];
            //in>>station.id>>station.name>>longlat;
            strList=longlat.split(QChar(','));
            station.longitude=strList.first().toDouble();
            station.latitude=strList.last().toDouble();

            att = strList1[3];
            attdis = strList1[4].toDouble();
            station.attraction[att]=attdis; //景点哈希表初始化

            att = strList1[5];
            attdis = strList1[6].toDouble();
            station.attraction[att]=attdis; //景点哈希表初始化

            att = strList1[7];
            attdis = strList1[8].toDouble();
            station.attraction[att]=attdis; //景点哈希表初始化 第三个景点





//            qDebug()<<station.longitude<<" "<<station.latitude<<"\n";
//            d1=station.longitude;
//            if(fabs(d1-d2)<1e-8)
//            {
//                qDebug()<<line.name<<" "<<station.id<<" "<<station.name<<"经度数据有误"<<"\n";
//            }
//            d2=d1;

            if (stationsHash.count(station.name))
            {
                svIndex2 = stationsHash[station.name];  //如果站点已经被存过，则直接调用其哈希值
            }
            else
            {
                svIndex2 = stationsHash[station.name] = stations.size(); //站点哈希值就是目前的总站点数
                stations.push_back(station);
            }

            stations[svIndex2].linesInfo.insert(lvIndex); //设置站点的所属线路
            lines[lvIndex].stationsSet.insert(svIndex2);  //设置线路所属站点，因为是集合类，所以不会产生站点重复的情况

            if (i) //i不是0
            {
                lines[lvIndex].edges.insert(Edge(svIndex1, svIndex2)); //1是前一个点，2是后一个点
                lines[lvIndex].edges.insert(Edge(svIndex2, svIndex1)); //插入两个方向的边
                insertEdge(svIndex1, svIndex2); //插入subwaygraph里面的边集合里
            }
            svIndex1 = svIndex2;
        }
        //&& !in.atEnd()
        bool flag = id=="id:" && name=="name:" && colour=="colour:" && fromTo=="fromTo:"
                && totalStations=="totalStations:" && ok ;

//        qDebug()<< "ok="<<ok<<" flag="<<flag<<line.id<< " "<<station.name<< "\n";

        if(flag==false)
        {
            file.close();
            clearData();
            return false ;
        }
        //in.readLine();
    }
    file.close();

    updateMinMaxLongiLati();

    return true;
}

//清空数据
void SubwayGraph::clearData()
{
    stations.clear();
    lines.clear();
    stationsHash.clear();
    linesHash.clear();
    edges.clear();
    graph.clear();
}

//插入一条边  如果边的集合里面已经包含这条边那个返回错误
bool SubwayGraph::insertEdge(int n1, int n2)
{
    if (edges.contains(Edge(n1, n2)) || edges.contains(Edge(n2, n1)))
    {
        return false;
    }
    edges.insert(Edge(n1, n2));
    return true;
}

//生成图结构
void SubwayGraph::makeGraph()
{
    graph.clear();
    graph=QVector<QVector<Node>>(stations.size(), QVector<Node>());//QVector<QVector<float> > data2D(10,QVector<float>(8));//初始化尺寸为10×8的二维向量
    for (auto &a : edges)
    {
        double dist=stations[a.first].distance(stations[a.second]);
        graph[a.first].push_back(Node(a.second, dist));
        graph[a.second].push_back(Node(a.first, dist));
    }
}


//获取线路颜色
QColor SubwayGraph::getLineColor(int l)
{
    return lines[l].color;
}

//获取线路名
QString SubwayGraph::getLineName(int l)
{
    return lines[l].name;
}

//获取线路hash值
int SubwayGraph::getLineHash(QString lineName)
{
    if(linesHash.contains(lineName))
    {
        return linesHash[lineName];
    }
    return -1;
}

//获取线路集合hash值
QList<int> SubwayGraph::getLinesHash(QList<QString> linesList)
{
    QList<int> hashList;
    for (auto &a:linesList)
    {
        hashList.push_back(getLineHash(a));  //获取每条线路的hash值
    }
    return hashList;
}

//获取线路名集合
QList<QString> SubwayGraph::getLinesNameList()
{
    QList<QString> linesNameList;
    for (auto a:lines)
    {
        linesNameList.push_back(a.name);
    }
    return linesNameList;
}

//获取线路的所有包含站点
QList<QString> SubwayGraph::getLineStationsList(int l)
{
    QList<QString> stationsList;
    for (auto &a:lines[l].stationsSet)
    {
        stationsList.push_back(stations[a].name);
    }
    return stationsList;
}



//更新边界经纬度  站点里面最小和最大的经纬度
void SubwayGraph::updateMinMaxLongiLati()
{
    double minLongitude=200, minLatitude=200;
    double maxLongitude=0, maxLatitude=0;

    for (auto &s : stations)
    {
        minLongitude = qMin(minLongitude, s.longitude);
        minLatitude = qMin(minLatitude, s.latitude);
        maxLongitude = qMax(maxLongitude, s.longitude);
        maxLatitude = qMax(maxLatitude, s.latitude);
    }
    Station::minLongitude = minLongitude;
    Station::minLatitude = minLatitude;
    Station::maxLongitude = maxLongitude;
    Station::maxLatitude = maxLatitude;

   qDebug("minLon=%.10lf, minLat=%.10lf\n", minLongitude, minLatitude);
    qDebug("maxLon=%.10lf, maxLat=%.10lf\n", maxLongitude, maxLatitude);
}

 //获取站点最小坐标
QPointF SubwayGraph::getMinCoord()
{
    return QPointF(Station::minLongitude, Station::minLatitude);
}

//获取站点最大坐标
QPointF SubwayGraph::getMaxCoord()
{
    return QPointF(Station::maxLongitude, Station::maxLatitude);
}

//获取两个站点的公共所属线路
QList<int> SubwayGraph::getCommonLines(int s1, int s2)
{
    QList<int> linesList;
    for (auto &s : stations[s1].linesInfo)
    {
        if(stations[s2].linesInfo.contains(s))
            linesList.push_back(s);
    }
    return linesList;
}
//获取景点名表
QList<QString> SubwayGraph::getattractName(int s){
    QList<QString> list;
    QHash<QString,double> qhash = stations[s].attraction;

    QHash<QString,double>::const_iterator it = qhash.constBegin();
    while (it != qhash.constEnd()) {
       list.append(it.key());
       ++it;
    }
    return list;
}
//获取景点距离
QList<double> SubwayGraph::getattractDis(int s){
    QList<double> list;
    QHash<QString,double> qhash = stations[s].attraction;

    QHash<QString,double>::const_iterator it = qhash.constBegin();
    while (it != qhash.constEnd()) {
       list.append(it.value());
       ++it;
    }
    return list;
}
//获取站点名
QString SubwayGraph::getStationName(int s)
{
    return stations[s].name;
}

//获取站点地理坐标
QPointF SubwayGraph::getStationCoord(int s)
{
    return QPointF(stations[s].longitude, stations[s].latitude);
}

//获取站点所属线路信息
QList<int> SubwayGraph::getStationLinesInfo(int s)
{
    return stations[s].linesInfo.toList();
}

//获取站点hash值
int SubwayGraph::getStationHash(QString stationName)
{
    if(stationsHash.contains(stationName))
    {
        return stationsHash[stationName];
    }
    return -1;
}

//获取站点集合hash值
QList<QString> SubwayGraph::getStationsNameList()
{
    QList<QString> list;
    for (auto &a: stations)
    {
        list.push_back(a.name);
    }
    return list;
}



//添加新线路
void SubwayGraph::addLine(QString lineName, QColor color)
{
    linesHash[lineName]=lines.size();   //存放哈希值，哈希值是线路的总条数
    lines.push_back(Line(lineName,color));  //lines集合添加线路
}

//添加新站点
void SubwayGraph::addStation(Station s)
{
    int hash=stations.size();
    stationsHash[s.name]=hash;
    stations.push_back(s);
    for (auto &a: s.linesInfo)
    {
        lines[a].stationsSet.insert(hash);
    }
    updateMinMaxLongiLati();
}

//添加站点连接关系
void SubwayGraph::addConnection(int s1, int s2, int l)
{
    insertEdge(s1,s2);
    lines[l].edges.insert(Edge(s1,s2));
    lines[l].edges.insert(Edge(s2,s1));
}



//获取网络结构，用于前端显示
void SubwayGraph::getGraph(QList<int>&stationsList, QList<Edge>&edgesList)
{
    stationsList.clear();
    for (int i=0; i<stations.size(); ++i)
    {
        stationsList.push_back(i);
    }
    edgesList=edges.toList();
    return ;
}

//获取最少时间的线路
bool SubwayGraph::queryTransferMinTime(int s1, int s2, QList<int>&stationsList, QList<Edge>&edgesList)
{
#define INF 999999999
    stationsList.clear();
    edgesList.clear();

    if(s1==s2)
    {
        stationsList.push_back(s2);
        stationsList.push_back(s1);
        return true;
    }
    makeGraph();

    std::vector<int> path(stations.size(), -1);
    std::vector<double> dist(stations.size(), INF); //设置每个点间的最短距离初始为无穷大
    dist[s1]=0;
    //优先级队列priority_queue
    //T：参数类型
    //Container：容器类型。默认是用vector容器实现，参数类型必须是T
    //Compare：排序规则。默认是小顶堆弹出std::less<T>
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> priQ;
    priQ.push(Node(s1, 0)); //s1到s1的距离是0
    while(!priQ.empty())
    {    //先广度优先再深度优先的迪杰斯特拉算法
        Node top=priQ.top();
        priQ.pop();
        if(top.stationID==s2)
        {
            break ;
        }

        for (int i=0; i<graph[top.stationID].size(); ++i)
        {
            Node &adjNode=graph[top.stationID][i];
            if(top.distance+adjNode.distance<dist[adjNode.stationID])  //如果这两个点间的距离小于目前这个点的最短距离
            {
                path[adjNode.stationID]=top.stationID;
                dist[adjNode.stationID]=top.distance+adjNode.distance;
                priQ.push(Node(adjNode.stationID, dist[adjNode.stationID]));
            }
        }
    }

    if(path[s2]==-1)
    {
        return false;
    }
    int p=s2;
    while(path[p]!=-1)  //从s2向最短路径往前找
    {
        stationsList.push_front(p);
        edgesList.push_front(Edge(path[p],p));
        p=path[p];
    }
    stationsList.push_front(s1);

//    qDebug()<<"s1="<<s1<<" s2="<<s2<<" size= "<<stationsList.size()<<" "<<edgesList.size()<<"\n";
    return true;
}

//获取最少换乘的线路
bool SubwayGraph::queryTransferMinTransfer(int s1, int s2, QList<int>&stationsList, QList<Edge>&edgesList)
{//实际上是先广度优先再深度优先，先把父结点所属路线全访问，再访问子结点所属线路
    stationsList.clear();
    edgesList.clear();

    if(s1==s2)
    {
        stationsList.push_back(s2);
        stationsList.push_back(s1);
        return true;
    }

    std::vector<bool> linesVisted(lines.size(),false);
    std::vector<int> path(stations.size(),-1);
    path[s1]=-2;
    std::queue<int> que;
    que.push(s1);

    while(!que.empty())
    {
        int top=que.front();
        que.pop();
        for (auto &l: stations[top].linesInfo)
        {
            if(!linesVisted[l]) //线路还没有被访问过则访问这条线路
            {
                linesVisted[l]=true;
                for (auto &s: lines[l].stationsSet)  //访问线路里的每一个站点
                {
                    if(path[s]==-1) //等于-1说明站点还没访问过
                    {
                        path[s]=top;
                        que.push(s);
                    }
                }
            }
        }
    }

    if(path[s2]==-1)
    {
        return false;
    }
    int p=s2;
    while(path[p]!=-2)  //往回寻找头结点
    {
        stationsList.push_front(p); //从前往后放入List，而且只会放入换乘点
        edgesList.push_front(Edge(path[p],p)); //边也是先放入上一个结点再放入后一个结点
        p=path[p];
    }
    stationsList.push_front(s1);  //再把s1放入
    return true;
}
