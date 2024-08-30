#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>> vec)
{
    for (auto it : vec)
    {
        for (auto val : it)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> findSum(vector<int> vec, int target)
{
    vector<vector<int>> result;
    for (int i = 0; i < vec.size() - 1; i++)
    {
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec[i] + vec[j] == target)
            {
                result.push_back({vec[i], vec[j]});
            }
        }
    }
    return result;
}
int main()
{
    int size;
    int target;
    cin >> size;
    vector<int> v;
    for (int i = 0; i < size; i++)
    {
        int element;
        cin >> element;
        v.push_back(element);
    }
    cin >> target;
    vector<vector<int>> result = findSum(v, target);
    print(result);
}