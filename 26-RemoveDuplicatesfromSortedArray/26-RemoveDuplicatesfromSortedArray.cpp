// Last updated: 29/08/2026, 10:06:29
1class Solution {
2public:
3    int removeDuplicates(vector<int>& nums) {
4        set<int> st;
5        int n = nums.size();
6        for(int i =0; i<n; i++){
7            st.insert(nums[i]);
8        }
9        int index = 0;
10        for(auto it: st){
11            nums[index] = it;
12            index++;
13        }
14        return index;
15    }
16};