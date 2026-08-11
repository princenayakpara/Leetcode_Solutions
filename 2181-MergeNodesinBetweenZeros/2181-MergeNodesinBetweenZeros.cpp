// Last updated: 11/08/2026, 17:08:13
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
13    ListNode* mergeNodes(ListNode* head) {
14        ListNode* curr = head->next;  
15        ListNode* ans = nullptr;
16        ListNode* tail = nullptr;
17
18        int sum = 0;
19
20        while (curr) {
21            if (curr->val == 0) {
22                ListNode* node = new ListNode(sum);
23
24                if (!ans) {
25                    ans = node;
26                    tail = node;
27                } else {
28                    tail->next = node;
29                    tail = node;
30                }
31
32                sum = 0;
33            } else {
34                sum += curr->val;
35            }
36
37            curr = curr->next;
38        }
39
40        return ans;
41    }
42};