| topic | difficulty | link |
| ---   | ---        | ---  |
| array | easy | [detail](https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/) |

# solution
```c++
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        // n row m cols
        vector<bool> N(n, false);
        vector<bool> M(m, false);

        for (auto ind : indices) {
            N[ind[0]] = N[ind[0]] ^ true;
            M[ind[1]] = M[ind[1]] ^ true;
        }

        int r(0), c(0);
        for (bool b : N) {
            r = b ? r + 1 : r;
        }
        for (bool b : M) {
            c = b ? c + 1 : c;
        }

        return r*m + c*n - 2*r*c;
    }
};
```

# note
- 每次加一，结果效果与异或运算一样，采用异或运算代替
- 记录下每一列翻转的奇/偶数次数，偶数翻转次数的忽略，得到有r行和c列翻转了奇数次数。
- 结果中为奇数的个数：r\*m + c\*n - r\*c(重复计入) - r\*c(实际为偶数).
