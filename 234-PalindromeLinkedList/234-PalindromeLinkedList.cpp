// Last updated: 05/08/2026, 15:49:02
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
23    ListNode* reverse(ListNode* head) {
24        ListNode* prev = nullptr;
25        while (head) {
26            ListNode* nextNode = head->next;
27            head->next = prev;
28            prev = head;
29            head = nextNode;
30        }
31        return prev;
32    }
33
34    bool isPalindrome(ListNode* head) {
35        if (!head || !head->next) return true;
36
37      
38        ListNode *slow = head, *fast = head;
39        while (fast && fast->next) {
40            slow = slow->next;
41            fast = fast->next->next;
42        }
43
44       
45        if (fast) slow = slow->next;
46
47       
48        ListNode* second = reverse(slow);
49        ListNode* first = head;
50
51       
52        while (second) {
53            if (first->val != second->val)
54                return false;
55            first = first->next;
56            second = second->next;
57        }
58
59        return true;
60    }
61};