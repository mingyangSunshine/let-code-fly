| topic | difficulty | link |
| ---   | ---        | ---  |
| math | easy | [detail](https://leetcode.com/problems/palindrome-number/) |

```c++
class Solution {
public:
    bool isPalindrome(int x) {
        queue<int> q;

        if (x < 0) {
            return false;
        }

        long long int temp = x;
        // push
        while (temp) {
            int res = temp % 10;
            temp = temp / 10;
            q.push(res);
        }
        temp = 0;
        // pop
        while (!q.empty()) {
            int res = q.front();
            q.pop();
            temp = temp * 10;
            temp += res;
        }

        if (temp == x) {
            return true;
        }
        else {
            return false;
        }
    }
};
```

# other solution
```c++
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x !=0 && x % 10 == 0)) {
            return false;
        }

        int sum = 0;
        while (x > sum) {
            sum = sum*10 + x%10;
            x /= 10;
        }
        return (x == sum) || (x == sum/10);
    }
};
```

# note
- be aware of **overflow** when reversing the integer.
- my solution uses queue data structure.
- a cool solution, only reverse half and compare, is provided.
