#include <iostream>
#include <string>
#include "RingBuffer.h"

using namespace std;

int main()
{
    RingBuffer<string> buffer(3);
    buffer.add("Hi");
    buffer.add("World");
    buffer.add("!");
    buffer.add("Hello");
    
    // C++98
    for(RingBuffer<string>::iterator it = buffer.begin(); it != buffer.end(); it++)
    {
        cout << *it << endl;
    }

    // C++11
    for(auto element : buffer)
    {
        cout << element << endl;
    }

    return 0;
}