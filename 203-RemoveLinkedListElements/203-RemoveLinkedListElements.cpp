// Last updated: 10/08/2026, 15:07:55
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
13    ListNode* removeElements(ListNode* head, int val) {
14        ListNode temp(0);
15        temp.next = head;
16
17        ListNode* prev = &temp;
18        ListNode* curr = head;
19
20        while(curr != nullptr){
21            if(curr->val == val) {
22                prev->next = curr->next;
23            }
24            else{
25                prev = curr;
26            }
27            curr = curr->next;
28        }
29        return temp.next;
30    }
31};