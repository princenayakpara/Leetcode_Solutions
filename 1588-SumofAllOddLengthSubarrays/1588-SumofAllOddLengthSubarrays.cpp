// Last updated: 28/07/2026, 15:32:07
1class Solution {
2public:
3    int sumOddLengthSubarrays(vector<int>& arr) {
4        int n = arr.size();
5        int ans = 0;
6
7        for (int i = 0; i < n; i++) {
8            int total = (i + 1) * (n - i);
9            int oddCount = (total + 1) / 2;
10            ans += arr[i] * oddCount;
11        }
12
13        return ans;
14    }
15};