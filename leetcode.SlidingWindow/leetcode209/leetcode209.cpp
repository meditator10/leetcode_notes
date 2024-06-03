#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

// 暴力遍历(超时)
int minSubArrayLen1(int target, vector<int>& nums) {
	int length = nums.size();
	int ans = INT_MAX;

	for (int i = 0; i < length; i++)
	{
		int sum = 0;
		for (int j = i; j < length; j++)
		{
			sum += nums[i];
			if (sum >= target)
			{
				ans = min(ans, j - i + 1);
				break;
			}
		}
	}

	return ans < INT_MAX ? ans : 0;
	//if (ans < INT_MAX)
	//	return ans;
	//else
	//	return 0;
}

// 不定长滑动窗口(双指针)
int minSubArrayLen2(int target, vector<int>& nums) {
	
	int ans = INT_MAX;
	int sum = 0;
	
	int left = 0;
	// 枚举子数组右端点,往前加
	for (int right = 0; right < nums.size(); right++) {
		sum += nums[right];
		while (sum >= target) { 
			// 记得先将上次结果保留
			ans = min(ans, right - left + 1);
			// 枚举左端点，往右缩小窗口
			sum -= nums[left]; 
			left++;		// 左端点右移
		}
	}
	return ans < INT_MAX ? ans : 0;
}

int main()
{
	vector<int> v = { 2,3,1,2,4,3 };

	auto res = minSubArrayLen2(7, v);
	cout << res << endl;
    
	return 0;
}

