// Last updated: 28/06/2026, 16:50:02
1class Solution {
2public:
3    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
4        sort(arr.begin(), arr.end());
5
6        arr[0] = 1;
7
8        for (int i = 1; i < arr.size(); i++) {
9            arr[i] = min(arr[i], arr[i - 1] + 1);
10        }
11
12        return arr.back();
13    }
14};