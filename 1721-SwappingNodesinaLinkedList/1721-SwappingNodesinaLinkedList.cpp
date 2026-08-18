// Last updated: 18/08/2026, 16:31:35
1class Solution {
2public:
3    ListNode* swapNodes(ListNode* head, int k) {
4        int n = 0;
5        ListNode* cur = head;
6
7        while (cur) {
8            n++;
9            cur = cur->next;
10        }
11
12        ListNode* first = head;
13        for (int i = 1; i < k; i++)
14            first = first->next;
15
16        ListNode* second = head;
17        for (int i = 1; i < n - k + 1; i++)
18            second = second->next;
19
20        swap(first->val, second->val);
21
22        return head;
23    }
24};