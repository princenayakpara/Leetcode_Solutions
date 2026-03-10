// Last updated: 10/03/2026, 13:45:11
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if (s.length !== t.length) return false;

    let freq = {};

    for (let ch of s) {
        freq[ch] = (freq[ch] || 0) + 1;
    }

    for (let ch of t) {
        if (!freq[ch]) return false;
        freq[ch]--;
    }

    return true; 
};