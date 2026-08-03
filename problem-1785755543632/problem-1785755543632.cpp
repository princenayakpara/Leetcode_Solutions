// Last updated: 03/08/2026, 16:42:23
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
13    void reorderList(ListNode* head) {
14        if (!head || !head->next) return;
15
16        ListNode *slow = head, *fast = head;
17        while (fast->next && fast->next->next) {
18            slow = slow->next;
19            fast = fast->next->next;
20        }
21
22         ListNode *curr = slow->next;
23        slow->next = nullptr;
24
25        ListNode *prev = nullptr;
26        while (curr) {
27            ListNode *nextNode = curr->next;
28            curr->next = prev;
29            prev = curr;
30            curr = nextNode;
31        }
32
33         ListNode *first = head;
34        ListNode *second = prev;
35
36        while (second) {
37            ListNode *temp1 = first->next;
38            ListNode *temp2 = second->next;
39
40            first->next = second;
41            second->next = temp1;
42
43            first = temp1;
44            second = temp2;
45        }
46    }
47};