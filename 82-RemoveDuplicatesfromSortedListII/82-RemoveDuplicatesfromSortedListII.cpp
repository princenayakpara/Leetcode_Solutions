// Last updated: 10/08/2026, 14:57:36
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
13    ListNode* deleteDuplicates(ListNode* head) {
14        ListNode dummy(0);
15        dummy.next = head;
16
17        ListNode* prev = &dummy;
18        ListNode* curr = head;
19
20        while (curr != nullptr) {
21            bool duplicate = false;
22
23            while (curr->next != nullptr &&
24                   curr->val == curr->next->val) {
25                duplicate = true;
26                curr = curr->next;
27            }
28
29            if (duplicate) {
30                prev->next = curr->next;
31            } else {
32                prev = prev->next;
33            }
34
35            curr = curr->next;
36        }
37
38        return dummy.next;
39    }
40};