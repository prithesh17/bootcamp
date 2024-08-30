#include <iostream>
#include <vector>

using namespace std;

bool isPythagoras(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            for (int k = j; k < v.size(); k++)
            {
                if ((v[i] * v[i]) == ((v[j] * v[j]) + v[k] * v[k]))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    int size;
    vector<int> v;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        int element;
        cin >> element;
        v.push_back(element);
    }
    if (isPythagoras(v))
        cout << "True";
    else
        cout << "False";
}