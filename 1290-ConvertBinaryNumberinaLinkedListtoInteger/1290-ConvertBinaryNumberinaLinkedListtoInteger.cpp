// Last updated: 03/05/2026, 22:00:32
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
13    int getDecimalValue(ListNode* head) {
14        int result = 0;
15
16        while(head!= NULL) {
17            result = result * 2 + head->val;
18            head = head->next;
19        }
20        return result;
21    }
22};