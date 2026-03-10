// Last updated: 10/03/2026, 13:45:20
/**
 * @param {string} columnTitle
 * @return {number}
 */
var titleToNumber = function(columnTitle) {
    let result = 0;

    for (let i = 0; i < columnTitle.length; i++) {
        let value = columnTitle.charCodeAt(i) - 64; // 'A' = 65
        result = result * 26 + value;
    }

    return result;
};
