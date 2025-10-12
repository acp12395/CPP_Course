#include<iostream>
#include<string>
#include"../header/Bitmap.h"

using namespace std;
using namespace project_fractal;

int main()
{
    const int WIDTH = 800;
    const int HEIGHT = 600;
    Bitmap map(WIDTH,HEIGHT);
    string fileName{"image.bmp"};
    map.write(fileName);
    cout << fileName << " written" << endl;
    return 0;
}