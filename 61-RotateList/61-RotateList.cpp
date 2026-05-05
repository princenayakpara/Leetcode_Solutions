// Last updated: 05/05/2026, 07:26:44
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
13    ListNode* rotateRight(ListNode* head, int k) {
14        if (!head || !head->next || k == 0) return head;
15
16        // Step 1: Find length
17        ListNode* temp = head;
18        int n = 1;
19        while (temp->next) {
20            temp = temp->next;
21            n++;
22        }
23
24        // Step 2: Make it circular
25        temp->next = head;
26
27        // Step 3: Reduce k
28        k = k % n;
29
30        // Step 4: Find new tail (n - k - 1 steps)
31        int steps = n - k;
32        ListNode* newTail = head;
33
34        for (int i = 1; i < steps; i++) {
35            newTail = newTail->next;
36        }
37
38        // Step 5: Set new head
39        ListNode* newHead = newTail->next;
40
41        // Step 6: Break circle
42        newTail->next = nullptr;
43
44        return newHead;
45    }
46};