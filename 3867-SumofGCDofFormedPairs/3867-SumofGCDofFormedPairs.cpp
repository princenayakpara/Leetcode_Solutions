// Last updated: 16/07/2026, 22:25:16
1class Solution {
2public:
3    long long gcdSum(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> prefixGcd(n);
6
7        int mx = 0;
8        for (int i = 0; i < n; i++) {
9            mx = max(mx, nums[i]);
10            prefixGcd[i] = gcd(nums[i], mx);
11        }
12
13        sort(prefixGcd.begin(), prefixGcd.end());
14
15        long long ans = 0;
16        int left = 0, right = n - 1;
17
18        while (left < right) {
19            ans += gcd(prefixGcd[left], prefixGcd[right]);
20            left++;
21            right--;
22        }
23
24        return ans;
25    }
26};