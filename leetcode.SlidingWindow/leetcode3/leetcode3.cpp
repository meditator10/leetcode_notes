#include <iostream>
using namespace std;
#include <algorithm>
#include <unordered_set>

int lengthOfLongestSubstring(string s) {
	int ans = 0;
	unordered_set<char> window; // 维护从下标 left 到下标 right 的字符

	int left = 0;
	for (int right = 0; right < s.size(); right++) {
		char c = s[right];
		// 如果窗口内已经包含c，那么再加入一个 c 必然会导致窗口内有重复元素
		// 所以要在加入 c 之前，先移出窗口内的 c
		while (window.count(c)) { 
			window.erase(s[left]); 
			left++;		// 往右缩小窗口
		}
		// 将此时的c加入到窗口中
		window.insert(c); 
		// 更新窗口长度最大值
		ans = max(ans, right - left + 1); 
	}
	return ans;
}


int main()
{
	string s = "abcabcbb";
	auto res = lengthOfLongestSubstring(s);

	cout << res << endl;

	return 0;
}