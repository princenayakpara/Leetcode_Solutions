// Last updated: 21/07/2026, 15:21:41
1class Solution {
2public:
3    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
4        int sum = 0;
5        for (int i = 0; i < k; i++) {
6            sum += arr[i];
7        }
8        int count = 0;
9        if (sum >= threshold * k)
10            count++;
11        for (int i = k; i < arr.size(); i++) {
12            sum += arr[i];
13            sum -= arr[i - k];
14            if (sum >= threshold * k)
15                count++;
16        }
17        return count;
18    }
19};