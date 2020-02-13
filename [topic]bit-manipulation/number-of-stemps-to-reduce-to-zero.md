| topic | difficulty | link |
| ---   | ---        | ---  |
| bit-manipulation | easy | [detail](https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/) |

# my solution
```c++
class Solution {
public:
    int numberOfSteps (int num) {
        int count = 0;
        while (num) {
            if (num & 0x1) {
                num -= 1;
            } else {
                num >>= 1;
            }
            count++;
        }
        return count;
    }
};
```

# note
- use bit shift and | operation.
