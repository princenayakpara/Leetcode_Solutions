// Last updated: 17/07/2026, 15:43:07
1class Solution {
2public:
3    int findDuplicate(vector<int>& nums) {
4        set <int> s={};
5        for(int i: nums){
6            if(!s.count(i)) s.insert(i);
7            else return i;
8        }
9        return -1;
10    }
11};