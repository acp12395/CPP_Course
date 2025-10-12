#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream file;
    file.open("WriteFile.txt");
    if(file.is_open())
    {
        for(int i = 1; i <= 10; i++)
        {
            string inData;
            cin >> inData;
            file << i << ". " << inData << endl;
        }
        file.close();
    }
    return 0;
}