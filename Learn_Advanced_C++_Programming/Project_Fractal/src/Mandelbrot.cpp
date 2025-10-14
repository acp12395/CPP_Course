#include <complex>
#include "../Header/Mandelbrot.h"

using namespace std;

namespace project_fractal
{

Mandelbrot::Mandelbrot(){}

int Mandelbrot::getIterations(double x, double y)
{
    complex<double> Z = 0;
    complex<double> C(x,y);

    int iterations;

    for(iterations = 0; iterations < MAX_ITERATIONS && abs(Z) <= 2; iterations++)
    {
        Z = Z*Z + C;
    }

    return iterations;
}

Mandelbrot::~Mandelbrot(){}

}