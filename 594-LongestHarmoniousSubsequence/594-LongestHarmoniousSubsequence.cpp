// Last updated: 17/07/2026, 14:59:22
1class Solution {
2public:
3    int findLHS(vector<int>& nums) {
4        unordered_map<int, int> freq;
5        
6        // count frequency
7        for (int num : nums) {
8            freq[num]++;
9        }
10        
11        int ans = 0;
12        
13        // check for harmonious pairs
14        for (auto it : freq) {
15            int num = it.first;
16            if (freq.find(num + 1) != freq.end()) {
17                ans = max(ans, it.second + freq[num + 1]);
18            }
19        }
20        
21        return ans;
22    }
23};