// Last updated: 02/05/2026, 15:59:46
1class Solution {
2public:
3    int rotatedDigits(int n) {
4        int count = 0;
5
6        for (int i = 1; i <= n; i++) {
7            int num = i;
8            bool isValid = true;
9            bool isDifferent = false;
10
11            while (num > 0) {
12                int digit = num % 10;
13
14                // Invalid digits
15                if (digit == 3 || digit == 4 || digit == 7) {
16                    isValid = false;
17                    break;
18                }
19
20                // Digits that change after rotation
21                if (digit == 2 || digit == 5 || digit == 6 || digit == 9) {
22                    isDifferent = true;
23                }
24
25                num /= 10;
26            }
27
28            if (isValid && isDifferent) {
29                count++;
30            }
31        }
32
33        return count;
34    }
35};