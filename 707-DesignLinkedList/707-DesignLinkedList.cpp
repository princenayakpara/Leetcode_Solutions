// Last updated: 04/08/2026, 17:05:55
1class MyLinkedList {
2private:
3    struct Node {
4        int val;
5        Node* next;
6        Node(int x) {
7            val = x;
8            next = nullptr;
9        }
10    };
11
12    Node* dummy;
13    int size;
14
15public:
16    MyLinkedList() {
17        dummy = new Node(0);
18        size = 0;
19    }
20
21    int get(int index) {
22        if (index < 0 || index >= size)
23            return -1;
24
25        Node* curr = dummy->next;
26        for (int i = 0; i < index; i++)
27            curr = curr->next;
28
29        return curr->val;
30    }
31
32    void addAtHead(int val) {
33        addAtIndex(0, val);
34    }
35
36    void addAtTail(int val) {
37        addAtIndex(size, val);
38    }
39
40    void addAtIndex(int index, int val) {
41        if (index < 0)
42            index = 0;
43
44        if (index > size)
45            return;
46
47        Node* prev = dummy;
48        for (int i = 0; i < index; i++)
49            prev = prev->next;
50
51        Node* node = new Node(val);
52        node->next = prev->next;
53        prev->next = node;
54
55        size++;
56    }
57
58    void deleteAtIndex(int index) {
59        if (index < 0 || index >= size)
60            return;
61
62        Node* prev = dummy;
63        for (int i = 0; i < index; i++)
64            prev = prev->next;
65
66        Node* temp = prev->next;
67        prev->next = temp->next;
68        delete temp;
69
70        size--;
71    }
72};
73
74/**
75 * Your MyLinkedList object will be instantiated and called as such:
76 * MyLinkedList* obj = new MyLinkedList();
77 * int param_1 = obj->get(index);
78 * obj->addAtHead(val);
79 * obj->addAtTail(val);
80 * obj->addAtIndex(index,val);
81 * obj->deleteAtIndex(index);
82 */