/***************************************
*���������������������������������ϳɺ������
*�ϳɺ���������㵥����������
*ʵ�ַ���: �����ĵݹ����
********************************************/
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :
//			val(x), next(NULL) {
//	}
//};
//class Solution {
//public:
//	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
//	{
//		if (pHead1 == NULL || pHead2 == NULL)
//			return pHead1!= NULL ? pHead1 : pHead2;
//
//		ListNode* head = NULL;
//
//		if (pHead1->val < pHead2->val)
//			head = pHead1;
//			head->next = Merge(pHead1->next, pHead2);
//		}
//		else{
//			head = pHead2;
//			head->next = Merge(pHead1, pHead2->next);
//		}
//		return head;
//	}
//};