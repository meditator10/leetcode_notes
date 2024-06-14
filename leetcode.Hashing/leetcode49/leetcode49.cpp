#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <unordered_map>


vector<vector<string>> groupAnagrams(vector<string> strs) {

    vector<vector<string>> ans;

    // 先将strs里的各子串排序，当且仅当两个排序子串相同时(个数和位置)，这两个原字符串才能分到同一组
    // 用哈希表来分组，把排序后的字符串当作 key，原字符串组成的列表当作 value
    unordered_map<string, vector<string>> map;

    for (string& str : strs) {
        string key = str;
        /* 将字符串排序后便于统一作为键 */
        sort(key.begin(), key.end());
        /* 将相同键值的字符串分到一组 */
        map[key].push_back(str);
    }
    /* 取出相同键值的vector<string>放入到ans中 */
    for (auto it = map.begin(); it != map.end(); ++it)
        ans.push_back(it->second);

    return ans;
}


int main()
{
    vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
    auto res = groupAnagrams(strs);
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
