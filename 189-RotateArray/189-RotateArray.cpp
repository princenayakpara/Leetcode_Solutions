// Last updated: 10/03/2026, 13:45:19
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.end());          
        reverse(nums.begin(), nums.begin() + k);    
        reverse(nums.begin() + k, nums.end());    
    }
};