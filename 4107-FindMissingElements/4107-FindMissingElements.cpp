// Last updated: 10/03/2026, 13:44:42
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        if (nums.empty()) return ans;

        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            int prev = nums[i - 1];
            int curr = nums[i];
            if (curr == prev) continue;

            for (int x = prev + 1; x < curr; x++)
                ans.push_back(x);
        }

        return ans;
    }
};