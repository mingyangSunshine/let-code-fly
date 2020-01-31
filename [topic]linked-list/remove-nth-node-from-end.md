| topic | difficulty | link |
| ---   | ---        | ---  |
| linked-list | medium | [detail](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) |

# my solution
```c++
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1, *p2;
        p1 = head;
        p2 = head;
        while(n--) {
            p2 = p2->next;
        }
        // if remove head node
        if (!p2) {
            head = p1->next;
            delete(p1);
        }
        // normal case, delete the next node of p1
        else {
            while (p2->next) {
                p2 = p2->next;
                p1 = p1->next;
            }
            p2 = p1->next;
            p1->next = p2->next;
            delete(p2);
        }
        return head;
	}
};
```

# other solution - clearer
```c++
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *preHead = new ListNode(0);
        ListNode *slow, *fast;

        preHead->next = head;
        slow = preHead;
        fast = preHead;

        while (n--) {
            fast = fast->next;
        }

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return preHead->next;
    }
};
```

# note
