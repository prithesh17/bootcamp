#include <iostream>
#include <vector>

using namespace std;

int rowSum(vector<vector<int>> matrix)
{
    int sum = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        sum = sum + matrix[i][i];
    }
    return sum;
}

int colSum(vector<vector<int>> matrix)
{
    int sum = 0;
    int index1=0;
    int index2 = matrix.size()-1;
    while(index1!=matrix.size()){
        sum+=matrix[index1++][index2--];
    }
    return sum;
}

int main()
{
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> matrix(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << "Row sum is : " << rowSum(matrix)<<endl;
    cout << "Column sum is : " << colSum(matrix)<<endl;
}
