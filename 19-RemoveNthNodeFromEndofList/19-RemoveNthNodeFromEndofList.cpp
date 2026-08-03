// Last updated: 03/08/2026, 15:54:47
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
11/**
12 * Definition for singly-linked list.
13 * struct ListNode {
14 *     int val;
15 *     ListNode *next;
16 *     ListNode() : val(0), next(nullptr) {}
17 *     ListNode(int x) : val(x), next(nullptr) {}
18 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
19 * };
20 */
21class Solution {
22public:
23    ListNode* removeNthFromEnd(ListNode* head, int n) {
24        ListNode dummy(0);
25        dummy.next = head;
26
27        ListNode* fast = &dummy;
28        ListNode* slow = &dummy;
29
30        // Move fast n steps ahead
31        for (int i = 0; i < n; i++) {
32            fast = fast->next;
33        }
34
35        // Move both until fast reaches the last node
36        while (fast->next != nullptr) {
37            fast = fast->next;
38            slow = slow->next;
39        }
40
41        // Delete the nth node from the end
42        ListNode* temp = slow->next;
43        slow->next = temp->next;
44        delete temp;  // Optional for LeetCode
45
46        return dummy.next;
47    }
48};
49