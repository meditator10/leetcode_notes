using namespace std;
#include <iostream>
#include <vector>

class NumArray {
public:
    vector<int> s;

    NumArray(vector<int>& nums) {
        // 定义一个元素个数为n+1的sum用于存储前缀和，sum[0] = 0
        // resize 会添加额外的元素到容器的末尾,并将所有元素初始化为 0
        s.resize(nums.size() + 1);
        for (auto i = 0; i < nums.size(); i++)
        {
            // 注意：s比nums多一位
            s[i + 1] = s[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return s[right + 1] - s[left];
    }
};


int main()
{
    vector<int> v = { -2, 0, 3, -5, 2, -1 };
    NumArray* array = new NumArray(v);
    
    auto res = array->sumRange(0, 2);
    auto res2 = array->sumRange(2, 5);
    auto res3 = array->sumRange(0, 5);
    cout << res << endl;
    cout << res2 << endl;
    cout << res3 << endl;

    return 0;
}

