// Last updated: 03/05/2026, 10:17:34
1class Solution {
2public:
3    string interpret(string command) {
4        string result = "";
5         for(int i=0; i<command.length(); i++){
6            if(command[i] == 'G'){
7                result += "G";
8            }
9            else if(command[i] == '('){
10                if(command[i+1] == ')'){
11                    result += "o";
12                }
13                else{
14                    result += "al";
15                }
16            }
17         }
18         return result;
19    }
20};