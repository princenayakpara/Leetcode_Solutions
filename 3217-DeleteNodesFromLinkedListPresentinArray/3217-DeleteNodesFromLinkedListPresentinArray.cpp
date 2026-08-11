// Last updated: 11/08/2026, 14:57:02
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
14        unordered_set<int> st(nums.begin(), nums.end());
15
16        ListNode temp(0, head);
17        ListNode* curr = &temp;
18
19        while(curr->next){
20            if(st.count(curr->next->val)) {
21                curr->next = curr->next->next;
22            } else {
23                curr = curr->next;
24            }
25        }
26            return temp.next;
27        }
28    
29};