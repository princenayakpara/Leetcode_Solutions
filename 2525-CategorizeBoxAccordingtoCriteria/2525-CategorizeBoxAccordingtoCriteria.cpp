// Last updated: 19/05/2026, 10:56:01
1class Solution {
2public:
3    string categorizeBox(int length, int width, int height, int mass) {
4        bool bulky = false;
5        bool heavy = false;
6
7        long long volume = 1LL * length * width * height;
8
9        if (length >= 10000 || width >= 10000 || height >= 10000 || volume >= 1000000000) {
10            bulky = true;
11        }
12
13        if (mass >= 100) {
14            heavy = true;
15        }
16
17        if (bulky && heavy) {
18            return "Both";
19        }
20        else if (!bulky && !heavy) {
21            return "Neither";
22        }
23        else if (bulky) {
24            return "Bulky";
25        }
26
27        return "Heavy";
28    }
29};