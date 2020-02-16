| topic | difficulty | link |
| ---   | ---        | ---  |
| recursion | easy | [detail](https://leetcode.com/problems/n-th-tribonacci-number/ |

# my solution - recursive, will exceed time limit.
```c++
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;
        return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    }
};
```

 # other solution - use an array
 ```c++
class Solution {
public:
    int tribonacci(int n) {
        int tribNum[38] = {0, 1, 1};
        for (int i = 3; i <= n; i++) {
            tribNum[i] = tribNum[i-1] + tribNum[i-2] + tribNum[i-3];
        }
        return tribNum[n];
    }
};
```


 # note
 - 