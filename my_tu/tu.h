#ifndef _Graph
#define _Graph

const int Maxint = 1000;
const int MVnum = 100;

typedef struct {
	int Adj_Table[MVnum][MVnum];
	int point_table[MVnum];
	int ver_num;
	int border_num;
}AMGraph;
typedef struct {
	int front;
	int rear;
	int quene[MVnum];
}Q;

typedef struct AR{
	int vertex;
	int Weight;

}array,H_array[MVnum];

int find_min(H_array Arr_ay, int value);
void init_Graph(AMGraph& G);
void dfs(AMGraph G, int value);
void bfs(AMGraph G, int value);
void Graph_Prim(AMGraph G, int value);
void mode_select(AMGraph& G_1, int value);
void Dis(void );
#endif
