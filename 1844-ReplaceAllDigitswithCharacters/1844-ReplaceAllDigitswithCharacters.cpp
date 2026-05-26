// Last updated: 26/05/2026, 18:26:55
1class Solution {
2public:
3    string reversePrefix(string word, char ch) {
4        int idx = word.find(ch);
5        if(idx != string::npos){
6            reverse(word.begin(), word.begin() + idx + 1);
7        }
8        return word;
9    }
10};