| topic | difficulty | link |
| ---   | ---        | ---  |
| bit-manipulation | easy | [detail](https://leetcode.com/problems/power-of-two/) |

# my solution
```c++
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && !(n & (n-1));
    }
};
```

# note
- pay attention that input arg has a 'int' type. power of 2 should be > 0.
- n &= (n-1) could remove the last '1' bit. to check if there is only one bit '1' in binary.
