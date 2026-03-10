// Last updated: 10/03/2026, 13:44:53
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    let words = s.split(" ");

    for (let i = 0; i < words.length; i++) {
        let arr = words[i].split('');
        let left = 0;
        let right = arr.length - 1;

        while (left < right) {
            let temp = arr[left];
            arr [left] = arr[right];
            arr [right] = temp;
            left++;
            right--;
        }

        words[i] = arr.join('');
    }

    return words.join(" ");
};
