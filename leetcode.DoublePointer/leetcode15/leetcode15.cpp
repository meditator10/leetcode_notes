#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

vector<vector<int>> threeSum(vector<int>& nums) {
    // 先排序
    sort(nums.begin(), nums.end());

    int length = nums.size();
    vector<vector<int>> ans;

    for (int i = 0; i < length - 2; i++)
    {
        // 题目说答案不能包含重复的三元组，所以当nums[i] == nums[i-1]，就跳过
        int x = nums[i];
        if (i > 0 && x == nums[i-1])
            continue;

        // 优化1：当nums[j]和nums[k]为元素最小值时
        // nums[i] + nums[j] + nums[k] > 0，说明j和k后面的数和都是大于0的，直接break
        if (x + nums[i + 1] + nums[i + 2] > 0)
            break;
        // 优化2：当nums[j]和nums[k]为元素最大值时
        // nums[i] + nums[j] + nums[k] < 0，说明j和k前面的数和都是小于0的，直接枚举下一个i
        if (x + nums[length-2] + nums[length-1] < 0)
            continue;

        // 这里仿照leetcode167，计算两数之和 = 目标值(nums[j]+nums[k] == nums[i])
        int j = i + 1;
        int k = length - 1;
        while (j < k)
        {
            int flag = nums[i] + nums[j] + nums[k];
            if (flag == 0)
            {
                // 将结果存到ans里
                ans.push_back({ x, nums[j], nums[k] });

                // 这里与leetcode167不一样，需要找出所有满足条件的三元组
                // 所以在存储一个后需要 j++ 和 k--
                j++;
                // 与判断i类似，不存在重复的三元组，所以当nums[j] == nums[j-1]，就跳过
                // 这里为啥不像i那样用continue，因为i是在for循环里，会自动++
                // 这里用while，不能用if，当同时有三个数相同时，if只会跳过一次
                while (j < k && nums[j] == nums[j - 1])
                    j++;

                k--;
                // 因为不存在重复的三元组，所以当nums[k] == nums[k+1]，就跳过
                while (k > j && nums[k] == nums[k + 1])
                    k--;
            }
            else if (flag < 0)
                j++;
            else if (flag > 0)
                k--;
        }
    }

    return ans;
}


int main()
{
    vector<int> v = { -2,0,3,-1,4,0,3,4,1,1,1,-3,-5,4,0 };
    auto res = threeSum(v);

    for (auto it = res.begin(); it != res.end(); it++)
    {
        for (auto it2 = it->begin(); it2 != it->end(); it2++)
        {
            cout << *it2 << ' ';
        }
        cout << endl;
    }

    return 0;
}


