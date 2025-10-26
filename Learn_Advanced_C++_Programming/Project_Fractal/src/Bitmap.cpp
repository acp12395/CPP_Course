#include<fstream>
#include"../header/Bitmap.h"
#include"../header/BitmapFileHeader.h"
#include"../header/BitmapInfoHeader.h"

namespace project_fractal
{

Bitmap::Bitmap(int32_t width, int32_t height) : m_width(width), m_height(height), m_pPixels(new uint8_t[width * height * 3]{}){}

bool Bitmap::write(string fileName)
{
    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;

    infoHeader.width = m_width;
    infoHeader.height = m_height;

    fileHeader.dataOffset = sizeof(fileHeader) + sizeof(infoHeader);
    fileHeader.fileSize = fileHeader.dataOffset + infoHeader.width * infoHeader.height * 3;

    ofstream file;
    file.open(fileName, ios::binary|ios::out);

    if(!file)
    {
        return false;
    }

    file.write((char*)&fileHeader, sizeof(fileHeader));
    file.write((char*)&infoHeader, sizeof(infoHeader));
    file.write((char*)m_pPixels.get(), m_width*m_height*3);

    file.close();

    if(!file)
    {
        return false;
    }

    return true;
}

void Bitmap::setPixel(int32_t x, int32_t y, uint8_t red, uint8_t green, uint8_t blue)
{
    uint8_t* l_pPixel = m_pPixels.get();
    l_pPixel += (3 * y) * m_width + (3 * x);
    l_pPixel[0] = blue;
    l_pPixel[1] = green;
    l_pPixel[2] = red;
}

Bitmap::~Bitmap(){}


Bitmap& Bitmap::operator=(const Bitmap& bitmap)
{
    m_width = bitmap.m_width;
    m_height = bitmap.m_width;
    return *this;
}

}