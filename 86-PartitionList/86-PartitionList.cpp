// Last updated: 10/08/2026, 15:49:13
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
13    ListNode* partition(ListNode* head, int x) {
14        ListNode lessDummy(0);
15        ListNode greaterDummy(0);
16
17        ListNode* less = &lessDummy;
18        ListNode* greater = &greaterDummy;
19
20        while (head != nullptr) {
21            if (head->val < x) {
22                less->next = head;
23                less = less->next;
24            } else {
25                greater->next = head;
26                greater = greater->next;
27            }
28
29            head = head->next;
30        }
31
32        greater->next = nullptr;
33        
34        less->next = greaterDummy.next;
35
36        return lessDummy.next;
37    }
38};