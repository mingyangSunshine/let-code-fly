| topic | difficulty | link |
| ---   | ---        | ---  |
| linked-list | easy | [detail](https://leetcode.com/problems/intersection-of-two-linked-lists/) |

# my solution
```c++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> stkA, stkB;
        ListNode *p1, *p2;
        ListNode *ret = NULL;
        p1 = headA;
        p2 = headB;

        while (p1) {
            stkA.push(p1);
            p1 = p1->next;
        }
        while (p2) {
            stkB.push(p2);
            p2 = p2->next;
        }

        while (!stkA.empty() && !stkB.empty() && stkA.top() == stkB.top()) {
            ret = stkA.top();
            stkA.pop();
            stkB.pop();
        }

        return ret;
    }
};
```

# other solution - looks more clearer
```c++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA;
        ListNode *p2 = headB;

        if (p1 == NULL || p2 == NULL) {
            return NULL;
        }

        while (p1 != NULL && p2 != NULL && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;

            // Any time they collide or reach end together without colliding 
            // then return any one of the pointers.
            if (p1 == p2) {
                return p1;
            }

            if (p1 == NULL) {
                p1 = headB;
            }
            if (p2 == NULL) {
                p2 = headA;
            }
        }

        return p1;
    }
};
```

# note
- the intersection here means the same address.
- in my solution, stack data structure is applied.
- another artful solution is provided. Let p1 go through headA then headB, let
  p2 go through headB then headA, if colliding, intersection exists.