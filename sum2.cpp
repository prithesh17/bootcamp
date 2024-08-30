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

vector<vector<int>> fun(vector<int> vec, int target, vector<vector<int>> result, vector<int> ans, int sum, int index)
{
    if (index == vec.size())
    {
        return result;
    }
    ans.push_back(vec[index]);
    sum += vec[index];
    if (sum == target)
    {
        result.push_back(ans);
    }
    fun(vec,target,result,ans,sum,index+1);
    ans.pop_back();
    sum-=vec[index];
    fun(vec,target,result,ans,sum,index+1);
}


vector<vector<int>> findSum(vector<int> vec, int target)
{
    vector<vector<int>> result;
    vector<int> ans;
    int sum = 0;
    int index = 0;
    vector<vector<int>> result = fun(vec, target, result, ans, sum, index);
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