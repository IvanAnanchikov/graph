#include "scene.hpp"

scene::scene(QObject *parent) : QGraphicsScene(parent)
{
}
scene::~scene()
{
}
void scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    addEllipse(event->scenePos().x() - 5,
               event->scenePos().y() - 5,
               5,
               5,
               QPen(Qt::NoPen),
               QBrush(Qt::blue));
    previousPoint = event->scenePos();
}

void scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    addLine(previousPoint.x(),
            previousPoint.y(),
            event->scenePos().x(),
            event->scenePos().y(),
            QPen(Qt::blue,5,Qt::SolidLine,Qt::RoundCap));
    previousPoint = event->scenePos();
}
