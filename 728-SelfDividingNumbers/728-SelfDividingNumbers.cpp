// Last updated: 23/05/2026, 22:45:13
1class Solution {
2public:
3    bool check(int n) {
4        int x = n;
5
6        while(x > 0) {
7            int d = x % 10;
8
9            if(d == 0 || n % d != 0)
10                return false;
11
12            x /= 10;
13        }
14
15        return true;
16    }
17    vector<int> selfDividingNumbers(int left, int right) {
18        vector<int> ans;
19
20        for(int i = left; i <= right; i++) {
21            if(check(i))
22                ans.push_back(i);
23        }
24
25        return ans;
26    }
27};