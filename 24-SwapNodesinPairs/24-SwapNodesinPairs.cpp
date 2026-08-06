// Last updated: 06/08/2026, 16:28:25
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
13    ListNode* swapPairs(ListNode* head) {
14        ListNode temp(0);
15        temp.next = head;
16
17        ListNode* curr = &temp;
18
19        while (curr->next && curr->next->next) {
20            ListNode* first = curr->next;
21            ListNode* second = first->next;
22
23            first->next = second->next;
24            second->next = first;
25            curr->next = second;
26
27            curr = first;
28        }
29
30        return temp.next;
31    }
32};