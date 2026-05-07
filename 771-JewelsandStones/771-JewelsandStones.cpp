// Last updated: 07/05/2026, 21:02:42
1class Solution {
2public:
3    int numJewelsInStones(string jewels, string stones) {
4        unordered_set<char> jewelSet(jewels.begin(), jewels.end());
5        int count = 0;
6        for(char c : stones){
7            if(jewelSet.count(c)){
8                count++;
9            }
10        }
11        return count;
12    }
13};