| topic | difficulty | link |
| ---   | ---        | ---  |
| linked-list | easy | [detail](https://leetcode.com/problems/delete-node-in-a-linked-list/) |

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
    void deleteNode(ListNode* node) {
        auto next = node->next;
        *node = *next;
        delete next;
    }
};
```

# note
- This is a very stupid question...