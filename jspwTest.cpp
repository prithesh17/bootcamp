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

void printVector(vector<int> vec)
{
    for (auto val : vec)
    {
        cout << val << " ";
    }
}

int min(int a, int b, int c)
{
    if (a < b && a < c)
    {
        return a;
    }
    else if (b < c)
    {
        return b;
    }
    else
    {
        return c;
    }
}

int min(int a, int b, int c)
{
    if (a > b && a > c)
    {
        return a;
    }
    else if (b > c)
    {
        return b;
    }
    else
    {
        return c;
    }
}

vector<int> findsmallestPath(vector<vector<int>> input, vector<vector<int>> matrix, int i, int j, vector<int> &result)
{
    if (i == 0 && j == 0)
    {
        return result;
    }
    if (matrix[i - 1][j] < matrix[i][j - 1] && matrix[i - 1][j] < matrix[i - 1][j - 1])
    {
        result.insert(result.begin(), input[i - 1][j]);
        i = i - 1;
    }
    else if (matrix[i][j - 1] < matrix[i - 1][j - 1])
    {
        result.insert(result.begin(), input[i][j - 1]);
        j = j - 1;
    }
    else
    {
        result.insert(result.begin(), input[i - 1][j - 1]);
        i = i - 1;
        j = j - 1;
    }
    return findsmallestPath(input, matrix, i, j, result);
}

vector<int> findLargestPath(vector<vector<int>> input, vector<vector<int>> matrix, int i, int j, vector<int> &result)
{
    if (i == 0 && j == 0)
    {
        return result;
    }
    if (matrix[i - 1][j] > matrix[i][j - 1] && matrix[i - 1][j] > matrix[i - 1][j - 1])
    {
        result.insert(result.begin(), input[i - 1][j]);
        i = i - 1;
    }
    else if (matrix[i][j - 1] > matrix[i - 1][j - 1])
    {
        result.insert(result.begin(), input[i][j - 1]);
        j = j - 1;
    }
    else
    {
        result.insert(result.begin(), input[i - 1][j - 1]);
        i = i - 1;
        j = j - 1;
    }
    return findLargestPath(input, matrix, i, j, result);
}

vector<int> smallestSum(vector<vector<int>> input, int rows, int cols)
{
    vector<int> result;
    vector<vector<int>> matrix(rows, vector<int>(cols));
    matrix[0][0] = input[0][0];
    for (int i = 1; i < cols; i++)
    {
        matrix[0][i] = matrix[0][i - 1] + input[0][i];
    }
    for (int i = 1; i < rows; i++)
    {
        matrix[i][0] = matrix[i - 1][0] + input[i][0];
    }
    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            matrix[i][j] = min(matrix[i][j - 1], matrix[i - 1][j], matrix[i - 1][j - 1]) + input[i][j];
        }
    }
    cout << "Minimum Sum is " << matrix[rows - 1][cols - 1] << endl;
    result.insert(result.begin(), input[rows-1][cols-1]);
    return findsmallestPath(input, matrix, rows - 1, cols - 1, result);
}


vector<int> largestSum(vector<vector<int>> input, int rows, int cols)
{
    vector<int> result;
    vector<vector<int>> matrix(rows, vector<int>(cols));
    matrix[0][0] = input[0][0];
    for (int i = 1; i < cols; i++)
    {
        matrix[0][i] = matrix[0][i - 1] + input[0][i];
    }
    for (int i = 1; i < rows; i++)
    {
        matrix[i][0] = matrix[i - 1][0] + input[i][0];
    }
    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            matrix[i][j] = max(matrix[i][j - 1], matrix[i - 1][j], matrix[i - 1][j - 1]) + input[i][j];
        }
    }
    cout << "Maximum Sum is " << matrix[rows - 1][cols - 1] << endl;
    result.insert(result.begin(), input[rows-1][cols-1]);
    return findLargestPath(input, matrix, rows - 1, cols - 1, result);
}



int main()
{
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> input(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> input[i][j];
        }
    }
    vector<int> result1 = smallestSum(input, rows, cols);
    vector<int> result2 = largestSum(input,rows,cols);
    cout<<"Shortest path for MIN sum : ";
    printVector(result1);
    cout<<"Shortest path for MAX sum : ";
    printVector(result2);
}
