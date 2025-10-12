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

            getline(file,line);

            cout<<line<<endl;
        }
        file.close();
    }
    return 0;
}