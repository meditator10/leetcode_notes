#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int maxArea(vector<int> height) {
    int ans = 0;
    int left = 0;
    int right = height.size() - 1;

    while (left < right) {
        // 容器体积取决于最短板长度（木桶原理）
        int area = (right - left) * min(height[left], height[right]);
        ans = max(ans, area);

        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return ans;
}


int main()
{
    vector<int> areaH = { 1,8,6,2,5,4,8,3,7 };

    auto max = maxArea(areaH);
    cout << max << endl;

    return 0;
}
