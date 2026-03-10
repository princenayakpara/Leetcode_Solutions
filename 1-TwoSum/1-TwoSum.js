// Last updated: 10/03/2026, 13:45:58
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
     let map = {};  

    for(let i = 0; i < nums.length; i++){
        let need = target - nums[i];

        if(map[need] !== undefined){
            return [ map[need], i ];
        }

        map[nums[i]] = i;
    }
};