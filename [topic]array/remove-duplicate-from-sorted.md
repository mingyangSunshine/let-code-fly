| topic | difficulty | link |
| ---   | ---        | ---  |
| array | easy | [detail](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) |

# my solution
```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int unique(0), p(0);
        while (p < nums.size()) {
            if (nums[p] != nums[unique]) {
                nums[++unique] = nums[p];
            }
            p++;
        }
        unique += (int)(nums.size() != 0);
        return unique;
    }
};
```

# other solution
## use a variable 'count' to mark the distance between unique and current.
```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (A[i] == A[i-1]) count++;
            else A[i-count] = A[i];
        }
        return nums.size() - count;
    }
};
```
# note
- 要求原址修改，如每次发现重复的值，删掉把后续的值依次移动到前面来，cost太大。使用两个标记，一个记录并保存不重复的值，另一个用于遍历整个数组。遍历过程中发现不同的值则保存到标记所在位置。
