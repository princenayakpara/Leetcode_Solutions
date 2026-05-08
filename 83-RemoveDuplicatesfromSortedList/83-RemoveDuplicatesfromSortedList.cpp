// Last updated: 08/05/2026, 22:47:04
1class Solution {
2public:
3    ListNode* deleteDuplicates(ListNode* head) {
4        ListNode* temp = head;
5
6        while(temp != NULL && temp->next != NULL) {
7            if(temp->val == temp->next->val) {
8                temp->next = temp->next->next;
9            }
10            else {
11                temp = temp->next;
12            }
13        }
14
15        return head;
16    }
17};