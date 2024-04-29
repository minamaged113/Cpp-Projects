#include <iostream>

#include "line/line.h"

void line(Point<int> p0, Point<int> p1, TGAImage &image, TGAColor color) {
    bool steep = false;

    if (std::abs(p1.x - p0.x) < std::abs(p1.y - p0.y)) {
        std::swap(p0.x, p0.y);
        std::swap(p1.x, p1.y);
        steep = true;
    }

    if (p0.x > p1.x) {
        std::swap(p1.x, p0.x);
        std::swap(p1.y, p0.y);
    }

    int dy = p1.y - p0.y;
    int dx = p1.x - p0.x;

    // float slope = std::abs(dy/(float)dx);
    int slope = std::abs(dy) * 2;
    // float error = 0;
    int error = 0;
    int y = p0.y;

    for (int x = p0.x; x <= p1.x; x++) {
        if (steep) {
            image.set(y, x, color);
        } else {
            image.set(x, y, color);
        }

        error += slope;
        if (error > dx) {
            y += (dy > 0) ? 1 : -1;
            // error -= 1.;
            error -= dx * 2;
        }
    }
}

/*
static void line_unoptimized(int x0, int y0, int x1, int y1, TGAImage &image,
TGAColor color)
{
        // states whether height is larger than width
        bool steep = false;
        int dy = y1-y0;
        int dx = x1-x0;
        // float abs_slope = std::abs(dy-dx);

        // Check if width is smaller than height
        if (std::abs(dx) < std::abs(dy))
        {
                std::swap(x0, y0);
                std::swap(x1, y1);
                steep = true;
        }

        // check if given points are reversed
        // i.e. end point given first
        // assuming starting point has lower x value
        // and ending point has hight x value
        // >> If reversed, reverse them
        if (x0 > x1)
        {
                std::swap(x0, x1);
                std::swap(y0, y1);
        }

        for (int x = x0; x < x1; x++)
        {
                float t = (x-x0) / (float)dx;
                int y = y0 * (1.-t) + y1 * t;
                if (steep)
                {
                        image.set(y, x, color);
                } else {
                        image.set(x, y, color);
                }
        }


}
*/