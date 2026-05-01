// Last updated: 01/05/2026, 16:53:34
1class Solution {
2public:
3    int numJewelsInStones(string jewels, string stones) {
4        unordered_set<char> jewelSet(jewels.begin(), jewels.end());
5        int count = 0;
6
7        for (char c : stones) {
8            if (jewelSet.count(c)) {
9                count++;
10            }
11        }
12
13        return count;
14    }
15};
16