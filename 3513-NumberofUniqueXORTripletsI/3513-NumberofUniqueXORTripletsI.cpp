// Last updated: 23/07/2026, 09:58:48
1class Solution {
2public:
3    int uniqueXorTriplets(vector<int>& nums) {
4        int n = nums.size();
5
6        if (n < 3)
7            return n;
8
9        int ans = 1;
10        while (ans <= n)
11            ans <<= 1;
12
13        return ans;
14    }
15};