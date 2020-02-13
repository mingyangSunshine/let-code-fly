| topic | difficulty | link |
| ---   | ---        | ---  |
| bit-manipulation | easy | [detail](https://leetcode.com/problems/number-of-1-bits/) |

# my solution
```c++
class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t mask = 1;
        int count = 0;
        while (mask) {
            if (mask & n) {
                count++;
            }
            mask <<= 1;
        }
        return count;
    }
};
```

# solution 2
## n&(n-1) 
```c++
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            count++;
            n &= (n-1);
        }
        return count;
    }
};
```

# note
- n &= (n-1) could remove the last '1' bit.
