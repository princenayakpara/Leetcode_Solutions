// Last updated: 13/06/2026, 13:48:17
1class Solution {
2public:
3    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
4        vector<int> freq(101,0);
5        for(int num:nums)
6        freq[num]++;
7        for(int i=1;i<101;i++)
8        freq[i]+=freq[i-1];
9        vector<int> ans;
10        for(int num:nums)
11        ans.push_back(num==0? 0:freq[num-1]);
12        return ans;
13    }
14};