#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>


// 顺时针旋转90° == 先将矩阵A转置，再左右翻转 
void rotate(vector<vector<int>>&matrix) {
	int n = matrix.size();
	// First step: Transpose the matrix
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			swap(matrix[i][j], matrix[j][i]);
		}
	}

	// Second step: Reverse each row
	for (int i = 0; i < n; ++i) {
		reverse(matrix[i].begin(), matrix[i].end());
	}

	/* 推导：逆时针旋转90° == 先将矩阵A转置，再上下翻转
	for (int j = 0; j < n; ++j) {
		for (int i = 0; i < n / 2; ++i) {
			swap(matrix[i][j], matrix[n - i - 1][j]);
		}
	}
	*/
}


int main()
{
	vector<vector<int>> matrix = { {1,2,3}, {4,5,6}, {7,8,9} };
	vector<vector<int>> matrix2 = { {5,1,9,11} , {2,4,8,10}, {13,3,6,7}, {15,14,12,16} };

	rotate(matrix2);

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

