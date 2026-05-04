// Last updated: 05/05/2026, 01:06:45
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * Reverses the prefix of the word up to the first occurrence of 'ch'.
     * Time Complexity: O(N)
     * Space Complexity: O(1) auxiliary
     */
    string reversePrefix(string word, char ch) {
        // Find the index of the first occurrence of 'ch'
        size_t index = word.find(ch);
        
        // If the character is found, reverse the segment in-place
        if (index != string::npos) {
            reverse(word.begin(), word.begin() + index + 1);
        }
        
        return word;
    }
};