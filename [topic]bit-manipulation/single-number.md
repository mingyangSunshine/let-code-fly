| topic | difficulty | link |
| ---   | ---        | ---  |
| bit-manipulation | easy | [detail](https://leetcode.com/problems/single-number/) |

# my solution
```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>::iterator iter = nums.begin();
        int result = 0;
        while (iter != nums.end()) {
            result ^= *iter++;
        }
        return result;
    }
};
```

# note
- use XOR operation to accomplish linear runtime complexity.