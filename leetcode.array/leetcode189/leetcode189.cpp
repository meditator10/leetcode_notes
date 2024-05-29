#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void rotate(vector<int>& nums, int k) {

    // 容易忽视的点：k的值可能大于nums数组长度导致无意义的旋转，故可以 k % length
    int n = nums.size();
    k %= n; // 轮转 k 次等于轮转 k%n 次

    reverse(nums.begin(), nums.end());          // 将整个数组反转
    reverse(nums.begin(), nums.begin() + k);    // 将前k个元素翻转
    reverse(nums.begin() + k, nums.end());      // 将k之后的所有元素再翻转
}


int main()
{
    vector<int> v1 = { 1,2,3,4,5,6,7 };
    vector<int> v2 = { -1,-100,3,99 };

    rotate(v1, 3);  // 操作同一块内存，传引用
    rotate(v2, 2);   

    for (auto it = v2.begin(); it != v2.end(); it++)
    {
        cout << *it << ' ';
    }


    return 0;
}
