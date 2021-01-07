#ifndef DIAGRAMITEMS_H
#define DIAGRAMITEMS_H
#include <QGraphicsLineItem>
#include <QPen>
#include <QPainter>
#include <cmath>

using namespace std;

class DiagramItems : public QGraphicsLineItem
{
public:
    DiagramItems(QLineF line, QGraphicsItem* parent = 0);
    QRectF boundingRect() const;
    QPainterPath shape() const;

    void paint (QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) ;


private:
    const qreal selectionOffSet;
    QPolygonF selectionPolygon;
    void createSelectionPolygon();
};

#endif // DIAGRAMITEMS_H
