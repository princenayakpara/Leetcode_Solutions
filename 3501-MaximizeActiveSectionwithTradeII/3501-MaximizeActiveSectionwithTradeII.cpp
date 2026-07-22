// Last updated: 22/07/2026, 19:07:56
1const int K = 17, MAXN = 1e5;
2int st[K + 1][MAXN];
3
4void build(auto& array) {
5	copy(array.begin(), array.end(), st[0]);
6
7	for(int i = 1; i <= K; i++)
8	    for(int j = 0; j + (1 << i) <= array.size(); j++)
9	        st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
10}
11
12int query(int L, int R) {
13	int i = bit_width(unsigned(R - L + 1)) - 1;
14	return max(st[i][L], st[i][R - (1 << i) + 1]);
15}
16
17class Solution {
18public:
19    vector<int> maxActiveSectionsAfterTrade(const string& s, vector<vector<int>>& queries) {
20        int n = s.size(), active = 0;
21        vector<pair<int, int>> zero;
22        vector<int> index(n);
23        for(int i = 0; i < n; i++) {
24        	if(s[i] == '0') {
25        		if(i > 0 && s[i - 1] == '0') zero.back().second++;
26        		else zero.push_back({i, 1});
27        	}else {
28        		active++;
29        	}
30        	index[i] = int(zero.size()) - 1;
31        }
32        if(zero.empty()) return vector<int>(queries.size(), active);
33        
34        vector<int> gains(zero.size() - 1);
35        for(int i = zero.size() - 2; i >= 0; i--) {
36        	gains[i] = zero[i].second + zero[i + 1].second;
37        }
38        build(gains);
39
40        vector<int> res(queries.size(), active);
41        for(int i = 0, sz = queries.size(); i < queries.size(); i++) {
42        	int L = queries[i][0], R = queries[i][1];
43        	int start = index[L] + 1, end = index[R] - (s[R] == '0');
44        	int cnt_left = index[L] == -1 ? -1 : (zero[index[L]].second - (L - zero[index[L]].first));
45    		int cnt_right = index[R] == -1 ? -1 : (R - zero[index[R]].first + 1);
46
47        	if(start < end)
48    			res[i] = max(res[i], active + query(start, end - 1));
49    		if(s[L] == '0' && s[R] == '0' && index[L] + 1 == index[R])
50    			res[i] = max(res[i], active + cnt_left + cnt_right);
51            if(s[L] == '0' && index[L] + 1 < index[R] + (s[R] == '1'))
52                res[i] = max(res[i], active + cnt_left + zero[index[L] + 1].second);
53            if(s[R] == '0' && index[L] < index[R] - 1)
54                res[i] = max(res[i], active + cnt_right + zero[index[R] - 1].second);
55        }
56        return res;
57    }
58};