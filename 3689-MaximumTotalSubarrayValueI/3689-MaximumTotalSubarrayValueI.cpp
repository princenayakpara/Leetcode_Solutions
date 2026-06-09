// Last updated: 09/06/2026, 09:33:03
1class Solution {
2public:
3    long long maxTotalValue(vector<int>& nums, int k) {
4        long long mx = *max_element(nums.begin(), nums.end());
5        long long mn = *min_element(nums.begin(), nums.end());
6
7        return 1LL * k * (mx - mn);
8    }
9};