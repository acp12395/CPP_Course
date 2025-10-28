#ifndef FRACTAL_CREATOR_H__
#define FRACTAL_CREATOR_H__

#include<iostream>
#include<string>
#include<memory>
#include<vector>
#include<math.h>
#include "Zoom.h"
#include "Bitmap.h"
#include "ZoomList.h"
#include "Mandelbrot.h"
#include "RGB.h"

using namespace std;

namespace project_fractal
{

class FractalCreator
{
private:
    int m_width;
    int m_height;
    unique_ptr<int[]> m_iterationsHistogram;
    unique_ptr<int[]> m_fractalIterations;
    Bitmap m_map;
    ZoomList m_zoomList;
    long m_total{0};

    vector<int> m_ranges;
    vector<RGB> m_colors;
    vector<int> m_rangeTotals;

    bool m_bGotFirstRange{false};

    int getRange(int iterations) const;
public:
    FractalCreator(int, int);

    void calculateIterations();
    void drawFractal();
    void addZoom(const Zoom&);
    void writeBitmap(string);
    void addRange(double range, const RGB& rgb);
    void calculateRangeTotals();

    ~FractalCreator();
};

}

#endif