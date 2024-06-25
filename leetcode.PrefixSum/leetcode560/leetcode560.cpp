using namespace std;
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// nums是有序的
// 借鉴leetcode 303(前缀和)和1(两数之和)

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    // 定义一个元素个数为n+1的sum用于存储前缀和，sum[0] = 0
    vector<int> s(n + 1);
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + nums[i];
    }

    int ans = 0;
    unordered_map<int, int> cnt;
    /*
        下标从i到j−1的非空连续子数组的元素和等于k，即 s[j]−s[i] = k
        也就是 s[i] = s[j] − k
        此时cnt的key就是si，value就是si出现的次数
    */  
    for (int sj : s) {
        // 注意不要直接 += cnt[sj-k]，如果 sj-k 不存在，map会插入 sj-k
        ans += cnt.count(sj - k) ? cnt[sj - k] : 0;
        cnt[sj]++;
    }
    //for (const auto& pair : cnt) {
    //    // pair.first 是键，pair.second 是值
    //    std::cout << "key: " << pair.first << ", value: " << pair.second << std::endl;
    //}

    return ans;
}


int main()
{
    vector<int> v = { 1, 1, -1, 1 };    // 5
    auto res = subarraySum(v, 1);
    cout << res << endl;
}

