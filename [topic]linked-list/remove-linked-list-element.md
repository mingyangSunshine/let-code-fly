| topic | difficulty | link |
| ---   | ---        | ---  |
| linked-list | easy | [detail](https://leetcode.com/problems/remove-linked-list-elements/) |

# my solution - use pre and cur pointers.
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* preHead = new ListNode(0);
        preHead->next = head;
        ListNode* pre = preHead;
        ListNode* cur = head;

        while(cur) {
            if (cur->val == val) {
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
            } else {
                cur = cur->next;
                pre = pre->next;
            }
        }
        return preHead->next;
    }
};
```

# solution - 2 recursive
```c++
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) {
            return head;
        }
        ListNode *next = removeElements(head->next, val);
        if (head->val == val) {
            return next;
        } else {
            head->next = next;
            return head;
        }
    }
};
```

# note
- 