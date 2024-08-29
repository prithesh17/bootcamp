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


vector<int> corona(vector<int> v, int spike)
{
    if(!spike) return v;
    vector <int> result;
    for(int i=0;i<v.size();i++){
        int value = v[i]>>spike;
        result.push_back(value);
    }
    return result;
}

int main()
{
    int size;
    int spike;
    vector<int> v;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        int element;
        cin >> element;
        v.push_back(element);
    }
    cin >> spike;
    if (!size)
        cout << "Enter Valid Array" << endl;
    else
    {
        vector<int> result = corona(v, spike);
        print(result);
    }
    return 0;
}