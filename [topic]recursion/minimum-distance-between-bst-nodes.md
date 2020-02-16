| topic | difficulty | link |
| ---   | ---        | ---  |
| recursion | easy | [detail](https://leetcode.com/problems/minimum-distance-between-bst-nodes/ |

# my solution - recursive, will exceed time limit.
```c++
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int minValLeft = INT32_MAX;
        int minValRight = INT32_MAX;

        if (root->left) {
            minValLeft = min(root->val - getMaxOfTree(root->left), minDiffInBST(root->left));
        }
        if (root->right) {
            minValRight = min(getMinOfTree(root->right) - root->val, minDiffInBST(root->right));
        }

        return min(minValRight, minValLeft);
    }

    int getMinOfTree(TreeNode* node) {
        while (node->left) {
            node = node->left;
        }
        return node->val;
    }

    int getMaxOfTree(TreeNode* node) {
        while (node->right) {
            node = node->right;
        }
        return node->val;
    }
};
```

 # other solution - use an prev to record the previous node value.
 ```c++
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int res = numeric_limits<int>::max(), prev =  numeric_limits<int>::min();
        helper(root,prev,res);
        return res;
    }
    
    void helper(TreeNode* root, int &prev, int &res){
        if(root){
            helper(root->left,prev,res);
            if(prev!=numeric_limits<int>::min())
                res = min(res, root->val-prev);
            prev = root->val;
            helper(root->right,prev,res);
        }
    }
};
```


 # note
 - prev初始值设置为INT32_MIN，用prev记录上一个遍历到的结点值，求得root->val-prev的值，并不断与res的值比较取最小