// Last updated: 04/08/2026, 14:43:40
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode(int x) : val(x), next(NULL) {}
7 * };
8 */
9class Solution {
10public:
11    void deleteNode(ListNode* node) {
12        node->val = node->next->val;
13        ListNode* temp = node->next;
14        node->next = node->next->next;
15        delete temp;
16    }
17};