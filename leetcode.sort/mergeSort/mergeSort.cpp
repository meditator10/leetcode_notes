#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>

void mergeSort(vector<int>& num, int begin, int end) {
	if (begin >= end)
		return;

	int mid = (begin + end) / 2;
	mergeSort(num, begin, mid);		//先递归得到最小左子序列，进行排序
	mergeSort(num, mid + 1, end);	//先递归得到最小右子序列，进行排序

	static vector<int> temp;		//static定义的temp看成全局变量
	temp.clear();

	//归并操作
	int i = begin, j = mid + 1;
	while (i <= mid && j <= end)			//当i和j都没有超过各自的序列size时，比较左右序列的元素大小分别放入temp中
	{										//当其中一个下标已经越界后，另一个序列就不需要比了，直接抄到temp中
		if (num[i] <= num[j])
			temp.push_back(num[i++]);		//a：左 < 右，把左边的元素放到temp中
		else
			temp.push_back(num[j++]);		//b：左 > 右，把右边的元素放到temp中
	}
	while (i <= mid)
		temp.push_back(num[i++]);			//b：把左边剩下的元素直接抄到temp中
	while (j <= end)
		temp.push_back(num[j++]);			//a：把右边剩下的元素直接抄到temp中

	//将合并好的有序数列还回去
	for (i = begin, j = 0; j < (int)temp.size(); i++, j++)
		num[i] = temp[j];
}


int main()
{
	vector<int> num = { 8,7,9,6,8,5 };

	mergeSort(num, 0, num.size() - 1);

	for (auto i : num) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}

