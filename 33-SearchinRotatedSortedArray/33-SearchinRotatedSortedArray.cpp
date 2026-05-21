// Last updated: 21/05/2026, 23:50:57
1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        for(int i = 0; i<nums.size(); i++){
5            if(nums[i] == target){
6                return i;
7            }
8        }
9        return -1;
10    }
11};