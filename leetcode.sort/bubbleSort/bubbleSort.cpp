#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>

/*
	稳定的排序算法
平均时间复杂度为：O( n^2 )		空间复杂度O(1)
最优时间复杂度为：O( n )		空间复杂度O(1)
*/
void bubbleSort1(vector<int>& nums) {
	int len = nums.size();
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j + 1 < len - i; ++j) {
			if (nums[j] > nums[j + 1])
				swap(nums[j], nums[j + 1]);
		}
	}
}


void bubbleSort2(vector<int>& nums) {

	int len = nums.size();
	bool flag = false;

	for (int i = 0; i < len - 1; ++i) {

		flag = false;
		for (int j = 0; j + 1 < len - i; ++j) {

			if (nums[j] > nums[j + 1])
			{
				swap(nums[j], nums[j + 1]);
				flag = true;
			}
		}
		//若某一趟中一次元素交换都没有，即依然为flag = false
		//那么表明所剩待排序列已经有序，不必再进行趟数比较，外层循环应该结束，跳出循环
		if (!flag)
			break;
	}
}


int main()
{
	vector<int> num = { 8,7,9,6,8,5 };

	//bubbleSort1(num);
	bubbleSort2(num);

	for (auto i : num) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
