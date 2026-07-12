// Last updated: 12/07/2026, 18:38:59
1class Solution {
2public:
3    vector<int> arrayRankTransform(vector<int>& arr) {
4        vector<int> temp = arr;
5        sort(temp.begin(), temp.end());
6        
7        unordered_map<int, int> rank;
8        int r = 1;
9        
10        for (int x : temp) {
11            if (rank.find(x) == rank.end()) {
12                rank[x] = r++;
13            }
14        }
15        
16        for (int i = 0; i < arr.size(); i++) {
17            arr[i] = rank[arr[i]];
18        }
19        
20        return arr;
21    }
22};