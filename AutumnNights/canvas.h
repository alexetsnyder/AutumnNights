#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>

using namespace std;

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
        void keyPressEvent(QKeyEvent *event);
        void keyReleaseEvent(QKeyEvent *event);

    private:
        vector<int>::iterator getIteratorOfKey(int key);

        vector<int> keys;
        QPixmap pixMap;
        QBrush background;
};

#endif // CANVAS_H
