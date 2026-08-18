// Last updated: 18/08/2026, 17:00:57
1class Solution {
2public:
3    Node* copyRandomList(Node* head) {
4        if (!head) return nullptr;
5
6        unordered_map<Node*, Node*> mp;
7
8        Node* cur = head;
9
10        while (cur) {
11            mp[cur] = new Node(cur->val);
12            cur = cur->next;
13        }
14
15        cur = head;
16
17        while (cur) {
18            mp[cur]->next = cur->next ? mp[cur->next] : nullptr;
19            mp[cur]->random = cur->random ? mp[cur->random] : nullptr;
20            cur = cur->next;
21        }
22
23        return mp[head];
24    }
25};