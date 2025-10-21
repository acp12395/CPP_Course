#include<iostream>
#include<string>
#include<cstdio>
#include<memory>
#include<math.h>
#include"../header/Mandelbrot.h"
#include"../header/Bitmap.h"
#include"../header/ZoomList.h"

using namespace std;
using namespace project_fractal;

int main()
{
    const int WIDTH = 800;
    const int HEIGHT = 600;
    Bitmap map(WIDTH,HEIGHT);
    string fileName{"image.bmp"};
    ZoomList zoomList(WIDTH,HEIGHT);
    zoomList.add(Zoom(WIDTH/2, HEIGHT/2, 4.0/WIDTH));
    zoomList.add(Zoom(295, HEIGHT - 202, 0.1));
    zoomList.add(Zoom(312, HEIGHT - 304, 0.1));
    unique_ptr<int[]> iterationsHistogram(new int[Mandelbrot::MAX_ITERATIONS]{0});
    unique_ptr<int[]> fractalIterations(new int[WIDTH*HEIGHT]{0});
    long total = 0;
    for(int x = 0; x < WIDTH; x++)
    {
        for(int y = 0; y < HEIGHT; y++)
        {
            pair<double,double> coords = zoomList.doZoom(x,y);
            int iterations = Mandelbrot::getIterations(coords.first,coords.second);
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