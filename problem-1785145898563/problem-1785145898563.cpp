// Last updated: 27/07/2026, 15:21:38
1class Solution {
2public:
3    int maxProduct(vector<int>& nums) {
4        int max = 0;
5        for(int i =0; i<nums.size();i++){
6            for(int j =i+1; j<nums.size();j++){
7                if((nums[i]-1)*(nums[j]-1)>max){
8                    max = (nums[i]-1) * (nums[j]-1);
9                }
10            }
11        }
12        return max;
13    }
14};