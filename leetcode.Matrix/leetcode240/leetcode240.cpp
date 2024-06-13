#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

// 利用好matrix是一个有序矩阵这个点
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();        
    int column = matrix[0].size();

    int i = 0, j = column - 1; // 从右上角开始

    while (i < row && j >= 0) { // 还有剩余元素
        if (matrix[i][j] == target) {
            return true; // 找到 target
        }
        if (matrix[i][j] < target) {
            i++; // 这一行剩余元素全部小于 target，排除
        }
        else {
            j--; // 这一列剩余元素全部大于 target，排除
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = { {1,4,7,11,15} ,{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30} };
    auto res = searchMatrix(matrix, 5);
    cout << boolalpha;      // 使用std::boolalpha操纵器后，cout会打印bool类型为true或false
    cout << res << endl;
    
    return 0;
}