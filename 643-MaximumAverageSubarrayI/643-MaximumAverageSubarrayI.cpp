// Last updated: 21/07/2026, 15:12:03
1class Solution {
2public:
3    double findMaxAverage(vector<int>& nums, int k) {
4        int low = 0, high = k - 1;
5        double sum = 0;
6
7        for (int i = low; i <= high; i++) {
8            sum += nums[i];
9        }
10        double maxEle = sum / k;
11        low++;
12        high++;
13        while (high < nums.size()) {
14            sum -= nums[low - 1];
15            sum += nums[high];
16            double avg = sum / k;
17            maxEle = max(maxEle, avg);
18            low++;
19            high++;
20        }
21        return maxEle;
22    }
23};