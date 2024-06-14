#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <unordered_set>

// 找出数字连续的最长序列（不要求序列元素在原数组中连续）,所以先排序nums
// 时间复杂度O(nlogn)
int longestConsecutive1(vector<int>& nums) {
	if (nums.empty()) return 0;

	sort(nums.begin(), nums.end());
	int ans = 0, k = 1;
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] == nums[i - 1] + 1) {
			k++;
		}
		else if (nums[i] == nums[i - 1]) continue; // 跳过重复元素
		else {
			// 当序列不连续，且没有重复元素，就记录当前最长序列后更新k
			ans = max(ans, k);
			k = 1;	
		}
	}
	// 别忘了更新ans
	ans = max(ans, k);
	return ans;
}


/*
	将nums存到hash_set里面去，通过find/count来查找
	注意这里使用的是unordered_set，因为它的时间复杂度是O(1)的，set时间复杂度是O(logn)
*/
int longestConsecutive2(vector<int>& nums) {
	unordered_set<int> s(nums.begin(), nums.end());

	int ans = 0;
	// for (int i = 0; i < nums.size(); i++)
	for (int i : nums)
	{
		// 使用 count() 检查序列是否连续
		// 当s.count(i - 1)不存在时，说明序列不连续，此时i作为子序列的左边界，往后遍历
		if (!s.count(i - 1)) {
			int k = 0;
			// 当i存在，记录长度k，当i不存在，退出循环
			while (s.count(i))
			{
				k++;
				i++;
			}
			ans = max(ans, k);
		}
	}
	return ans;
}


int main()
{
	vector<int> v = { 100,4,200,1,3,2 };
	vector<int> v2 = { 0,3,7,2,5,8,4,6,0,1 };
	vector<int> v3 = { 9,1,4,7,3,-1,0,5,8,-1,6 };
	auto res = longestConsecutive2(v);
	cout << res << endl;

	return 0;
}

