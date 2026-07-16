// Last updated: 16/07/2026, 15:32:37
1class Solution {
2public:
3    int maxArea(vector<int>& height) {
4        int ans = 0;
5        int left = 0;
6        int right = height.size() - 1;
7
8        while (left < right) {
9            int area = (right - left) * min(height[left], height[right]);
10            ans = max(ans, area);
11
12            if (height[left] < height[right]) {
13                left++;
14            } else {
15                right--;
16            }
17        }
18
19        return ans;
20    }
21};