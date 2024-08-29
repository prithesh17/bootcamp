#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> v)
{
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
}

vector<int> nextGreater(vector<int> v)
{
    bool flag;
    vector<int> result;
    for (int i = 0; i < v.size(); i++)
    {
        int nextGreater = i;
        while (nextGreater != v.size())
        {
            flag = false;
            if (v[nextGreater] > v[i])
            {
                result.push_back(v[nextGreater]);
                flag = true;
                break;
            }
            nextGreater++;
        }
        if (!flag)
            result.push_back(-1);
    }
    return result;
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
    vector<int> result = nextGreater(v);
    print(result);
}