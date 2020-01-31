| topic | difficulty | link |
| ---   | ---        | ---  |
| linked-list | medium | [detail](https://leetcode.com/problems/add-two-numbers/) |

# my solution
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int overflow = 0;
        ListNode *head = l1;
        if (l1 == NULL || l2 == NULL) {
            return NULL;
        }
        // add from 个位 to last node位.
        while (l1->next && l2->next) {
            l1->val = l1->val + l2->val + overflow;
            overflow = l1->val / 10;
            l1->val = l1->val % 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        // process the last node, if l1 ends, move the last nodes from l2
        // to l1, store the final result in l1.
        // a special case is when l1 and l2 end together.
        if (l1->next == NULL) {
            l1->next = l2->next;
            l2->next = NULL;
        }
        l1->val = l1->val + l2->val + overflow;
        overflow = l1->val / 10;
        l1->val = l1->val % 10;
        
		//处理进位，存在例如1+9999999这样的情况，需要一直进位。
        while (overflow) {
            if (l1->next == NULL) {
                l1->next = new ListNode(overflow);
                overflow = 0;
            } else {
                l1->next->val += overflow;
                overflow = l1->next->val / 10;
                l1->next->val %= 10;
                l1 = l1->next;
            }
        }

        return head;
    }
};
```

# other solution
```c++
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode preHead(0);
		ListNode *p = &preHead;
		int extra = 0;

		while (l1 || l2 || extra) {
			if (l1) {
				extra += l1->val;
				l1 = l1->next;
			}
			if (l2) {
				extra += l2->val;
				l2 = l2->next;
			}
			p->next = new ListNode(extra % 10);
			p = p->next;
			extra /= 10;
		}

		return preHead.next;
	}
};
```

# note
- 存在 1 + 999999 类似这样需要一直进位下去的情况