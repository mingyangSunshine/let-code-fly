| topic | difficulty | link |
| ---   | ---        | ---  |
| linked-list | easy | [detail](https://leetcode.com/problems/palindrome-linked-list/) |

# my solution - reverse the first half.
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
    bool isPalindrome(ListNode* head) {
        if (head == NULL) {
            return false;
        }
        ListNode* p1 = head;
        ListNode* p2 = head;
        ListNode* pre = NULL;
        ListNode* next = p1->next;

        // move p2 to the end, and p1 to the center
        while (p2->next && p2->next->next) {
            //reverse p1 while moving p2 to the end.
            p2 = p2->next->next;
            p1->next = pre;
            p1 = next;
            pre = p1;
            next = next->next;
        }
        // 1. odd number of list nodes: [O-O-O-O-O]
        // 2. only 1 node [O]
        if (p2->next == NULL) {
            // add one node of the center code to make it even
            p2 = new ListNode(p1->val);
            p2->next = next;
        }
        // 1. even number of list nodes [O-O-O-O-O-O]
        // 2. only tow nodes. [O-O]
        else if (p2->next->next == NULL) {
            // code
            p2 = next;
        }
        p1->next = pre;

        while (p2 && p2->val == p1->val) {
            p2 = p2->next;
            p1 = p1->next;
        }

        return p2 == NULL;
    }
};
```

# solution - 2 reverse the second half.
```c++

```

# solution - 3 recursive, but with O(n) space complexity.
```c++
class Solution {
public:
    ListNode* temp;
    bool isPalindrome(ListNode* head) {
        temp = head;
        return check(head);
    }
    
    bool check(ListNode* p) {
        if (NULL == p) return true;
        bool isPal = check(p->next) & (temp->val == p->val);
        temp = temp->next;
        return isPal;
    }
};
```

# note
- 