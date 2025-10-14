#include<iostream>
#include<string>
#include<cstdio>
#include"../header/Mandelbrot.h"
#include"../header/Bitmap.h"

using namespace std;
using namespace project_fractal;

int main()
{
    const int WIDTH = 800;
    const int HEIGHT = 600;
    Bitmap map(WIDTH,HEIGHT);
    string fileName{"image.bmp"};
    for(int x = 0; x < WIDTH; x++)
    {
        for(int y = 0; y < HEIGHT; y++)
        {
            double x_fractal = (x - WIDTH/2 - 200) * (2.0/HEIGHT);
            double y_fractal = (y - HEIGHT/2) * (2.0/HEIGHT);
            uint8_t intensity = (uint8_t)((256*(double)(Mandelbrot::getIterations(x_fractal,y_fractal))/Mandelbrot::MAX_ITERATIONS));
            map.setPixel(x,y,0,intensity,0);
        }
    }
    map.write(fileName);
    cout << fileName << " written" << endl;

    return 0;
}