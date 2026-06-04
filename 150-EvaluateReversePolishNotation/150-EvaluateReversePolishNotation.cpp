// Last updated: 04/06/2026, 11:33:43
1class Solution {
2public:
3    int evalRPN(vector<string>& tokens) {
4        stack<int> st;
5
6        for (string token : tokens) {
7
8            if (token == "+" || token == "-" ||
9                token == "*" || token == "/") {
10
11                int b = st.top();
12                st.pop();
13
14                int a = st.top();
15                st.pop();
16
17                if (token == "+")
18                    st.push(a + b);
19                else if (token == "-")
20                    st.push(a - b);
21                else if (token == "*")
22                    st.push(a * b);
23                else
24                    st.push(a / b);
25            }
26            else {
27                st.push(stoi(token));
28            }
29        }
30
31        return st.top();
32    }
33};