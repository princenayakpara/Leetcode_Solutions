// Last updated: 21/08/2026, 15:14:50
1class Solution {
2public:
3    bool hasCycle(ListNode *head) {
4        if (!head || !head->next)
5            return false;
6
7        ListNode* slow = head;
8        ListNode* fast = head->next;
9
10        while (fast && fast->next) {
11            slow = slow->next;
12            fast = fast->next->next;
13
14            if (slow == fast)
15                return true;
16        }
17
18        return false;
19    }
20};