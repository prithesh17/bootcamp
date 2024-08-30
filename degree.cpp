#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int>> vec)
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

vector<vector<int>> transposeMatrix(vector<vector<int>> matrix)
{
    for (int i = 0; i <= matrix.size() / 2; i++)
    {
        for (int j = i; j < matrix[i].size(); j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    return matrix;
}

vector<vector<int>> reverseRow(vector<vector<int>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size() / 2; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][matrix[i].size() - j - 1];
            matrix[i][matrix[i].size() - j - 1] = temp;
        }
    }
    return matrix;
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
    printMatrix(reverseRow(transposeMatrix(matrix)));
}
