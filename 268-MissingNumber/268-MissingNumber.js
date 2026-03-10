// Last updated: 10/03/2026, 13:45:10
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    let n = nums.length;
    let expected_sum = n * (n+1)/2;
    let actual_sum = 0;
    for(let i=0; i<nums.length; i++){
        actual_sum=actual_sum + nums[i];
           }
    
    let missing = expected_sum - actual_sum;
    return missing;
};