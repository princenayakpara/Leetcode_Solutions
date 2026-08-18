// Last updated: 18/08/2026, 15:53:59
1class Solution {
2public:
3    Node* flatten(Node* head) {
4        if (!head) return head;
5
6        Node* cur = head;
7
8        while (cur) {
9            if (cur->child) {
10                Node* child = cur->child;
11                Node* next = cur->next;
12
13                cur->next = child;
14                child->prev = cur;
15                cur->child = nullptr;
16
17                Node* tail = child;
18
19                while (tail->next)
20                    tail = tail->next;
21
22                tail->next = next;
23
24                if (next)
25                    next->prev = tail;
26            }
27
28            cur = cur->next;
29        }
30
31        return head;
32    }
33};