#include<iostream>
#include<string>
#include<cstdio>

#include"../header/FractalCreator.h"

using namespace std;
using namespace project_fractal;

int main()
{
    const int WIDTH = 800;
    const int HEIGHT = 600;
    FractalCreator fractal(WIDTH, HEIGHT);
    fractal.addZoom(Zoom(WIDTH/2, HEIGHT/2, 4.0/WIDTH));
    fractal.addZoom(Zoom(295, HEIGHT - 202, 0.1));
    fractal.addZoom(Zoom(312, HEIGHT - 304, 0.1));

    fractal.addRange(0, RGB(0,0,255));
    fractal.addRange(0.01, RGB(255,0,255));
    fractal.addRange(0.03, RGB(255,255,0));
    fractal.addRange(1.0, RGB(255,255,255));

    fractal.calculateIterations();
    fractal.calculateRangeTotals();
    fractal.drawFractal();

    string fileName{"image.bmp"};
    fractal.writeBitmap(fileName);

    return 0;
}