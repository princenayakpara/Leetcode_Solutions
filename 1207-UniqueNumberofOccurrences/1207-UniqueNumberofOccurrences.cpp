// Last updated: 11/04/2026, 15:18:51
1class Solution {
2public:
3    bool uniqueOccurrences(vector<int>& arr) {
4        unordered_map<int, int> freq;
5
6        // Step 1: Count frequency
7        for (int num : arr) {
8            freq[num]++;
9        }
10
11        // Step 2: Check uniqueness using set
12        unordered_set<int> seen;
13
14        for (auto it : freq) {
15            if (seen.count(it.second)) {
16                return false; 
17            }
18            seen.insert(it.second);
19        }
20
21        return true;
22    }
23};