#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QBrush>
#include <QFont>
#include <QPen>

class QBrush;
class QFont;
class QPen;

class Canvas : public QWidget
{
    Q_OBJECT

    public:
        explicit Canvas(QWidget *parent = nullptr);

    signals:

    public slots:
        void animate();

    protected:
        void paintEvent(QPaintEvent *event) override;

    private:
        int elapsed;
        QBrush background;
        QBrush circleBrush;
        QFont textFont;
        QPen circlePen;
        QPen textPen;
};

#endif // CANVAS_H
