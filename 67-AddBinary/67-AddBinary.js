// Last updated: 10/03/2026, 13:45:31
/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
    let i = a.length - 1;
    let j = b.length - 1;
    let carry = 0;
    let result = "";

    while (i >= 0 || j >= 0 || carry) {
        let bitA = i >= 0 ? Number(a[i]) : 0;
        let bitB = j >= 0 ? Number(b[j]) : 0;

        let sum = bitA + bitB + carry;
        result = (sum % 2) + result;
        carry = Math.floor(sum / 2);

        i--;
        j--;
    }

    return result;
};
