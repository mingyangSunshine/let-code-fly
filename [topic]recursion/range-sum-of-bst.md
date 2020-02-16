| topic | difficulty | link |
| ---   | ---        | ---  |
| recursion | easy | [detail](https://leetcode.com/problems/range-sum-of-bst/ |

# my stupid solution
```c++
class Solution {
public:
    int sum = 0;
    int flag = 0;
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (root == NULL) {
            return 0;
        }
        (void)rangeSumBST(root->left, L, R);
        if (root->val == L) {
            flag = 1;
        }
        sum += flag ? root->val : 0;
        if (root->val == R) {
            flag = 0;
        }
        (void)rangeSumBST(root->right, L, R);

        return sum;
    }
};
```

 # other solution - simple recursive: very clear!
 ```c++
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (root == NULL) return 0;
        if (root->val > R) return rangeSumBST(root->left, L, R);
        if (root->val < L) return rangeSumBST(root->right, L, R);
        return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
    }
};
```


 # note
 - use stack data structure.