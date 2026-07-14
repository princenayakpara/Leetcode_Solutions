// Last updated: 14/07/2026, 15:38:41
1class Solution {
2public:
3    int totalFruit(vector<int>& fruits) {
4        unordered_map<int, int> mp;
5        int n = fruits.size();
6        int low = 0, ans = 0;
7
8        for (int high = 0; high < n; high++) {
9            mp[fruits[high]]++;
10
11            while (mp.size() > 2) {
12                mp[fruits[low]]--;
13                if (mp[fruits[low]] == 0)
14                    mp.erase(fruits[low]);
15                low++;
16            }
17
18            ans = max(ans, high - low + 1);
19        }
20
21        return ans;
22    }
23};