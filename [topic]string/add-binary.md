| topic | difficulty | link |
| ---   | ---        | ---  |
| string | easy | [detail](https://leetcode.com/problems/add-binary/) |

```c++
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1, j = b.size()-1;
        int carry = 0;
        string s;

        while (i >= 0 || j >= 0 || carry) {
            carry += i >= 0 ? a[i--] - '0' : 0;
            carry += j >= 0 ? b[j--] - '0' : 0;
            s = s + char(carry % 2 + '0');
            carry /= 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
```

# note
- the while() condition is clever.
- get the result in reverse order and reverse it in the end to save time.
