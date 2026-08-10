// Last updated: 10/08/2026, 14:48:30
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
13    ListNode* reverseBetween(ListNode* head, int left, int right) {
14        if (!head || left == right) return head;
15
16        // Dummy node handles the case where left == 1
17        ListNode dummy(0, head);
18        ListNode* prev = &dummy;
19
20        // Move prev to the node just before 'left'
21        for (int i = 1; i < left; i++) {
22            prev = prev->next;
23        }
24
25        // Reverse nodes between left and right
26        ListNode* curr = prev->next;
27
28        for (int i = 0; i < right - left; i++) {
29            ListNode* nextNode = curr->next;
30
31            curr->next = nextNode->next;
32            nextNode->next = prev->next;
33            prev->next = nextNode;
34        }
35
36        return dummy.next;
37    }
38};