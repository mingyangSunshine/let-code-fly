| topic | difficulty | link |
| ---   | ---        | ---  |
| array | easy | [detail](https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/) |

# my solution
```c++
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // find the first negative number in each row.
        int count = 0;
        for (int row = 0; row < grid.size(); row++) {
            int col = 0;
            for (col = 0; col < grid[0].size() && grid[row][col] >= 0; col++);
            count += (grid[0].size() - col);
        }

        return count;
    }
};
```

# other solution
## search from upper right to lower left, a litter faster
```c++
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m(grid.size()), n(grid[0].size()), r(0), c(n - 1);
        while (r < m) {
            while (c >= 0 && grid[r][c] < 0) c--;
            ans += n - c - 1;
            r++;
        }
    }
};
# note
- 
