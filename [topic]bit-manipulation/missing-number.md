| topic | difficulty | link |
| ---   | ---        | ---  |
| bit-manipulation | easy | [detail](https://leetcode.com/problems/missing-number/) |

# solution 1 - XOR operation.
```c++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            result = result ^ i ^ nums[i];
        }
        return result;
    }
};
```

# solution 2 - Array of arithmetic progression
```c++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        return (n * (n + 1)) / 2 - sum;
    }
};
```

# note
- xor of same numbers equals 0.
- sum of an array and minus the sum of nums.
