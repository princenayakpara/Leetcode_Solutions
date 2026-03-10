// Last updated: 10/03/2026, 13:45:57
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {

    // this will be the start of our answer list
    let head = new ListNode(0);

    // pointer to build the new list
    let current = head;

    // this stores carry like normal addition
    let carry = 0;

    // run loop until both lists end AND carry becomes 0
    while (l1 !== null || l2 !== null || carry !== 0) {

        // get values from nodes, if node is null take 0
        let num1 = 0;
        let num2 = 0;

        if (l1 !== null) {
            num1 = l1.val;
        }

        if (l2 !== null) {
            num2 = l2.val;
        }

        let total = num1 + num2 + carry;

        let digit = total % 10;

        carry = Math.floor(total / 10);

        current.next = new ListNode(digit);

        current = current.next;
        if (l1 !== null) {
            l1 = l1.next;
        }

        if (l2 !== null) {
            l2 = l2.next;
        }
    }
    return head.next;
};