// Last updated: 12/05/2026, 10:09:27
1class Solution {
2public:
3    int minimumEffort(vector<vector<int>>& tasks) {
4        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
5            return (a[1] - a[0]) > (b[1] - b[0]);
6        });
7
8        int energy = 0, current = 0;
9
10        for (auto& t : tasks) {
11            int actual = t[0];
12            int minimum = t[1];
13
14            if (current < minimum) {
15                energy += (minimum - current);
16                current = minimum;
17            }
18
19            current -= actual;
20        }
21
22        return energy;
23    }
24};