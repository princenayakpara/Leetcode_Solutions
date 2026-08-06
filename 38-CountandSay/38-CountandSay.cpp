// Last updated: 06/08/2026, 14:58:32
1class Solution {
2public:
3    string countAndSay(int n) {
4        string ans = "1";
5
6        for(int i = 2; i<=n; i++){
7            string temp = "";
8            int count = 1;
9
10            for(int j=1; j<= ans.size(); j++){
11                if(j< ans.size() && ans[j] == ans[j-1]) {
12                    count++;
13                }else{
14                    temp += to_string(count);
15                    temp += ans[j-1];
16                    count = 1;
17                }
18            }
19            ans = temp;
20        }
21        return ans;
22    }
23};