// Last updated: 12/08/2026, 15:55:08
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
13    ListNode* removeNodes(ListNode* head) {
14        ListNode* prev = nullptr;
15        ListNode* curr = head;
16
17        while (curr) {
18            ListNode* next = curr->next;
19            curr->next = prev;
20            prev = curr;
21            curr = next;
22        }
23
24        head = prev;
25        int maxVal = head->val;
26        curr = head;
27
28        while (curr && curr->next) {
29            if (curr->next->val < maxVal) {
30                curr->next = curr->next->next;
31            } else {
32                curr = curr->next;
33                maxVal = max(maxVal, curr->val);
34            }
35        }
36        prev = nullptr;
37        curr = head;
38
39        while (curr) {
40            ListNode* next = curr->next;
41            curr->next = prev;
42            prev = curr;
43            curr = next;
44        }
45
46        return prev;
47    }
48};