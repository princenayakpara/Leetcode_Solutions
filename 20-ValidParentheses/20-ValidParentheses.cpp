// Last updated: 10/03/2026, 13:45:46
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(char c : s) {
            
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {
               
                if(st.empty()) return false;
                
                char top = st.top();
                st.pop();
                
                if((c == ')' && top != '(') ||
                   (c == '}' && top != '{') ||
                   (c == ']' && top != '[')) {
                    return false;
                }
            }
        }
        
        return st.empty();  
    }
};