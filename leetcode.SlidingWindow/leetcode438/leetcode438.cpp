#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <unordered_map>


vector<int> findAnagrams1(string s, string p) {
    vector<int> ans;

    // 初始化一个数组来统计字符串 p 中每个字符的出现次数,也可以用hash table
    vector<int> cnt(26, 0);
    for (int i = 0; i < p.size(); i++) {
        cnt[p[i] - 'a']++;
    }

    // l 和 r 分别表示滑动窗口的左右边界
    int l = 0;
    for (int r = 0; r < s.size(); r++) {
        // 统计s字符串里的各字符出现次数，并更新cnt
        cnt[s[r] - 'a']--;
        // 注意循环条件，当出现重复字符时，就移动左指针，从左侧收缩窗口
        while (cnt[s[r] - 'a'] < 0) {
            cnt[s[l] - 'a']++;
            l++;
        }
        // 当窗口长度等于p的长度，就记录左指针值
        if (r - l + 1 == p.size()) {
            ans.push_back(l);
        }
    }
    return ans;
}

vector<int> findAnagrams2(string s, string p) {
    vector<int> ans;

    //记录p串各字符出现次数
    unordered_map<char, int> hashp;
    for (int i = 0; i < p.size(); i++) {
        hashp[p[i]]++;
    }

    int cnt = 0;    // 记录窗口的长度

    int left = 0, right = 0;
    unordered_map<char, int> hashs;
    while (right < s.size()) {
        //记录s串各字符出现次数
        char c = s[right];
        hashs[c]++;
        cnt++;
        right++;
        //如果字符重复，就调整窗口，移动左指针
        while (hashs[c] > hashp[c]) {
            hashs[s[left]]--;
            left++;
            cnt--;
        }
        // 当窗口长度等于p的长度，就记录左指针值
        if (cnt == p.size()) {
            ans.push_back(left);
        }
    }
    return ans;
}


int main()
{
    string s = "cbacbabacd";
    string p = "abc";
    // auto res = findAnagrams1(s, p);
    auto res = findAnagrams2(s, p);
    for (auto it = res.begin(); it != res.end(); it++)
    {
        cout << *it << ' ';
    }

    return 0;
}
