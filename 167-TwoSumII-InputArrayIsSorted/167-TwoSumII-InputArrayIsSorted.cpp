// Last updated: 02/07/2026, 18:49:54
1class Solution {
2public:
3    vector<int> twoSum(vector<int>& numbers, int target) {
4        int left = 0, right = numbers.size() - 1;
5
6        while(left < right){
7            int sum = numbers[left] + numbers[right];
8
9        if(sum == target){
10            return {left+1, right+1};
11        }
12        else if(sum < target){
13            left++;
14        }
15        else {
16            right--;
17        }
18        }
19        return {};
20    }
21};