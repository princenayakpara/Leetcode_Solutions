// Last updated: 10/03/2026, 13:45:02
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
    let set1 = new Set(nums1);
    let result = new Set();

    for(let i=0; i<nums2.length; i++){
        if(set1.has(nums2[i])){
            result.add(nums2[i]);
        }
    
    }
    return [...result];
};