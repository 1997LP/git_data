/*************************十七***********************************
*定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的
*min函数（时间复杂度应为O（1））。保证测试中不会当栈为空的时候，
*对栈调用pop()或者min()或者top()方法。
*实现方法：
*	创建一个辅助栈，栈顶保存原栈中存在的最小元素，两个栈中的元素数目
*	相同，同时出栈，入栈时，原栈直接入栈，辅助栈首先判断新入栈元素与
*	栈顶元素大小，如果新的元素小。则入栈元素为新入栈元素，否则，入栈
*   元素为栈顶存在的元素。
****************************************************************/
class Solution {
public:
	void push(int value) {
		stack.push_back(value);
		if (ret.empty()) {
			ret.push_back(value);
		}
		else {
			if (value < ret[ret.size() - 1]) {
				ret.push_back(value);
			}
			else {
				ret.push_back(ret[ret.size() - 1]);
			}
		}
	}
	void pop() {
		if(stack.size())stack.pop_back();
		if (ret.size())ret.pop_back();
	}
	int top() {
		if(stack.size())return stack[stack.size()-1];
		else return 0;
	}
	int min() {
		return ret[ret.size()-1];
	}
private:
	vector<int> stack;
	vector<int> ret;                
};