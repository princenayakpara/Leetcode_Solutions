// Last updated: 06/06/2026, 21:54:19
1class Solution {
2public:
3    vector<int> leftRightDifference(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> result(n);
6        
7        int totalSum = 0;
8        for(int num : nums) {
9            totalSum += num;
10        }
11        
12        int leftSum = 0;
13        
14        for(int i = 0; i < n; i++) {
15            int rightSum = totalSum - leftSum - nums[i];
16            result[i] = abs(leftSum - rightSum);
17            leftSum += nums[i];
18        }
19        
20        return result;
21    }
22};