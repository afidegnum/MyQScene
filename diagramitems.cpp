#include "diagramitems.h"

DiagramItems::DiagramItems(QLineF line, QGraphicsItem *parent) : QGraphicsLineItem(line, parent), selectionOffSet(20)
{
    setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
    createSelectionPolygon();
}

void DiagramItems::createSelectionPolygon(){
    QPolygonF nPolygon;
    qreal radAngle = line().angle()* M_PI / 180;
    qreal dx = selectionOffSet * sin(radAngle);
    qreal dy = selectionOffSet * cos(radAngle);
    QPointF offset1 = QPointF(dx, dy);
    QPointF offset2 = QPointF(-dx, -dy);
    nPolygon << line().p1() + offset1
                 << line().p1() + offset2
                 << line().p2() + offset2
                 << line().p2() + offset1;
    selectionPolygon = nPolygon;
    update();
}

QRectF DiagramItems::boundingRect() const {
    return selectionPolygon.boundingRect();
}

QPainterPath DiagramItems::shape() const{
    QPainterPath ret;
    ret.addPolygon(selectionPolygon);
    return ret;
}

void DiagramItems::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                           QWidget *widget){
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(pen());
    painter->drawLine(line());
    if (isSelected()) {
        painter->setPen(QPen(Qt::black, 2, Qt::DashLine));
        painter->drawPolygon(selectionPolygon);
    }
}

