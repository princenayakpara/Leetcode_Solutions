// Last updated: 01/05/2026, 13:44:58
1class Solution {
2public:
3    int maxRotateFunction(vector<int>& nums) {
4        int n = nums.size();
5        long long sum = 0;
6        long long f0 = 0;
7        
8        // Step 1: Calculate sum and F(0)
9        for (int i = 0; i < n; i++) {
10            sum += nums[i];
11            f0 += (long long)i * nums[i];
12        }
13        
14        long long maxVal = f0;
15        long long prev = f0;
16        
17        // Step 2: Use relation to compute next values
18        for (int k = 1; k < n; k++) {
19            long long curr = prev + sum - (long long)n * nums[n - k];
20            maxVal = max(maxVal, curr);
21            prev = curr;
22        }
23        
24        return maxVal;
25    }
26};