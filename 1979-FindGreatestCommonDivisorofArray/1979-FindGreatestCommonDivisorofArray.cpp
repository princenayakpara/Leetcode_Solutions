// Last updated: 18/07/2026, 10:41:08
1class Solution {
2public:
3    int findGCD(vector<int>& nums) {
4        int mn = *min_element(nums.begin(), nums.end());
5        int mx = *max_element(nums.begin(), nums.end());
6
7        return gcd(mn, mx);   // __gcd(mn, mx) also works
8    }
9};