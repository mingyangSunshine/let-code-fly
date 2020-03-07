| topic | difficulty | link |
| ---   | ---        | ---  |
| math | easy | [detail](https://leetcode.com/problems/rectangle-overlap/) |

# my solution
```c++
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int lr[] = {rec1[0], rec1[2], rec2[0], rec2[2]};
        int bu[] = {rec1[1], rec1[3], rec2[1], rec2[3]};
        int *small, *large;
        int isLap = 0;
        if (lr[0] < lr[2]) {
            small = &lr[0];
            large = &lr[2];
        } else {
            small = &lr[2];
            large = &lr[0];
        }
        if (*(++small) > *large) {
            isLap++;
        }
        if (bu[0] < bu[2]) {
            small = &bu[0];
            large = &bu[2];
        } else {
            small = &bu[2];
            large = &bu[0];
        }
        if (*(++small) > *large) {
            isLap++;
        }

        return isLap == 2;
    }
};
```

# other solution
```c++
class Solution {
public:
    int addDigits(int num) {
        return rec1[0] < rec2[2] && rec2[0] < rec1[2] && rec1[1] < rec2[3] && rec2[1] < rec1[3];
    }
};
```

# note
- 确保都满足左下角顶点位于另一个矩形右上角顶点的左下方。
