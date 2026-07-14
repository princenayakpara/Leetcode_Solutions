// Last updated: 14/07/2026, 15:38:06
1class Solution {
2public:
3    int totalFruit(vector<int>& fruits) {
4        unordered_map<int, int> mp;
5        int low = 0, ans = 0;
6
7        for (int high = 0; high < fruits.size(); high++) {
8            mp[fruits[high]]++;
9
10            while (mp.size() > 2) {
11                mp[fruits[low]]--;
12                if (mp[fruits[low]] == 0)
13                    mp.erase(fruits[low]);
14                low++;
15            }
16
17            ans = max(ans, high - low + 1);
18        }
19
20        return ans;
21    }
22};