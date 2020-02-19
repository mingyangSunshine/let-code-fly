| topic | difficulty | link |
| ---   | ---        | ---  |
| divide-and-conquer | easy | [detail](https://leetcode.com/problems/maximum-subarray/ |

# my solution - O(n) complexity.
```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT32_MIN;
        int curSum = 0;
        vector<int>::iterator iter = nums.begin();

        // keep adding each integer to the sequence until the sum drops below 0.
        // If sum is negative, then should reset the sequence.
        while (iter != nums.end()) {
            curSum += *iter++;
            maxSum = curSum > maxSum ? curSum : maxSum;
            if (curSum < 0) {
                curSum = 0;
            }
        }
        return maxSum;
    }
};
```

# other solution - similar
```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int[] dp = new int[n]; //dp[i] means the maximum subarray ending with A[i];
        dp[0] = A[0];
        int maxSum = dp[0];
        
        // core thought: dp[i] = nums[i] + (dp[i-1] > 0 ? dp[i-1] : 0);
        // max(maxSum, dp[i]);
        for(int i = 1; i < n; i++) {
            dp[i] = A[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
            maxSum = max(maxSum, dp[i]);
        }
        
        return maxSum;
}
```

# solution - divide and conquer
```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSub(nums, 0, nums.size()-1);
    }
private:
    int maxSub(vector<int>& nums, int l, int r) {
        if (l > r)
            return INT_MIN;
        int mid = (r-l)/2+l;
        int lMax = maxSub(nums, l, mid-1);
        int rMax = maxSub(nums, mid+1, r);
        int s1 = 0, s2 = 0;
        for (int i = mid-1, cur = 0; i >= l; i--) {
            cur += nums[i];
            s1 = max(s1, cur);
        }
        for (int i = mid+1, cur = 0; i <= r; i++) {
            cur += nums[i];
            s2 = max(s2, cur);
        }
        return max(s1+s2+nums[mid], max(lMax, rMax));
    }
};
```


# note
- 需要考虑全部为复数的情况在内。
- 动态规划：创建一个保存结果的数组dp[], dp[i]保存了以第i个数字结尾的子串的最大和的结果序列。其实不必保存dp[]全部结果。
- 分治法：The Divide-and-Conquer algorithm breaks nums into two halves and find the maximum subarray sum in them recursively. Well, the most tricky part is to handle the case that the maximum subarray spans the two halves. For this case, we use a linear algorithm: starting from the middle element and move to both ends (left and right ends), record the maximum sum we have seen. In this case, the maximum sum is finally equal to the middle element plus the maximum sum of moving leftwards and the maximum sum of moving rightwards.