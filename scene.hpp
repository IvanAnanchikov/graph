#ifndef SCENE_HPP
#define SCENE_HPP

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class scene : public QGraphicsScene
{

    Q_OBJECT

public:
    explicit scene(QObject *parent = 0);
    ~scene();
    bool Cursor = true;
private:
    QPointF     previousPoint;

private:
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);



};

#endif // SCENE_HPP
