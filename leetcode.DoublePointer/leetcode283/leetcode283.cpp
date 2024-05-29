#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void moveZeroes(vector<int>& nums) {
	//第一次遍历，j指针记录非0元素的个数，并赋给nums[j]
	int i = 0;
	int j = 0;
	for (i; i < nums.size(); i++) {
		if (nums[i] != 0) {
			nums[j++] = nums[i];
		}
	}

	//第二次遍历把j之后的所有元素都赋为0
	for (int i = j; i < nums.size(); i++) {
		nums[i] = 0;
	}
}


int main()
{
	vector<int> v = { 0,1,0,3,12 };
	moveZeroes(v);

	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << ' ';
	}

	return 0;
}