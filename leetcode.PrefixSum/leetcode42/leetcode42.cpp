using namespace std;
#include <iostream>
#include <vector>


/*
	时间复杂度 O(n)
	空间复杂度 O(n)
*/
int trap(vector<int>& height) {
	int n = height.size();

	// 求前缀最大值
	vector<int> pre_max(n, 0);
	pre_max[0] = height[0];
	for (auto i = 1; i < n; i++)
	{
		// 对当前值和前一个前缀最大值进行判断
		pre_max[i] = max(height[i], pre_max[i - 1]);
	}

	// 求后缀最大值
	vector<int> suf_max(n, 0);
	suf_max[n - 1] = height[n - 1];
	for (auto i = n - 2; i >= 0; i--)
	{
		// 对当前值和后一个后缀最大值进行判断
		suf_max[i] = max(height[i], suf_max[i + 1]);
	}

	int ans = 0;
	// 遍历数组，并统计所有桶内的雨水个数
	for (auto i = 0; i < n; i++)
	{
		int flag = min(pre_max[i], suf_max[i]) - height[i];
		ans += flag;
	}

	return ans;
}


int main()
{
	vector<int> heights = { 0,1,0,2,1,0,1,3,2,1,2,1 };	// 6
	vector<int> heights2 = { 4,2,0,3,2,5 };				// 9
	auto res = trap(heights2);

	cout << res << endl;

	return 0;
}

