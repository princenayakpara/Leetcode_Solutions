// Last updated: 10/03/2026, 13:44:58
/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function(s, t) {
    let freq = {};

    for (let ch of s) {
    freq[ch] = (freq[ch] || 0) + 1;
}

     for (let ch of t) {
        if (!freq[ch]) {
            return ch;
        }
        freq[ch]--;
    }
};