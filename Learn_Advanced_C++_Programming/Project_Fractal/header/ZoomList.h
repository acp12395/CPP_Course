#ifndef ZOOMLIST_H__
#define ZOOMLIST_H__

#include<vector>
#include<utility>
#include "Zoom.h"

using namespace std;

namespace project_fractal
{

class ZoomList
{
private:
    double m_scale{1.0};
    double m_xCenter{0.0};
    double m_yCenter{0.0};

    vector<Zoom> m_zooms;
    int m_width{0};
    int m_height{0};
public:
    ZoomList(int width, int height);
    void add(const Zoom& zoom);
    pair<double,double> doZoom(int x, int y);
};

}
#endif