// Last updated: 16/05/2026, 23:52:41
1class Solution {
2public:
3    string intToRoman(int num) {
4        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
5        vector<string> romans = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
6        
7        string result = "";
8        
9        for (int i = 0; i < values.size(); i++) {
10            while (num >= values[i]) {
11                result += romans[i];
12                num -= values[i];
13            }
14        }
15        
16        return result;
17    }
18};