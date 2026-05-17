// Last updated: 17/05/2026, 08:17:32
1class Solution {
2public:
3    long long kthPower(long long x, int k, long long limit) {
4        long long res = 1;
5
6        for(int i = 0; i < k; i++) {
7            if(x != 0 && res > limit / x)
8                return limit + 1;
9            res *= x;
10        }
11
12        return res;
13    }
14
15    int countKthRoots(int l, int r, int k) {
16        long long low = 0, high = 1e9;
17
18        long long left = -1;
19        while(low <= high) {
20            long long mid = (low + high) / 2;
21
22            if(kthPower(mid, k, r) >= l) {
23                left = mid;
24                high = mid - 1;
25            } else {
26                low = mid + 1;
27            }
28        }
29
30        low = 0, high = 1e9;
31
32        long long right = -1;
33        while(low <= high) {
34            long long mid = (low + high) / 2;
35
36            if(kthPower(mid, k, r) <= r) {
37                right = mid;
38                low = mid + 1;
39            } else {
40                high = mid - 1;
41            }
42        }
43
44        if(left == -1 || right == -1 || left > right)
45            return 0;
46
47        return right - left + 1;
48    }
49};