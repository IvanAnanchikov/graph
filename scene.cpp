#include "scene.hpp"

scene::scene(QObject *parent) : QGraphicsScene(parent)
{
}
scene::~scene()
{
}
void scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
  //if (Cursor)
  //{
    addEllipse(event->scenePos().x() - 5,
               event->scenePos().y() - 5,
               5,
               5,
               QPen(Qt::NoPen),
               QBrush(Qt::gray));
    previousPoint = event->scenePos();
   //}
}

void scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
//  if (Cursor)
//  {
    addLine(previousPoint.x(),
            previousPoint.y(),
            event->scenePos().x(),
            event->scenePos().y(),
            QPen(Qt::green,5,Qt::SolidLine,Qt::RoundCap));
    previousPoint = event->scenePos();
//  }
}
