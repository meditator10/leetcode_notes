#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

vector<int> productExceptSelf(vector<int> nums) {
    int n = nums.size();

    // nums[i]的前i-1个乘积
    vector<int> pre(n, 1);
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] * nums[i - 1];
    }

    vector<int> suf(n, 1);
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i + 1] * nums[i + 1];
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = pre[i] * suf[i];
    }
    return ans;
}


int main()
{
    vector<int> v = { 1,2,3,4 };
    auto res = productExceptSelf(v);

    for (auto it = res.begin(); it != res.end(); it++)
    {
        cout << *it << ' ';
    }

    return 0;
}