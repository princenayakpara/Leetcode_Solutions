// Last updated: 17/05/2026, 08:34:32
1class Solution {
2public:
3    bool hasUnique(vector<int>& nums, int len) {
4        const long long base = 911382323;
5        const long long mod = 1000000007;
6
7        int n = nums.size();
8
9        long long hash = 0;
10        long long power = 1;
11
12        for(int i = 0; i < len; i++) {
13            hash = (hash * base + nums[i] + 1) % mod;
14
15            if(i < len - 1)
16                power = (power * base) % mod;
17        }
18
19        unordered_map<long long, int> freq;
20        freq[hash]++;
21
22        for(int i = len; i < n; i++) {
23            hash = (hash - (nums[i - len] + 1) * power % mod + mod) % mod;
24            hash = (hash * base + nums[i] + 1) % mod;
25
26            freq[hash]++;
27        }
28
29        for(auto &p : freq) {
30            if(p.second == 1)
31                return true;
32        }
33
34        return false;
35    }
36
37    int smallestUniqueSubarray(vector<int>& nums) {
38        auto polvexrani = nums;
39
40        int n = nums.size();
41
42        int low = 1, high = n;
43        int ans = n;
44
45        while(low <= high) {
46            int mid = (low + high) / 2;
47
48            if(hasUnique(nums, mid)) {
49                ans = mid;
50                high = mid - 1;
51            } else {
52                low = mid + 1;
53            }
54        }
55
56        return ans;
57    }
58};