// Last updated: 10/03/2026, 13:45:00
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
    let map = {};
    let result = [];

    for (let i = 0; i < nums1.length; i++) {
        let v = nums1[i];
        map[v] = (map[v] || 0) + 1;
    }

    for (let i = 0; i < nums2.length; i++) {
        let v = nums2[i];
        if (map[v] > 0) {
            result.push(v);
            map[v]--;
        }
    }

    return result;
};
