// Last updated: 14/06/2026, 12:02:03
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
13    int pairSum(ListNode* head) {
14        ListNode* slow = head;
15        ListNode* fast = head;
16
17        // Find middle
18        while (fast && fast->next) {
19            slow = slow->next;
20            fast = fast->next->next;
21        }
22
23        // Reverse second half
24        ListNode* prev = nullptr;
25        while (slow) {
26            ListNode* nextNode = slow->next;
27            slow->next = prev;
28            prev = slow;
29            slow = nextNode;
30        }
31
32        // Calculate maximum twin sum
33        int ans = 0;
34        ListNode* first = head;
35        ListNode* second = prev;
36
37        while (second) {
38            ans = max(ans, first->val + second->val);
39            first = first->next;
40            second = second->next;
41        }
42
43        return ans;
44    }
45};