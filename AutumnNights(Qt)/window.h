#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class Canvas;

class Window : public QWidget
{
    Q_OBJECT

    public:
        explicit Window(QWidget *parent = nullptr);

    signals:

    public slots:

    private:
        Canvas *canvas;
};

#endif // WINDOW_H
