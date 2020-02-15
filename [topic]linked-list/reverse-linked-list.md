| topic | difficulty | link |
| ---   | ---        | ---  |
| linked-list | easy | [detail](https://leetcode.com/problems/reverse-linked-list/) |

# my solution - iterative
```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode *fast = head->next;
        ListNode *slow = head;

        slow->next = NULL;

        while (fast) {
            ListNode* temp = fast->next;
            fast->next = slow;
            slow = fast;
            fast = temp;
        }

        return slow;
    }
};
```

# solution - 2 recursive
## used an extra pointer to store the value of last node.
```c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode *result = NULL;
        ListNode** nhead = &result;
        head = reverse(nhead, head);
        head->next = NULL;
        return *nhead;
    }
    ListNode* reverse(ListNode** nhead, ListNode *p) {
        if (p->next == NULL) {
            // the last node
            *nhead = p;
            return p;
        }
        ListNode *tail = reverse(nhead, p->next);
        tail->next = p;
        return p;
    }
};
```

# solution - simple recursion
```c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !(head->next)) {
            return head;
        }
        ListNode *res = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;  //can be changed to right value after return.
        return res;
    }
}
```

# note
- 