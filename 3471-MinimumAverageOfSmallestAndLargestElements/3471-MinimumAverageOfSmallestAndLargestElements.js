// Last updated: 10/03/2026, 13:44:45
/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumAverage = function(nums) {
        nums.sort((a, b) => a - b);

    let i = 0;
    let j = nums.length - 1;
    let ans = Infinity;

    while (i < j) {
        let avg = (nums[i] + nums[j]) / 2;
        ans = Math.min(ans, avg);
        i++;
        j--;
    }

    return ans;
};