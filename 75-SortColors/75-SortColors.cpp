// Last updated: 29/07/2026, 14:53:39
1class Solution {
2public:
3    void sortColors(vector<int>& nums) {
4       int zero = 0;
5       int one = 0;
6       int two = 0;
7
8        for(int i = 0; i<nums.size(); i++){
9            if(nums[i]==0) zero++;
10            else if(nums[i]==1) one++;
11            else 
12            two++;
13        }
14        for(int i = 0; i<zero; i++) nums[i] = 0;
15        for(int i=zero; i<zero + one; i++) nums[i] = 1;
16        for(int i = zero + one; i<nums.size(); i++) nums[i] = 2;
17        
18    }
19};