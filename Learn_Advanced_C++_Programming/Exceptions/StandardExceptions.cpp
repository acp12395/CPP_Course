#include <iostream>
using namespace std;

void mightGoWrong()
{
    int a;
    cin>>a;
    char* pMemory = new char[a];
    delete pMemory;
}

int main()
{
    try{
        mightGoWrong();
    }
    catch(bad_alloc& e)
    {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}