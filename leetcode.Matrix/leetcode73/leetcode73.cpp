#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <set>

//原地算法：即在函数的输入矩阵上直接修改，而不是 return 一个矩阵
// 暴力解法
void setZeroes(vector<vector<int>>& matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) return;

    int row = matrix.size();      //行 
    int column = matrix[0].size();//列
    
    vector<vector<int>> vis(row, vector<int> (column, 1));
    //vis用于查找0的位置
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            if (matrix[i][j] == 0) vis[i][j] = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++)
        {
            if (vis[i][j] == 0)
            {
                fill(matrix[i].begin(), matrix[i].end(), 0);    //每一行置位0  
                for_each(matrix.begin(), matrix.end(), 
                    [j](vector<int>& row) { row[j] = 0;});      //每一列置为0
            }
        }
    }
}

// 优化：在空间复杂度是 O(MN) 的解法中，我们需要对于每个出现的 0 都修改对应的行列。
// 那么，如果同一个行（列）中如果出现了两个 0 ，则需要把该行（列）置两遍 0 。
// 无论是空间还是时间复杂度，都不好。
void setZeroes2(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return;

    int m = matrix.size();
    int n = matrix[0].size();
    // set 的key就是value，并且key是独一无二的
    set<int> row;
    set<int> col;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) {
                row.insert(i);
                col.insert(j);
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (row.find(i) != row.end() || col.find(j) != col.end()) {
                matrix[i][j] = 0;
            }
        }
    }
}


int main()
{
    vector<vector<int>> matrix = { {1,1,1}, {1,0,1}, {1,1,1} };
    vector<vector<int>> matrix2 = { {0,1,2,0} , {3,4,5,2}, {1,3,1,5} };
    setZeroes2(matrix2);
    for (auto it = matrix2.begin(); it != matrix2.end(); it++)
    {
        for (auto it2 = it->begin(); it2 != it->end(); it2++)
        {
            cout << *it2 << ' ';
        }
        cout << endl;
    }

    return 0;
}

