#include <iostream>
#include <vector>
#include <stack>
#include <list>
using  namespace std;



/*
*���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ���
*�����Ƿ����Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ���������־�����ȡ�
*��������1, 2, 3, 4, 5��ĳջ��ѹ��˳������4, 5, 3, 2, 1
*�Ǹ�ѹջ���ж�Ӧ��һ���������У���4, 3, 5, 1, 2�Ͳ�������
*��ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�
*ʵ�ַ�����
*		����һ���µ�ջ����ԭջ������ջ��ÿ��Ԫ����ջ֮��
*       ��һ���ж��Ƿ��ջ���������ж��Ƿ����ջ�е�δ��
*       ջԪ����ͬ��
*		��1�������ͬ�����ջ����ջ֮�����ж��µ�ջ�е�ջ��Ԫ���Ƿ�
*		����ջ�е�δ��ջԪ�أ���ջ�����Ҫ��ջ�����ջ��ֱ�����ܳ�ջ
*		��2���������ͬ����ԭջ�е�Ԫ��ѹ���µ�ջ�С�
*		�ظ�ִ���������Ĳ��裬��ԭջԪ��ȫ��ʵ������ջ���裬�ж���ջ�Ƿ�Ϊ�գ�
*       ���Ϊ�գ���ɹ�������ʧ�ܣ�
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
