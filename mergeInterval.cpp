#include <iostream>
#include <vector>

using namespace std;


void printIntervals(vector<vector<int>> input){
    for(auto interval : input){
        for(auto value : interval){
            cout<<value<<" ";
        }
        cout<<endl;
    }
}

void mergeIntervals(vector<vector<int>>& input, int index, int size){
    bool flag = false;
    if(index==size-1){
        return;
    }
    if(input[index+1][0] >= input[index][0] && input[index+1][0]<=input[index][1]){
        if(input[index+1][1]>input[index][1]){
            input[index][1]=input[index+1][1];
        }
        input.erase(input.begin()+index+1);
        flag=true;
        size--;
    }
    if(flag){
        mergeIntervals(input, index, size);
    }else{
        mergeIntervals(input,index+1,size);
    }
}


void sortIntervals(vector<vector<int>>& input){
    int n = input.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (input[j][0] < input[minIndex][0]) {
                minIndex = j;
            }
        }
        swap(input[i], input[minIndex]);
    }
}

int main()
{
    int size;
    cin >> size ;
    vector<vector<int>> intervals(size, vector<int>(2));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> intervals[i][j];
        }
    }
    sortIntervals(intervals);
    mergeIntervals(intervals, 0, size);
    printIntervals(intervals);
}


// 4
// 1 3
// 2 6
// 8 10
// 15 18


// 3
// 1 2
// 7 9
// 5 6

// 3
// 3 6
// 4 5
// 6 9