#include<iostream>
#include<string>
#include<cstdio>
#include<memory>
#include<math.h>
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
    unique_ptr<int[]> iterationsHistogram(new int[Mandelbrot::MAX_ITERATIONS]{0});
    unique_ptr<int[]> fractalIterations(new int[WIDTH*HEIGHT]{0});
    long total = 0;
    for(int x = 0; x < WIDTH; x++)
    {
        for(int y = 0; y < HEIGHT; y++)
        {
            double x_fractal = (x - WIDTH/2 - 200) * (2.0/HEIGHT);
            double y_fractal = (y - HEIGHT/2) * (2.0/HEIGHT);
            int iterations = Mandelbrot::getIterations(x_fractal,y_fractal);
            fractalIterations[y*WIDTH + x] = iterations;
            if(iterations < Mandelbrot::MAX_ITERATIONS)
            {
                iterationsHistogram[iterations]++;
                total++;
            }
        }
    }

    for(int x = 0; x < WIDTH; x++)
    {
        for(int y = 0; y < HEIGHT; y++)
        {
            int iterations = fractalIterations[y*WIDTH + x];
            double hue = 0.0;
            if(iterations < Mandelbrot::MAX_ITERATIONS)
            {
                for(int i = 0; i <= iterations; i++)
                {
                    hue += (static_cast<double>(iterationsHistogram[i]))/total;
                }
            }
            map.setPixel(x,y,0,hue*255,0);
        }
    }
    

    map.write(fileName);
    cout << fileName << " written" << endl;

    return 0;
}