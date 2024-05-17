#if !defined(__LINE_H__)
#define __LINE_H__

#include "point/point.h"
#include "tgaimage/tgaimage.h"

class LineSegment {
  private:
    float slope;
    int intercept;
    int __compute_y(Point<int> &p) {
        // y = mx + c;
        return (int)(slope * p.x + intercept);
    }

  public:
    int start;
    LineSegment() = default;
    // LineSegment() {}
    virtual ~LineSegment() = default;
    bool has(Point<int> &p, float epsilon = 0.0001) {
        // compute the actual y on the line
        int y_on_line = __compute_y(p);
        return (std::abs(p.y - y_on_line)) < epsilon;
    }
    void draw(Point<int> &p0, Point<int> &p1, TGAImage &image,
              TGAColor &color) {
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
};

void line(Point<int> p0, Point<int> p1, TGAImage &image, TGAColor color);

#endif // __LINE_H__
