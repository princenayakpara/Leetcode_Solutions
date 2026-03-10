// Last updated: 10/03/2026, 13:45:08
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    let n = nums;
    let write = 0;
    for(let i=0; i<nums.length; i++){
        if(nums[i]!=0){
            nums[write]=nums[i];
            write++;
        }
    }

    for(let i=write; i<nums.length; i++){
        nums[i]=0;
    }
};