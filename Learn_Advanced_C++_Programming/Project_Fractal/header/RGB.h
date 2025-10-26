#ifndef RGB_H__
#define RGB_H__

namespace project_fractal{

struct RGB
{
    double r;
    double g;
    double b;

    RGB(double r, double g, double b);
};

RGB operator-(const RGB&, const RGB&);

}

#endif