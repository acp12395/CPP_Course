#include<iostream>
#include<list>
using namespace std;

int main()
{
    list<int> myList;
    for(int i = 1; i < 4; i++)
    {
        myList.push_back(i);
    }
    myList.push_front(0);

    list<int>::iterator it;
    for(it = myList.begin(); it != myList.end(); it++)
    {
        if(*it == 2)
        {
            myList.insert(it,100);
        }
        if(*it == 1)
        {
            it = myList.erase(it);
            it--;
        }

    }

    for(it = myList.begin(); it != myList.end(); it++) // you may not use neither it < myList.end() nor it += 2
    {
        cout << *it << endl;
    }

    return 0;
}