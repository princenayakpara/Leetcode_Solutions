// Last updated: 10/03/2026, 13:44:57
/**
 * @param {number[]} nums
 * @return {number}
 */
var thirdMax = function(nums) {

    let first = -Infinity;
    let second = -Infinity;
    let third = -Infinity;

    for (let i = 0; i < nums.length; i++) {

        let n = nums[i];

        if (n === first || n === second || n === third) {
            continue;
        }

        if (n > first) {
            third = second;
            second = first;
            first = n;
        } 
        else if (n > second) {
            third = second;
            second = n;
        } 
        else if (n > third) {
            third = n;
        }
    }

    if (third === -Infinity) {
        return first;
    }

    return third;
};
