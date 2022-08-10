#ifndef STATION_H
#define STATION_H

#include <QString>
#include <QPointF>
#include <QSet>

class SubwayGraph;
class QTextStream;

//地铁站点类定义
class Station
{
protected:
    int id;                     //站点ID
    QString name;               //站点名称
    double longitude, latitude; //站点经纬度
    QSet<int> linesInfo;        //站点所属线路   QSet类是一个模板类，他是一个哈希表集合。
                                //QSet<T>是Qt的一个普通容器类。QSet存储的值是不指明顺序的，QSet对这些值提供了快速检索的功能。他和QHash很像
    QHash<QString,double> attraction; //第一个存储景点的名称，第二个对应站点与景点的距离
    //所有站点的边界位置
    static double minLongitude, minLatitude, maxLongitude, maxLatitude;

public:
    //构造函数
    Station();
    Station(QString nameStr, double longi, double lati, QList<int> linesList,QHash<QString,double> att);

protected:
    //求取站点间实地直线距离
    int distance(Station other);

    //声明友元
    friend class SubwayGraph;
    friend class QTextStream;
};

#endif // STATION_H
