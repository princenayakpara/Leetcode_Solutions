// Last updated: 08/06/2026, 09:29:46
1class Solution {
2public:
3    vector<string> summaryRanges(vector<int>& nums) {
4         vector<string> ans;
5        int n = nums.size();
6
7        for(int i = 0; i<n; i++){
8            int start = nums[i];
9
10          while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
11                i++;
12            }
13
14            int end = nums[i];
15
16            if(start == end){
17                ans.push_back(to_string(start));
18            }else{
19                ans.push_back(to_string(start) + "->" + to_string(end));
20            }
21        }
22        return ans;
23
24    }
25};