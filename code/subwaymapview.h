#ifndef SUBWAYMAPVIEW_H
#define SUBWAYMAPVIEW_H

#include <QMainWindow>

namespace Ui {
class SubwayMapView;
}

class SubwayMapView : public QMainWindow
{
    Q_OBJECT

public:
    explicit SubwayMapView(QWidget *parent = nullptr);
    ~SubwayMapView();

private:
    Ui::SubwayMapView *ui;
};

#endif // SUBWAYMAPVIEW_H
