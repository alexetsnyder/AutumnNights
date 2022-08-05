#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>

class Canvas : public QWidget
{
    Q_OBJECT

    public:
        explicit Canvas(QWidget *parent = nullptr);

        void draw();

    signals:

    public slots:

    protected:
        void paintEvent(QPaintEvent *event) override;

    private:
        QPixmap pixMap;
        QBrush background;
};

#endif // CANVAS_H
