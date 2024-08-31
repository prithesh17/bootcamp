#include <iostream>
#include <vector>

using namespace std;

int topSum(vector<vector<int>> matrix)
{
    int sum = 0;
    for (int i = 0; i <= matrix.size() / 2; i++)
    {
        for (int j = i; j < matrix.size() - i; j++)
        {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int bottomSum(vector<vector<int>> matrix)
{
    int sum = 0;
    for (int i = matrix.size() / 2; i < matrix.size(); i++)
    {
        for (int j = i; j >= matrix.size() - i - 1; j--)
        {
            sum += matrix[i][j];
        }
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
    cout << "Top Triangle sum is : " << topSum(matrix) << endl;
    cout << "Bottom Triangle sum is : " << bottomSum(matrix) << endl;
}
