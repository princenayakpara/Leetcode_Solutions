// Last updated: 10/03/2026, 13:45:23
/**
 * @param {number} columnNumber
 * @return {string}
 */
var convertToTitle = function(columnNumber) {
    let result = "";

    while (columnNumber > 0) {
        columnNumber--; // adjust for no zero
        let rem = columnNumber % 26;
        let char = String.fromCharCode(65 + rem);
        result = char + result;
        columnNumber = Math.floor(columnNumber / 26);
    }

    return result;
};
