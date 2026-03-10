// Last updated: 10/03/2026, 13:45:05
/**
 * @param {string} s
 * @return {string}
 */
var reverseVowels = function(s) {
    let arr = s.split('');
    let left = 0;
    let right = arr.length - 1;
    const vowels = new Set(['a','e','i','o','u','A','E','I','O','U']);

            
           while(left < right) { 
            if(!vowels.has(arr[left])) {
            left++;
            } 

            else if(!vowels.has(arr[right])) {
            right--;
            } 

            else{let temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;

            left++;
            right--;
 
            } 

           }
           return arr.join('');

};