// Last updated: 18/08/2026, 15:21:57
1class Solution {
2public:
3    int minOperations(vector<int>& nums) {
4        int operations = 0;
5        int n = nums.size();
6        for(int i = 1; i<n; i++){
7            if(nums[i]<=nums[i-1]){
8                int need = nums[i-1] + 1 - nums[i];
9                operations += need;
10                nums[i] += need;
11            }
12        }
13        return operations;
14    }
15};