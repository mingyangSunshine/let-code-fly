| topic | difficulty | link |
| ---   | ---        | ---  |
| linked-list | easy | [detail](https://leetcode.com/problems/remove-duplicates-from-sorted-list/) |

# my solution
```c++
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // since it is sorted, compare current node value with next value, if
        // equal, delete the next.
        ListNode *p = head;
        if (head == NULL) {
            return head;
        }
        while (p->next) {
            if (p->val == p->next->val) {
                ListNode *temp = p->next;
                p->next = temp->next;
                delete(temp);
            } else {
                p = p->next;
            }
        }
        return head;
    }
};
```

# note

- 检查传入空值

