// Last updated: 10/03/2026, 13:45:50
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    if(strs.length===0)return"";

    let prefix=strs[0];

    for(let i=0; i<prefix.length; i++){
        for(let j=0; j<strs.length; j++){
            if(i>=strs[j].length || strs[j][i]!==prefix[i]){
                return prefix.slice(0, i);
            }
        }
    }
    return prefix;
};