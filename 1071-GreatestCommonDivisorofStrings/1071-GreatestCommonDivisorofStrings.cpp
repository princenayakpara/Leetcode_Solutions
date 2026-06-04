// Last updated: 04/06/2026, 11:15:04
1class Solution {
2public:
3    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
4        int mx = *max_element(candies.begin(), candies.end());
5
6        vector<bool>ans;
7
8        for(int candy : candies){
9            ans.push_back(candy + extraCandies >= mx);
10        }
11
12        return ans;
13    }
14};