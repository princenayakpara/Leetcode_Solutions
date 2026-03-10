// Last updated: 10/03/2026, 13:44:59
/**
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function(s) {
    let freq = {};

    for (let ch of s) {
        freq[ch] = (freq[ch] || 0) + 1;
    }

    for (let i = 0; i < s.length; i++) {
        if (freq[s[i]] === 1) {
            return i;
        }
    }

    return -1;
};
