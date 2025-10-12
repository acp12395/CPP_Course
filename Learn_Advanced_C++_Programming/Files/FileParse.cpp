#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream file;
    file.open("ReadFile.txt");
    if(file.is_open())
    {
        while(file)
        {
            string line;
            getline(file,line, ':');
            int population;
            file >> population;
            if(!file)
            {
                break;
            }
            cout << line << ": " << population;
        }
        file.close();
    }
    return 0;
}