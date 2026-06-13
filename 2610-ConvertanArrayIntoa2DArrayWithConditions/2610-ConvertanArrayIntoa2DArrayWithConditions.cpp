// Last updated: 13/06/2026, 14:15:54
1class Solution {
2public:
3    vector<vector<int>> findMatrix(vector<int>& nums) {
4        unordered_map<int, int> freq;
5        vector<vector<int>> ans;
6
7        for(int num: nums){
8            int row = freq[num];
9        
10        if(row==ans.size()){
11            ans.push_back({});
12        }
13
14        ans[row].push_back(num);
15        freq[num]++;
16        }
17        return ans;
18    }
19};