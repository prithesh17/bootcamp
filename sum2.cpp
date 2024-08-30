#include <iostream>
#include <vector>

using namespace std;


void print(const vector<vector<int>>& vec)
{
    for (const auto& it : vec)
    {
        for (int val : it)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}



void findSum(int index, vector<int>& v, vector<int> ans, int sum, int k, vector<vector<int>>& result)
{
    if (index >= v.size()) {
        if (sum == k) {
            result.push_back(ans);
        }
        return;
    }
    ans.push_back(v[index]);
    sum += v[index];
    findSum(index + 1, v, ans, sum, k, result);
    
    sum -= v[index];
    ans.pop_back();
    findSum(index + 1, v, ans, sum, k, result);
}



int main()
{
    int size, target;
    cin >> size;
    
    vector<int> v(size);
    for (int i = 0; i < size; i++)
    {
        cin >> v[i];
    }
    cin >> target;

    vector<vector<int>> result;
    vector<int> ans;

    findSum(0,v,ans,0,target,result);

    print(result);

    return 0;
}
