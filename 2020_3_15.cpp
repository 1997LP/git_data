#include <iostream>
#include <vector>
#include <stack>
#include <list>
using  namespace std;



/*
*输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个
*序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。
*例如序列1, 2, 3, 4, 5是某栈的压入顺序，序列4, 5, 3, 2, 1
*是该压栈序列对应的一个弹出序列，但4, 3, 5, 1, 2就不可能是
*该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
*实现方法：
*		创建一个新的栈，将原栈进行入栈，每个元素入栈之后，
*       （一）判断是否出栈，即就是判断是否与出栈中的未出
*       栈元素相同，
*		（1）如果相同，则出栈，出栈之后，再判断新的栈中的栈顶元素是否
*		（出栈中的未出栈元素）出栈，如果要出栈，则出栈，直到不能出栈
*		（2）如果不相同，则将原栈中的元素压入新的栈中。
*		重复执行完上述的步骤，即原栈元素全部实现了入栈步骤，判断新栈是否为空，
*       如果为空，则成功，否则，失败！
*/

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.empty()) return false;
		stack<int> ret;
		int size = pushV.size();
		int pop = 0;
		for (int i = 0; i < size; i++) {
			ret.push(pushV[i]);
			if (ret.top() == popV[pop]) {
				ret.pop();
				pop++;
				while (pop < size) {
					if (!ret.empty() &&
						(ret.top() == popV[pop])) {
						ret.pop(); pop++;
					}
					else break;
				}
			}
		}
		return ret.empty();
	}
};
int main()
{
	Solution test;
	vector<int> push = { 1,2,3,4,5 };
	vector<int> pop = { 4,3,5,1,2 };
	int ret = test.IsPopOrder(push, pop);
	cout << "ret = " << ret;
}
