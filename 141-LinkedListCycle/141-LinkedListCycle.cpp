// Last updated: 24/08/2026, 15:22:00
1class Solution {
2public:
3    ListNode *detectCycle(ListNode *head) {
4        if (!head || !head->next)
5            return nullptr;
6
7        ListNode *slow = head;
8        ListNode *fast = head;
9
10        while (fast && fast->next) {
11            slow = slow->next;
12            fast = fast->next->next;
13
14            if (slow == fast) {
15                ListNode *cur = head;
16
17                while (cur != slow) {
18                    cur = cur->next;
19                    slow = slow->next;
20                }
21
22                return cur;
23            }
24        }
25
26        return nullptr;
27    }
28};