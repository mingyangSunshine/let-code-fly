| topic | difficulty | link |
| ---   | ---        | ---  |
| math | dasy | [detail](https://leetcode.com/problems/add-digits/) |

```c++
class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        while (num) {
            sum = sum + num % 10;
            sum = sum/10 + sum%10;
            num /= 10;
        }
        return sum;
    }
};
```

# other solution
```c++
class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};
```

# note
- it is math problem. *digit root* problem. ref: https://en.wikipedia.org/wiki/Digital_root#Congruence_formula
