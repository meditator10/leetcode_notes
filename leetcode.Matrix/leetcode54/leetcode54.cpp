#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>


vector<int> spiralOrder(vector<vector<int>> matrix) {
    vector<int> ans;
    if (matrix.empty()) return ans; 

    int left = 0;
    int right = matrix[0].size() - 1;
    int up = 0;
    int down = matrix.size() - 1;

    while (true) {
        // 从第一行开始从左向右移动
        for (int i = left; i <= right; i++) {
            ans.push_back(matrix[up][i]);
        }
        up++;       // 一行遍历完，更新up，重新定义上边界
        if (up > down) {
            break;
        }

        // 从最后一列开始从上往下移动
        for (int i = up; i <= down; i++) {
            ans.push_back(matrix[i][right]);
        }
        right--;    // 一列遍历完，更新right，重新定义右边界
        if (right < left) {
            break;
        }
        // 从最后一行开始从右向左移动
        for (int i = right; i >= left; i--) {
            ans.push_back(matrix[down][i]);
        }
        down--;     // 一行遍历完，更新down，重新定义下边界
        if (down < up) {
            break;
        }

        // 从第一列开始从下往上移动
        for (int i = down; i >= up; i--) {
            ans.push_back(matrix[i][left]);
        }
        left++;     // 一列遍历完，更新left，重新定义左边界
        if (left > right) {
            break;
        }
    }
    return ans;
}



int main()
{
    vector<vector<int>> matrix = { {1,2,3} ,{4,5,6}, {7,8,9} };
    auto res = spiralOrder(matrix);
    for (auto it = res.begin(); it != res.end(); it++)
    {
        cout << *it << ' ';
    }

    return 0;
}

