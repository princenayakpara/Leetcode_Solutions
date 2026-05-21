// Last updated: 22/05/2026, 00:18:57
1class Solution {
2public:
3    vector<int> singleNumber(vector<int>& nums) {
4       map<int, int>m;
5       vector<int> arr;
6       for(int i=0; i<nums.size(); i++){
7        m[nums[i]]++;
8       }
9       for(auto i : m){
10        if(i.second == 1){
11            arr.push_back(i.first);
12        }
13       }
14       return arr;
15    }
16};