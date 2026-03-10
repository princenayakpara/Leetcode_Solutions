// Last updated: 10/03/2026, 13:45:16
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isIsomorphic = function(s, t) {
    if (s.length !== t.length) return false;

    let mapST = {};
    let mapTS = {};

    for (let i = 0; i < s.length; i++) {
        let a = s[i];
        let b = t[i];

        if (mapST[a] && mapST[a] !== b) return false;
        if (mapTS[b] && mapTS[b] !== a) return false;

        mapST[a] = b;
        mapTS[b] = a;
    }

    return true;
};
