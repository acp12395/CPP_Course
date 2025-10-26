#include"../header/FractalCreator.h"

using namespace std;

namespace project_fractal
{

FractalCreator::FractalCreator(int width, int height):
    m_width(width),
    m_height(height),
    m_iterationsHistogram(new int[Mandelbrot::MAX_ITERATIONS]{0}),
    m_fractalIterations(new int[m_width*m_height]{0}),
    m_map(width,height),
    m_zoomList(width,height)
{}

void FractalCreator::calculateIterations()
{
    for(int x = 0; x < m_width; x++)
    {
        for(int y = 0; y < m_height; y++)
        {
            pair<double,double> coords = m_zoomList.doZoom(x,y);
            int iterations = Mandelbrot::getIterations(coords.first,coords.second);
            m_fractalIterations[y*m_width + x] = iterations;
            if(iterations < Mandelbrot::MAX_ITERATIONS)
            {
                m_iterationsHistogram[iterations]++;
                m_total++;
            }
        }
    }
}

void FractalCreator::drawFractal()
{
    for(int x = 0; x < m_width; x++)
    {
        for(int y = 0; y < m_height; y++)
        {
            int iterations = m_fractalIterations[y*m_width+ x];
            double hue = 0.0;
            if(iterations < Mandelbrot::MAX_ITERATIONS)
            {
                for(int i = 0; i <= iterations; i++)
                {
                    hue += (static_cast<double>(m_iterationsHistogram[i]))/m_total;
                }
            }
            m_map.setPixel(x,y,0,hue*255,0);
        }
    }
}

void FractalCreator::addZoom(const Zoom& zoom)
{
    m_zoomList.add(zoom);
}

void FractalCreator::writeBitmap(string fileName)
{
    m_map.write(fileName);
    cout << fileName << " written" << endl;
}

FractalCreator::~FractalCreator()
{

}

}