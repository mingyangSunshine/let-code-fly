| topic | difficulty | link |
| ---   | ---        | ---  |
| math | medium | [detail](https://leetcode.com/problems/valid-parentheses/ |

# my solution
```c++
class Solution {
public:
    bool isValid(string s) {
		string::iterator iter = s.begin();
		while (iter != s.end()) {
			// push/pop stack and check
			switch (*iter) {
			case '(':
			case '[':
			case '{': push_stk(*iter); break;
			case ')':
				if (pop_stk() != '(')
					return false;
				break;
			case ']':
				if (pop_stk() != '[')
					return false;
				break;
			case '}':
				if (pop_stk() != '{')
					return false;
				break;
			default: return false; break;
			}
			iter++;
		}
		return (pos == 0);
	}
	void push_stk(char ch) {
		if (pos > 10000)
			return;
		stk[pos++] = ch;
	}
	char pop_stk() {
		if (pos <= 0) {
			return -1;
		}
		return stk[--pos];
	}
private:
	char stk[10000];
	int pos = 0;
};
```

 # other solution
 ```c++
class Solution {
public:
    bool isValid(string s) {
        string::iterator iter = s.begin();
        stack<char> stk_para;
        while (iter != s.end()) {
            switch (*iter) {
            case '(': stk_para.push(')'); break;
            case '[': stk_para.push(']'); break;
            case '{': stk_para.push('}'); break;
            case ')':
            case ']':
            case '}': 
                {
                    if (!stk_para.empty() && *iter == stk_para.top()) {
                        stk_para.pop();
                    } else {
                        return false;
                    }
                    break;
                }
            default: return false;
            }
            iter++;
        }
        return stk_para.empty();
    }
};


 # note
 - use stack data structure.