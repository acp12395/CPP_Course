#ifndef BITMAP_H__
#define BITMAP_H__

#include<cstdint>
#include<string>
#include<memory>

using namespace std;

namespace project_fractal
{

class Bitmap
{
private:
    int32_t m_width{0};
    int32_t m_height{0};
    unique_ptr<uint8_t[]> m_pPixels;
public:
    Bitmap(int32_t width, int32_t height);
    bool write(string fileName);
    void setPixel(int32_t x, int32_t y, uint8_t red, uint8_t green, uint8_t blue);
    virtual ~Bitmap();
};

}
#endif