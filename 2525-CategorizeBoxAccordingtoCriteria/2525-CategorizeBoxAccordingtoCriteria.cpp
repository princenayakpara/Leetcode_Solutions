// Last updated: 19/05/2026, 11:44:15
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
13    ListNode* reverseKGroup(ListNode* head, int k) {
14        ListNode* curr = head;
15
16        // Check if there are at least k nodes
17        int count = 0;
18        while (curr && count < k) {
19            curr = curr->next;
20            count++;
21        }
22
23        // If we have k nodes, reverse them
24        if (count == k) {
25            curr = reverseKGroup(curr, k);
26
27            while (count--) {
28                ListNode* temp = head->next;
29                head->next = curr;
30                curr = head;
31                head = temp;
32            }
33
34            head = curr;
35        }
36
37        return head;
38    }
39};