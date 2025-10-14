#ifndef MANDELBROT_H__
#define MANDELBROT_H__

namespace project_fractal
{

class Mandelbrot
{
public:
    static const int MAX_ITERATIONS{10000};
public:
    Mandelbrot();
    static int getIterations(double x, double y);
    ~Mandelbrot();
};

}
#endif