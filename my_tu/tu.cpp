#include <iostream>
#include "tu.h"
#include <windows.h>
using namespace std;
//����ͼ����Ӿ���

void init_Graph(AMGraph& G)
{
	int i, j;
	int s1, s2;
	int num;
	cout << "\r\n\t������ͼ�Ķ�����������\r\n";
	cin >> G.ver_num >> G.border_num;
	for (i = 0; i < G.ver_num; i++)
		G.point_table[i] = i;
	for (i = 0; i < G.ver_num; i++)
		for (j = 0; j < G.ver_num; j++)
			G.Adj_Table[i][j] = Maxint;
	cout << "\r\n\t������ÿ���ߵ����ڶ����λ��,Ȩֵ\r\n";
	for (i = 0; i < G.border_num; i++)
	{
		cin >> s1 >> s2 >> num;
		G.Adj_Table[s1][s2] = num;
		G.Adj_Table[s2][s1] = num;
	}
}



//������ȱ���
int Visit[MVnum] = { 0 };
void dfs(AMGraph G, int value)
{
	Visit[value] = 1;
	cout << G.point_table[value] << " ";
	for (int i = 0; i < G.ver_num; i++)
		if (G.Adj_Table[value][i] < Maxint && !Visit[i])
			dfs(G, i);
}

void bfs(AMGraph G, int value)
{
	int j = 0;
	int i = 0;
	for ( i = 0; i < G.ver_num; i++)
		Visit[i] = 0;
	Visit[value] = 1;
	cout << G.point_table[value] << " ";
	Q Quene;
	Quene.front = Quene.rear = 0;
	Quene.quene[Quene.rear] = value;
	Quene.rear = (Quene.rear + 1) % MVnum;
	while(Quene.front != Quene.rear)
	{
		j=Quene.quene[Quene.front];
		Quene.front = (Quene.front + 1) % MVnum;
		for (int i = 0; i < G.ver_num; i++)
			if (G.Adj_Table[j][i] < Maxint && !Visit[i])
			{
				cout << G.point_table[i] << " ";
				Visit[i] = 1;
				Quene.quene[Quene.rear] = i;
				Quene.rear = (Quene.rear + 1) % MVnum;
			}

	}
}

void Graph_Prim(AMGraph G, int value)
{
	H_array Arr_ay;
	int code = 0;
	int k;
	int j, i;
	Arr_ay[value].Weight = 0;
	Arr_ay[value].vertex = 0;
	cout << "\r\n\t";
	for ( i = 0; i < G.ver_num; i++)
	{
		if (i != value)
		{
			Arr_ay[i].Weight = G.Adj_Table[value][i];
			Arr_ay[i].vertex = value;
		}
	}
	for ( j = 0; j < (G.ver_num - 1); j++)
	{
		code=find_min(Arr_ay, G.ver_num);
		//cout << code;
		cout <<' '<< Arr_ay[code].vertex << "����" << code;
		Arr_ay[code].Weight = 0;
		for (k=0;k<G.ver_num;k++)
		{
			if (G.Adj_Table[code][k] < Arr_ay[k].Weight)
			{
				Arr_ay[k].Weight = G.Adj_Table[code][k];
				Arr_ay[k].vertex = code;
			}
		}
	}


}
int find_min(H_array Arr_ay,int value)
{
	int i = 0;
	AR Min;
	int m = 0;
	for (; m < value; m++)
		if (Arr_ay[m].Weight != 0)
		{
			Min = Arr_ay[m];
			i = m;
			break;
		}	
	for (int j = m+1; j < value; j++)
		if ( (Arr_ay[j].Weight < Min.Weight) && (Arr_ay[j].Weight != 0 ))
		{
			Min = Arr_ay[j];
			i = j;
		}
	return i;
}




void Dis()
{
	char q;
	system("color 0A");
	cout << "\t\t-=---------------------" << endl << endl << "\t\t  \\\   2019��11��19��  \\\ " << endl << endl << "\t\t-----------------------";
	cout << endl << "\t\t| ģʽһ: ��������ͼ         |" << endl;
	cout << endl << "\t\t| ģʽ��: ͼ��������ȱ���   |" << endl;
	cout << endl << "\t\t| ģʽ��: ͼ�Ĺ�����ȱ���   |" << endl;
	cout << endl << "\t\t| ģʽ��: ��С������         |" << endl;
}

void mode_select(AMGraph &G_1,int value)
{
	char q;
	int num;
	cout << "\t";
	cin >> num;
	switch (num)
	{
	case 1:
		cout << endl << "\t\tģʽһ:  ��������ͼ   " << endl;
		init_Graph(G_1);
		break;
	case 2:
		cout << endl << "\t\tģʽ��: ͼ��������ȱ���\t" << endl;
		dfs(G_1, value);
		break;
	case 3:
		cout << endl << "\t\tģʽ��: ͼ�Ĺ�����ȱ��� " << endl;
		bfs(G_1, value);
		break;
	case 4:
		cout << endl << "\t\tģʽ��: ��С������      " << endl;
		Graph_Prim(G_1, value);
		break;
	default:
		break;
	}
	cout << "\r\n\t�����������ַ�����";
	cin >> q;
	system("cls");
}

