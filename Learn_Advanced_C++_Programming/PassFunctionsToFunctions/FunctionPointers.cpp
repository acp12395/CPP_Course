#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool hasThreeChar(string str)
{
    return str.size() == 3;
}

int countMatches(const vector<string>& strings, bool (*match)(string))
{
    int retCount = 0;
    for(auto& str : strings)
    {
        if(match(str))
        {
            retCount++;
        }
    }
    return retCount;
}

int main()
{
    vector<string> strings({"One","Two","Three"});
    cout << count_if(strings.begin(), strings.end(), hasThreeChar) << endl;
    cout << countMatches(strings, &hasThreeChar) << endl;
    return 0;
}