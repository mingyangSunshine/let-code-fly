https://leetcode-cn.com/problems/generate-parentheses/

```c++
class Solution {
public:
	vector<string> result;
	void generateHelper(int left, int right, string &str) {
		if (right <= 0) {
			result.push_back(str);
			return;
		}
		if (left > 0) {
			str.push_back('(');
			generateHelper(left - 1, right, str);
			str.pop_back();
		}
		if (left < right && right > 0) {  // for left == right, can only add '('
			str.push_back(')');
			generateHelper(left, right - 1, str);
			str.pop_back();
		}
		return;
	}
	
	vector<string> generateParenthesis(int n) {
		if (n > 0) {
			string str;
			generateHelper(n, n, str);
		}

		return result;
	}
};
```

# 注释
1、传递`str`参数时，可以改成每次传递一个`str+'('`的临时变量，这样oj出来的结果占用内存更大；
2、上述所用方法思想为回溯法。
3、闭合数算法。对于每个括号对数目`c`，我们知道起始和结束括号必定位于索引`0`和`2*c + 1`。
然后两者间的 `2*c` 个元素一定是有效序列，其余元素一定是有效序列。因此，需要指定第一个括号对应的
闭合括号所在位置，并保证它们之间和之外的括号对为有效的。
ex: ``` '(' paran1 ')' paran2 ```
4、动态规划方法。把组合看作``` '(' paran1 ')' paran2 ```，分别求paran1的可能组合与paran2的
可能组合。类似于思路3。该方法占用内存空间大。

附上思路3的python版本，C++待整理
```python
class Solution(object):
    def generateParenthesis(self, N):
        if N == 0: return ['']
        ans = []
        for c in range(N):
            for left in self.generateParenthesis(c):
                for right in self.generateParenthesis(N-1-c):
                    ans.append('({}){}'.format(left, right))
        return ans
```