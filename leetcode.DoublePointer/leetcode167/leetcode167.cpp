#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// tip:这个nums是个有序数组，所以可以用这种方法，对于无序数组需要先排序
vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> ans;
	int left = 0;
	int right = nums.size() - 1;

	while (left < right) {
		int flag = nums[left] + nums[right];
		if (flag == target)
		{
			ans.push_back(left);
			ans.push_back(right);
			break;
		}
		else if (flag < target)
			left++;
		else if (flag > target)
			right--;
	}
	return ans;
}


int main()
{
	vector<int> v = { 2,7,11,15 };
	auto res = twoSum(v, 9);

	for (auto it = res.begin(); it != res.end(); it++)
	{
		cout << *it << ' ';
	}

	return 0;
}

