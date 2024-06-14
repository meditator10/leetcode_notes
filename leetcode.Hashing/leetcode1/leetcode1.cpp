#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>

// 暴力遍历
vector<int> twoSum1(vector<int> nums, int target) {
	vector<int> ans;
	
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = i+1; j < nums.size(); j++)
		{
			if (nums[i]+nums[j] == target)
			{
				ans.push_back(i);
				ans.push_back(j);
			}
		}
	}
	return ans;
}

// 一遍哈希表
vector<int> twoSum2(vector<int> nums, int target) {
    vector<int> ans;  

    // map存储遍历的元素值，因为要求不重复，把原数组的元素值当key，value存下标
    unordered_map<int, int> a;
    for (int i = 0; i < nums.size(); i++)
        a.insert(map<int, int>::value_type(nums[i], i));

    // 再次遍历nums，并从map中寻找 == target - nums[i] 的key所对应的value
    for (int i = 0; i < nums.size(); i++)
    {
        int s = target - nums[i];
        // 使用 count() 检查key是否存在，且同一个元素下标不能重复出现
        if (a.count(s) > 0 && (a[s] != i))
        {
            ans.push_back(i);                     // nums元素本身下标
            ans.push_back(a[target - nums[i]]);   // key所对应的value
            break;
        }
    }
    return ans;
}


int main()
{
    vector<int> v = { 2,7,11,15 };
    //auto res = twoSum1(v, 9);
    auto res = twoSum2(v, 9);
    for (auto it = res.begin(); it != res.end(); it++)
    {
        cout << *it << ' ';
    }

    return 0;
}
