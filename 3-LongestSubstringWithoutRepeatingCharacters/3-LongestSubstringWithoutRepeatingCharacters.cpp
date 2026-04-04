// Last updated: 04/04/2026, 21:55:29
1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        unordered_map<char, int> mp;
5        int left = 0, maxLen = 0;
6
7        for (int right = 0; right < s.size(); right++) {
8            if (mp.find(s[right]) != mp.end()) {
9                left = max(left, mp[s[right]] + 1);
10            }
11            mp[s[right]] = right;
12            maxLen = max(maxLen, right - left + 1);
13        }
14
15        return maxLen;
16    }
17};