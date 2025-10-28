#include<cassert>
#include"../header/FractalCreator.h"

using namespace std;

namespace project_fractal
{

void FractalCreator::addRange(double range, const RGB& rgb)
{
    m_ranges.push_back(range*Mandelbrot::MAX_ITERATIONS);
    m_colors.push_back(rgb);

    if(m_bGotFirstRange)
    {
        m_rangeTotals.push_back(0);
    }

    m_bGotFirstRange = true;
}

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

void FractalCreator::calculateRangeTotals()
{
    int rangeIndex = 0;

    for(int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
    {
        int pixels = m_iterationsHistogram[i];
        if(i >= m_ranges[rangeIndex+1])
        {
            rangeIndex++;
        }
        m_rangeTotals[rangeIndex] += pixels;
    }

    for(auto value : m_rangeTotals)
    {
        cout << "Range total: " << value << endl;
    }
}

int FractalCreator::getRange(int iterations) const
{
    int range = 0;

    for(int i = 1; i < m_ranges.size(); i++)
    {
        range = i;
        if(m_ranges[i] > iterations)
        {
            break;
        }
    }
    range--;

    assert(range >= 0);
    assert(range < m_ranges.size());

    return range;
}

void FractalCreator::drawFractal()
{
    for(int x = 0; x < m_width; x++)
    {
        for(int y = 0; y < m_height; y++)
        {
            int iterations = m_fractalIterations[y*m_width+ x];

            int range = getRange(iterations);
            int rangeTotal = m_rangeTotals[range];
            int rangeStart = m_ranges[range];

            RGB& startColor = m_colors[range];
            RGB& endColor = m_colors[range + 1];
            RGB colorDiff = endColor - startColor;

            int totalPixels = 0;
            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            if(iterations < Mandelbrot::MAX_ITERATIONS)
            {
                for(int i = rangeStart; i <= iterations; i++)
                {
                    totalPixels += m_iterationsHistogram[i];
                }

                red = startColor.r + colorDiff.r*(double)totalPixels/rangeTotal;
                green = startColor.g + colorDiff.g*(double)totalPixels/rangeTotal;
                blue = startColor.b + colorDiff.b*(double)totalPixels/rangeTotal;
            }
            m_map.setPixel(x,y,red,green,blue);
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