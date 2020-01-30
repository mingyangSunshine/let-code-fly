https://leetcode.com/problems/merge-two-sorted-lists/

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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		struct ListNode *p1, *p2;
		struct ListNode *head = new struct ListNode(INT32_MIN);
		struct ListNode *ret = NULL;

		// init
		p1 = l1;
		head->next = l2;
		l2 = head;
		p2 = l2;

		// merge l1 into l2, insert l1~p1(not including p1) into between l2 and p2.
		while (l1 && l2) {
			p1 = l1->next;
			p2 = l2->next;
			
			if (p2 == NULL) {
				break;
			}

			if (l1->val <= p2->val) {
				// insert p1->val into p2
				l2->next = l1;
				while (p1 && p1->val <= p2->val) {
					l1 = p1;
					p1 = p1->next;
				}
				l1->next = p2;
				l2 = p2;
				l1 = p1;
			}
			else {
				l2 = p2;
			}
		}

		if (p2 == NULL) {
			l2->next = l1;
		}
		ret = head->next;
		delete(head);

		return ret;
	}
};
```

# other solution
## recursive method
```c++
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
            return l2;
		if(l2 == NULL)
            return l1;
		if ( l1->val < l2->val ) {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		} else {
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
    }
}
```

## iterative method
```c++
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        else if(l2 == NULL) return l1;
        ListNode *temp = new ListNode(0);
        ListNode *curr = temp;
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = (l1 == NULL) ? l2 : l1;
        return temp->next;
    }
}
```