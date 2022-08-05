#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>

class Canvas : public QWidget
{
    Q_OBJECT

    public:
        explicit Canvas(QWidget *parent = nullptr);

    signals:

    public slots:

    protected:
        void paintEvent(QPaintEvent *event) override;

    private:

};

#endif // CANVAS_H
