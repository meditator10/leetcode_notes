#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

// 不定长滑动窗口(双指针)
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
	// 因为元素都是正整数，所以不存在小于1的数目
	if (k <= 1)
		return 0;

	int ans = 0;
	int p = 1;

	int left = 0;
	// 枚举子数组右端点,往前乘
	for (int right = 0; right < nums.size(); right++) {
		p *= nums[right];
		while (p >= k) {
			// 枚举左端点，往右缩小窗口
			p /= nums[left];
			left++;		// 左端点右移
		}
		// 这里十分巧妙，求[l,r]之间有多少个满足条件的子数组
		// 个数为：[l,r] [l+1,r] ... [r,r]
		ans += right - left + 1;
	}
	return ans;
}



int main()
{
	vector<int> v = { 10,5,2,6 };
	auto res = numSubarrayProductLessThanK(v, 100);
	cout << res << endl;

	return 0;
}
