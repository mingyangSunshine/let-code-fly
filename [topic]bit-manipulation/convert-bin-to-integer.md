| topic | difficulty | link |
| ---   | ---        | ---  |
| bit-manipulation | easy | [detail](https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/) |

# my solution
```c++
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result = 0;
        while (head) {
            result <<= 1;
            result |= head->val;
            head = head->next;
        }
        return result;
    }
};
```

# note
- use bit shift and | operation.
