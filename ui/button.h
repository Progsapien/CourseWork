#ifndef BUTTON_H
#define BUTTON_H

#include <QLabel>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>

class Button : public QLabel
{
    Q_OBJECT
public:
    Button(QString text);
    Button(QString text, QString imgPath, int position = 2);
    enum ImagePosition {
        Left = 1, Top, Right
    };

    void setDefaultOpacity(float opacity);

private:
    void setOpacity(float opacity);
    float default_opacity;

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void enterEvent(QEvent *event);
    virtual void leaveEvent(QEvent *event);
signals:
    void clicked();
};

#endif // BUTTON_H
