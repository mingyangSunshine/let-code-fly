| topic | difficulty | link |
| ---   | ---        | ---  |
| recursion | easy | [detail](https://leetcode.com/problems/longest-univalue-path/ |

# my solution - recursive
```c++
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int maxLen = 0;
        helper(root, maxLen);
        return maxLen;
    }

    void helper(TreeNode* root, int& maxLen) {
        if (root == NULL) return;
        int dep = depth(root->left, root->val) + depth(root->right, root->val);
        maxLen = dep > maxLen ? dep : maxLen;
        helper(root->left, maxLen);
        helper(root->right, maxLen);
    }

    int depth(TreeNode* node, int val) {
        if (node == NULL) return 0;
        if (node->val == val) {
            return 1 + max(depth(node->left, val), depth(node->right, val));
        }
        return 0;
    }
};
```

 # solution - 2
 ## see details at https://leetcode.com/problems/longest-univalue-path/discuss/108136/JavaC%2B%2B-Clean-Code
 ```c++
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int lup = 0;
        if (root) dfs(root, lup);
        return lup;
    }

private:
    int dfs(TreeNode* node, int& lup) {
        int l = node->left ? dfs(node->left, lup) : 0;
        int r = node->right ? dfs(node->right, lup) : 0;
        int resl = node->left && node->left->val == node->val ? l + 1 : 0;
        int resr = node->right && node->right->val == node->val ? r + 1 : 0;
        lup = max(lup, resl + resr);
        return max(resl, resr);
    }
};
```


 # note
 - 这道题目描述中，最长的路径是指二叉树深度概念上的，具有相同结点值的一系列结点从头连到尾，在树中的最长边长。
 - solution 2 中，l代表左子树中的最大边长数, r代表右子树的最大边长数, resl代表当前
   note结点的左半边中的最大深度（边长数目），resr待变当前note结点中的右半边中的最大
   深度，return max(resl, resr); 用于在递归中返回l和r的值。