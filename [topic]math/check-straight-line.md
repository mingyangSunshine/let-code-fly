| topic | difficulty | link |
| ---   | ---        | ---  |
| math | easy | [detail](https://leetcode.com/problems/check-if-it-is-a-straight-line/) |

# my solution
```c++
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double delta_y, delta_x, k;
        bool yaixs = false;
        vector<int> start(coordinates[0]);
        delta_y = coordinates[1][1] - coordinates[0][1];
        delta_x = coordinates[1][0] - coordinates[0][0];
        if (delta_x == 0) {
            yaixs = true;
        } else {
            k = delta_y / delta_x;
        }

        for (int i = 2; i < coordinates.size(); i++) {
            delta_y = coordinates[i][1] - start[1];
            delta_x = coordinates[i][0] - start[0];
            if (delta_x == 0) {
                if (yaixs) continue;
                else return false;
            }
            if (abs(k - delta_y / delta_x) > 1e-6) {
                return false;
            }
        }
        return true;
    }
};
```

# other solution - use multiply
```c++
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int delta_y0, delta_x0;
        bool yaixs = false;
        vector<int> start(coordinates[0]);
        delta_y0 = coordinates[1][1] - coordinates[0][1];
        delta_x0 = coordinates[1][0] - coordinates[0][0];

        for (int i = 2; i < coordinates.size(); i++) {
            int delta_y = coordinates[i][1] - start[1];
            int delta_x = coordinates[i][0] - start[0];
            if (delta_y * delta_x0 != delta_x * delta_y0) {
                return false;
            }
        }
        return true;
    }
};
```

# note
- 
