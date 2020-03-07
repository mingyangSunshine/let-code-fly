| topic | difficulty | link |
| ---   | ---        | ---  |
| math | easy | [detail](https://leetcode.com/problems/happy-number/) |

# 最后的结果，如果不是1则是循环的，设置一个slow值，一个fast值记录，直到两者相等 Floyd's cycle detection algorithm

```c++
class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = calSquareNum(slow);
            fast = calSquareNum(fast);
            fast = calSquareNum(fast);
        } while (slow != fast);
        if (slow == 1) {
            return true;
        }
        return false;
    }
    int calSquareNum(int num) {
        int sum = 0, res;
        while (num) {
            res = num % 10;
            sum += res * res;
            num = num / 10;
        }
        return sum;
    }
};
```

# Brent's Cycle detection algorithm
# https://en.wikipedia.org/wiki/Cycle_detection
```c++
class Solution {
public:
    int next(int n)
    {
        int sum = 0;
        
        while(n != 0)
        {
            sum += pow(n % 10,2);
            n = n / 10;
        }
        
        return sum;
    }

public:
    bool isHappy(int n) {
        int slow = n;
        int fast = next(n);
        int cnt = 1;
        int lim = 2;
        
        while(slow != fast)
        {
            if(cnt == lim)
            {
                cnt = 1;
                lim = lim*2;
                slow = fast;
            }
            else
                cnt ++;
        
            fast = next(fast);
        }
        
        return fast == 1 ;
    }
};
```

# other solution - 哈希表
```c++
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> tmp;
        
        while(n != 1)
        {
            if(tmp.find(n) == tmp.end())
                tmp.insert(n);
            else
                return false;
            
            int sum = 0;
            while(n != 0)
            {
                sum += pow(n % 10,2);
                n = n / 10;
            }
            
            n = sum;
        }
        
        return true;
    }
};
```

# note
- 
