// Last updated: 11/05/2026, 09:58:50
1class Solution {
2public:
3    int firstBadVersion(int n) {
4        int left = 1, right = n;
5
6        while (left < right) {
7            int mid = left + (right - left) / 2;
8
9            if (isBadVersion(mid)) {
10                right = mid;   // first bad could be mid
11            } else {
12                left = mid + 1;
13            }
14        }
15
16        return left;
17    }
18};