#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// 贪心法
vector<vector<int>> merge(vector<vector<int>> intervals) {

    vector<vector<int>> ans;
    if (intervals.size() == 0) return ans; 

    // 先排序
    sort(intervals.begin(), intervals.end());

    // 把第一个位置的区间存进容器中
    ans.push_back(intervals[0]);
    
    for (int i = 1; i < intervals.size(); i++) {
        // 重叠区间合并：上一个区间的右边界 >= 下一个区间的左边界
        if (ans.back()[1] >= intervals[i][0]) {

            // 合并区间：只更新右边界就好，因为经过排序ans.back()的左边界一定是最小值
            ans.back()[1] = std::max(ans.back()[1], intervals[i][1]);
        }
        // 不重叠区间，直接追加到容器中
        else {
            ans.push_back(intervals[i]); // 区间不重叠 
        }
    }
    
    return ans;
}


int main()
{
    vector<vector<int>> a = { {1, 3},{2, 6},{8, 10},{15, 18} };
    for (auto it = a.begin(); it != a.end(); it++)
    {
        for (auto it2 = it->begin(); it2 != it->end(); it2++)
        {
            cout << *it2 << ' ';
        }
        cout << endl;
    }

    cout << "----------------------" << endl;
    auto res = merge(a);
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
