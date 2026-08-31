// Last updated: 31/08/2026, 16:53:04
1class Solution {
2public:
3    int removeDuplicates(vector<int>& nums) {
4        int k = 1;
5        for(int j = 1; j<nums.size(); j++){
6            if(nums[j] != nums[j-1]){
7                nums[k] = nums[j];
8                k++;
9            }
10        }
11        return k;
12    }
13};