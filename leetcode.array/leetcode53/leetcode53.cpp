using namespace std;
#include <vector>
#include <iostream>

// 暴力解法
int maxSubArray1(vector<int> nums) {
	//类似寻找 最大or最小值 的题目，初始值一定要定义成理论上的 最小or最大值
	int max = INT_MIN;
	int length = nums.size();
	for (int i = 0; i < length; i++)	// 设置起始位置
	{
		int sum = 0;
		for (int j = i; j < length; j++)// 每次从起始位置i开始遍历
		{
			sum += nums[j];
			max = std::max(max, sum);
		}
	}

	return max;
}

// 去除负数的暴力解法（贪心法）
int maxSubArray2(vector<int> nums)
{
	//类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
	int max = INT_MIN;
	int length = nums.size();
	int sum = 0;
	for (int i = 0; i < length; i++)
	{
		sum += nums[i];
		max = std::max(max, sum);
		// 只要"连续和"为正数我们就保留
		// 如果sum < 0 立刻放弃，重新开始找子序串
		if (sum < 0)
		{
			sum = 0;
		}
	}

	return max;
}


int main()
{
	auto num1 = { -2,1,-3,4,-1,2,1,-8,4 };
	auto num2 = { -2,-1,-2,-1 };

	//auto res = maxSubArray1(num);
	//auto res = maxSubArray2(num1);
	auto res = maxSubArray2(num2);
	cout << res << endl;
	return 0;
}