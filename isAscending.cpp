#include <iostream>
using namespace std;

bool isAscending(string s)
{
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] > s[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string str;
    cin >> str;
    if (isAscending(str))
        cout << "True";
    else
        cout << "False";
}