#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class Window : public QWidget
{
    Q_OBJECT

    public:
        explicit Window(QWidget *parent = nullptr);

    signals:
    public slots:
    protected:
        //void resizeEvent(QResizeEvent *event) override;
    private:

};

#endif // WINDOW_H
