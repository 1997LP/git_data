/*************************ʮ��***********************************
*����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�
*min������ʱ�临�Ӷ�ӦΪO��1��������֤�����в��ᵱջΪ�յ�ʱ��
*��ջ����pop()����min()����top()������
*ʵ�ַ�����
*	����һ������ջ��ջ������ԭջ�д��ڵ���СԪ�أ�����ջ�е�Ԫ����Ŀ
*	��ͬ��ͬʱ��ջ����ջʱ��ԭջֱ����ջ������ջ�����ж�����ջԪ����
*	ջ��Ԫ�ش�С������µ�Ԫ��С������ջԪ��Ϊ����ջԪ�أ�������ջ
*   Ԫ��Ϊջ�����ڵ�Ԫ�ء�
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