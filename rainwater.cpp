#include <iostream>
#include <vector>

using namespace std;

bool isThereWall(vector<int> v, int i, int j, int min)
{
    for (int k = i + 1; k < j; k++)
    {
        if (v[k] > min)
        {
            return true;
        }
    }
    return false;
}

int rainWater(vector<int> vec)
{
    int totalWater = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = i + 1; j < vec.size(); j++)
        {
            int min = vec[i] < vec[j] ? vec[i] : vec[j];

            if (!isThereWall(vec, i, j, min))
            {
                int water = min * (j - i);
                if (water > totalWater)
                {
                    totalWater = water;
                }
            }
        }
    }
    return totalWater;
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
    cout << "Total Water : " << rainWater(v);
}