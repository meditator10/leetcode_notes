#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>

/*
	不稳定的排序算法
平均时间复杂度为：O( n^2 )		空间复杂度O(1)
最优时间复杂度为：O( n^2 )		空间复杂度O(1)
*/
void selectSort(vector<int>& num) {
	int minIndex = 0;

	for (int i = 0; i < num.size(); i++) {
		minIndex = i;
		for (int j = i + 1; j < num.size(); j++)
		{
			if (num[j] < num[minIndex])
				minIndex = j;			//遍历完之后，将最小元素的下标记录下来
		}
		swap(num[i], num[minIndex]);	//交换当前位置的元素为最小值
	}
}


int main()
{
	vector<int> num = { 8,7,9,6,8,5 };

	selectSort(num);

	for (auto i : num) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
