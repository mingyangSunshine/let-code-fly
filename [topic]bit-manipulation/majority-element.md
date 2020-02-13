| topic | difficulty | link |
| ---   | ---        | ---  |
| bit-manipulation | easy | [detail](https://leetcode.com/problems/majority-element/) |

# my solution
```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
    }
};
```

# solution 1 - sorting.
```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // nth_element(first, nth, last, compare);
        // 求区间 [first ~ last] 中第n大的元素，放在位置nth上并排序，即nth之后的元素都
        // 大于它，nth之前的元素都小于它。
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        return nums[nums.size() / 2];
    }
};
```

# solution 2 - Moore Voting Algorithm
## 前提是序列中存在出现次数大于总数1/2的元素
[算法来源](http://www.cs.utexas.edu/~moore/best-ideas/mjrty/index.html)
```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int counter = 0;
        vector<int>::iterator iter = nums.begin();
        int majority = 0;

        while (iter != nums.end()) {
            if (counter == 0) {
                majority = *iter;
                counter = 1;
            } else if (majority == *iter) {
                counter++;
            } else {
                counter--;
            }
            iter++;
        }
        return majority;
    }
};
```

# solution 3 - Bit manipulation
## the bits in the majority are just the majority of all numbers.
```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0;
        for (unsigned int i = 0, mask = 1; i < 32; i++, mask <<= 1;) {
            int bits = 0;
            for (int num : nums) {
                if (num & mask) {
                    bits++;
                }
            }
            if (bits > nums.size() / 2) {
                majority |= mask;
            }
        }

        return majority;
    }
};
```

# solution 4 - randomization
## pick an element randomly and check whether it is the majority one.

# solution 5 - divide and conquer
## recursively find the majority in the two halves of nums and combine the results.

see https://leetcode.com/problems/majority-element/discuss/51612/C%2B%2B-6-Solutions
for detail.

# note
