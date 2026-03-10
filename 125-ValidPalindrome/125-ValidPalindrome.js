// Last updated: 10/03/2026, 13:45:26
/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    
    let str = s.toLowerCase().replace(/[^a-z0-9]/g,"");

    let left = 0;
    let right = str.length - 1;

    while(left < right){
        if(str[left] !== str[right])
        return false;
        left++;
        right--;
    }
    return true;
};