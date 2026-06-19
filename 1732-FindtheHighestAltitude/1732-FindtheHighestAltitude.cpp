// Last updated: 19/06/2026, 10:46:01
1class Solution {
2public:
3    int largestAltitude(vector<int>& gain) {
4        int altitude = 0;
5        int maxAltitude = 0;
6
7        for (int g : gain) {
8            altitude += g;
9            maxAltitude = max(maxAltitude, altitude);
10        }
11
12        return maxAltitude;
13    }
14};