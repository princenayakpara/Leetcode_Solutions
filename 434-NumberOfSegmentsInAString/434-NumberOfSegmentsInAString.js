// Last updated: 10/03/2026, 13:44:55
/**
 * @param {string} s
 * @return {number}
 */
var countSegments = function(s) {
    let count = 0;

    for (let i = 0; i < s.length; i++) {
        if (s[i] !== ' ' && (i === 0 || s[i - 1] === ' ')) {
            count++;
        }
    }

    return count;
};
