//
// copyright 2018 Palestine Polytechnic Univeristy
//
// This software can be used and/or modified for academich use as long as
// this commented part is listed
//
// Last modified by: Zein Salah, on 24.02.2021
//

#include "renderwidget.h"
#include <QPainter>
#include <QPen>
#include <cmath>

//using namespace std;

RenderWidget::RenderWidget(QWidget *parent) : QWidget(parent) {
	// to be implemeted later
}

QSize RenderWidget::minimumSizeHint() const {
	return QSize(100, 100);
}

QSize RenderWidget::sizeHint() const {
	return QSize(600, 600);
}

void RenderWidget::paintEvent(QPaintEvent *) {
	QPainter painter(this);

	//    painter.setRenderHint(QPainter::Antialiasing, false);
	QColor color(0, 0, 0);
	painter.setPen(color);

	painter.drawRect(QRect(0, 0, width() - 1, height() - 1));

	//  for (int x = 100; x < 300; ++x)
	//  {
	//    painter.drawPoint(x, x);
	//  }

    drawLine(197, 68, 212, 48);
    drawLine(212, 48, 243, 72);
    drawLine(243, 72, 228, 92);
    drawLine(192, 65, 232, 95);

    drawLine(192, 65, 117, 165);

    drawLine(117, 165, 156, 196);
    drawLine(121, 169, 106, 189);
    drawLine(106, 189, 136, 213);
    drawLine(136, 213, 151, 193);

    drawCircle(185, 150, 20);
    drawCircle(185, 150, 14);

    drawLine(232, 95, 201, 136);
    drawLine(177, 168, 157, 195);

    drawArc(165, 213, 490, 300, 50);
    drawArc(165, 213, 428, 301, 77);
    drawArc(165, 213, 510, 473, 77);

    drawLine(75, 250, 152, 250);
    drawLine(75, 235, 152, 235);
    drawLine(75, 250, 75, 235);
    drawLine(152, 250, 152, 235);

    drawCircle(165, 288, 10);
    drawArc(165, 288, 325, 215, 26);
    drawArc(105, 347, 315, 347, 110);
    drawArc(225, 347, 225, 193, 110);

    drawLine(70, 323, 260, 323);
    drawLine(70, 308, 122, 308);
    drawLine(208, 308, 260, 308);
    drawLine(70, 323, 70, 308);
    drawLine(260, 308, 260, 323);
}

void swapPoints(int &x1, int &y1, int &x2, int &y2) {
    int temp = x1;
    x1 = x2;
    x2 = temp;
    temp = y1;
    y1 = y2;
    y2 = temp;
}

void RenderWidget::drawLine(int x1, int y1, int x2, int y2) {
	QPainter painter(this);
	QPen pen(Qt::black, 2, Qt::SolidLine);
	painter.setPen(pen);

    painter.drawPoint(x1, y1);

    int dx, dy, c1, c2, p, x, y, inc, dRef, dTargetPoint,
        *ref = &x,
        *targetPoint = &y,
        ref1,
        ref2,
        targetPoint1;

    if (abs(y2 - y1) < abs(x2 - x1)) {
        // for |m| < 1
        if (x1 > x2) {
            // In case of drawing a line on the left side of the coordinate
            swapPoints(x1, y1, x2, y2);
        }
        dx = x2 - x1;
        dy = y2 - y1;

        // set x as the reference
        ref1 = x1,
        ref2 = x2,
        targetPoint1 = y1;
        dRef = dx,
        dTargetPoint = dy;

    } else {
        // for |m| > 1
        if (y1 > y2) {
            // In case of drawing a line on the left side of the coordinate
            swapPoints(x1, y1, x2, y2);
        }
        dx = x2 - x1;
        dy = y2 - y1;

        // set y to be the refernce
        ref = &y;
        targetPoint = &x;
        ref1 = y1,
        ref2 = y2,
        targetPoint1 = x1;
        dRef = dy,
        dTargetPoint = dx;
    }

    inc = 1;
    if (dTargetPoint < 0) {
        inc = -1;
        dTargetPoint = -dTargetPoint;
    }
    c1 = 2 * dTargetPoint;
    c2 = 2 * (dTargetPoint - dRef);
    p = c1 - dRef;
    *targetPoint = targetPoint1;
    for (*ref = ref1 + 1; *ref <= ref2; ++*ref) {
        if (p < 0) {
            p = p + c1;
        } else {
            *targetPoint = *targetPoint + inc;
            p = p + c2;
        }
        painter.drawPoint(x, y);
    }
}

void drawCirclePoints(QPainter &painter, int xc, int yc, int x, int y) {
    painter.drawPoint(xc+x, yc+y);
    painter.drawPoint(xc-x, yc+y);
    painter.drawPoint(xc+x, yc-y);
    painter.drawPoint(xc-x, yc-y);
    painter.drawPoint(xc+y, yc+x);
    painter.drawPoint(xc-y, yc+x);
    painter.drawPoint(xc+y, yc-x);
    painter.drawPoint(xc-y, yc-x);
}

void RenderWidget::drawCircle(int xc, int yc, int r) {
    QPainter painter(this);
    QPen pen(Qt::black, 2, Qt::SolidLine);
    painter.setPen(pen);

    int x = 0, y = r,
        d = 3 - 2*r;

    drawCirclePoints(painter, xc, yc, x, y);

    while (y >= x) {
        x++;
        if (d > 0) {
            y--;
            d = d + 4*(x-y) + 10;
        } else {
            d = d + 4*x + 6;
        }

        drawCirclePoints(painter, xc, yc, x, y);
    }
}

void RenderWidget::drawArc(int xc, int yc, float t1, float t2, int r) {
    QPainter painter(this);
    QPen pen(Qt::black, 2, Qt::SolidLine);
    painter.setPen(pen);

    if (t1 > t2) {
        float t = t1;
        t1 = t2;
        t2 = t;
    }

//    t1 = t1*3.14159/180;
//    t2 = t2*3.14159/180;

    float t = t1;
    double dt = 1;

    while (t < t2) {
        int x = r*cos(t*3.14159/180),
            y = r*sin(t*3.14159/180);
        painter.drawPoint(xc+x, yc+y);
        t = t + dt;
    }
}
