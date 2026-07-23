// Last updated: 23/07/2026, 15:48:38
1class Solution {
2public:
3    int averageValue(vector<int>& nums) {
4        int count= 0, sum = 0;
5        int n = nums.size();
6        for(int i = 0; i<n; i++){
7            if(nums[i]%2==0 && nums[i]%3==0){
8                count++;
9                sum+=nums[i];
10            }
11        }
12        if(count == 0){
13            return 0;
14        }
15        return sum/count;
16    }
17};