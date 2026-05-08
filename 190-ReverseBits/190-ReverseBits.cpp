// Last updated: 08/05/2026, 22:36:55
1class Solution {
2public:
3    string addBinary(string a, string b) {
4        string ans = "";
5        int i = a.size() - 1;
6        int j = b.size() - 1;
7        int carry = 0;
8
9        while(i >= 0 || j >= 0 || carry) {
10            int sum = carry;
11
12            if(i >= 0) sum += a[i--] - '0';
13            if(j >= 0) sum += b[j--] - '0';
14
15            ans += (sum % 2) + '0';
16            carry = sum / 2;
17        }
18
19        reverse(ans.begin(), ans.end());
20        return ans;
21    }
22};
23