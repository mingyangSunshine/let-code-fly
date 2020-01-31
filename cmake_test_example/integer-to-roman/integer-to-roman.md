https://leetcode-cn.com/problems/integer-to-roman/

topic = math

```c++
// 1       I
// 5       V
// 10      X
// 50      L
// 100     C
// 500     D
// 1000    M
// sepcial:
// 4       IV
// 9       IX
// 40      XL
// 90      XC
// 400     CD
// 900     CM
class Solution {
public:
	vector<string> Roman_table = {"M", "CM", "D", "CD", "C", "XC", "L", "XL",
                                  "X", "IX", "V", "IV", "I" };
	vector<int> Num_table = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

	string intToRoman(int num) {
		string output;
		int radix_ind = 0;
		while (num > 0) {
			int res = num / Num_table[radix_ind];
			num = num % Num_table[radix_ind];
			while (res--) {
				output += Roman_table[radix_ind];
			}
			radix_ind++;
		}
		return output;
	}
};
```


# 注释

贪心算法思想