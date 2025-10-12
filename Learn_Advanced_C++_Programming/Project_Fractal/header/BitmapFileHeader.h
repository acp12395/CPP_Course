#ifndef BITMAPFILEHEADER_H__
#define BITMAPFILEHEADER_H__

#include<cstdint>

using namespace std;

namespace project_fractal
{

#pragma pack(2)
struct BitmapFileHeader
{
    char header[2]{'B','M'};
    int32_t fileSize;
    int32_t reserved{0};
    int32_t dataOffset;
};

}
#endif