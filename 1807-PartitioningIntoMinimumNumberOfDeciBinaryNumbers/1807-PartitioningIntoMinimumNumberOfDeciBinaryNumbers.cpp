// Last updated: 10/03/2026, 13:44:41
class Solution {
public:
    int minPartitions(string n) {
        int mx = 0;

        for(char c : n){
            mx = max(mx, c - '0');
        }

        return mx;
    }
};