#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#pragma pack(push,1)
struct Person
{
    char name[50];
    unsigned int age;
    double height;
};
#pragma pack(pop)

int main()
{
    Person someone = {"Charles", 18, 1.8};
    string fileName = "StructFile.bin";

    // Write file
    ofstream w_file;
    w_file.open(fileName, ios::binary);
    if(w_file.is_open())
    {
        w_file.write(reinterpret_cast<char *>(&someone), sizeof(Person));
        cout << "Name before clearing: " << someone.name << endl;
        someone = {"", 0, 0};
        cout << "Name after clearing: " << someone.name << endl;
        w_file.close();
    }
    else
    {
        cout << "File " << fileName << "could not be opened" << endl;
    }

    // Read file
    ifstream r_file;
    r_file.open(fileName, ios::binary);
    if(r_file.is_open())
    {
        r_file.read(reinterpret_cast<char *>(&someone), sizeof(Person));
        cout << "Name after reading: " << someone.name << endl;
        r_file.close();
    }
    else
    {
        cout << "File " << fileName << "could not be opened" << endl;
    }

    return 0;
}