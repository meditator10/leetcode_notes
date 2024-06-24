#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>

void insertSort(vector<int>& num) {
	int len = num.size();

	for (int i = 1; i < len; i++)
	{
		// 记录要插入的数据
		int temp = num[i];

		// 若第i个元素大于i-1元素，不需要变化。小于的话，移动有序表后插入
		int j = i;
		while (j > 0 && temp < num[j - 1])	//从已经排序的序列最右边的开始比较，num[j - 1]是要插入数据的前一个元素
		{
			num[j] = num[j - 1];			//将前面有序子数列往后挪，找到被插元素的下标记录为j
			j--;
		}

		// 如果j != i  那么被插元素一定小于前面有序表的某些元素
		if (j != i) {
			num[j] = temp;
		}
	}
}


int main()
{
	vector<int> num = { 8,7,9,6,8,5 };

	insertSort(num);

	for (auto i : num) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
