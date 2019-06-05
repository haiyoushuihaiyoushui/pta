/*************************************************************************
	> File Name: map.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年04月21日 星期日 11时43分05秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef struct
{
    int v;      //边的目标顶点
    int dis;    //边权
    int wight;  //人数
}NODE_S;

typedef struct VERTEX_SIDE
{
    int vertex;
    int side;
    
    friend bool operator<(VERTEX_SIDE f1, VERTEX_SIDE f2)
    {
        return f1.side > f2.side;       //side小的放在队首
    }
}VERTEX_SIDE_S;

const int MAX_LEN = 510;
const int INF = 1000000000;

vector<NODE_S> Adj[MAX_LEN];
int num_vertex = 0;          //顶点数
int num_side = 0;          //边数

int dis_min[MAX_LEN];     //起点到达各点的最短路径长度
int pre[MAX_LEN];         //pre[v]表示从起点到顶点v的最短路径上v的前一个起点
bool vis[MAX_LEN] = {false};    //标记数组，true已访问
int num[MAX_LEN] = {0};         //起点到达各点的最短路径的条数
int weight[MAX_LEN] = {0};      //点权
int max_weight[MAX_LEN] = {0};  //起点到各点收集到的最大物资

void Dijkstra(int s)    //s为起点
{
    fill(dis_min, dis_min+MAX_LEN, INF);
    
    for (int i=0; i<num_vertex; i++)
    {
        pre[i] = i;     //初始设每个点的前驱为自身
    }
    
    num[s] = 1;
    dis_min[s] = 0;
    max_weight[s] = weight[s];
    
    for (int i=0; i<num_vertex; i++)
    {
        int u = -1;
        int MIN = INF;
        for (int j=0; j<num_vertex; j++)     //找到未访问的顶点中dis_min最小的
        {
            if (!vis[j] && dis_min[j] < MIN)
            {
                u = j;                  //u使dis_min[u]最小
                MIN = dis_min[j];         //MIN存放该最小的dis_min[u]
            }
        }
        //找不到小于INF的dis_min[u]，即剩下的顶点与起点s不连通
        if (-1 == u)
        {
            cout << "return " << endl;
            return;
        }
        vis[u] = true;
        
        for (int j=0; j<Adj[u].size(); j++)
        {
            int v = Adj[u][j].v;
            int new_dis = dis_min[u] + Adj[u][j].dis;
            if (!vis[v])
            {
                if (new_dis < dis_min[v])
                {
                    //若v未访问且以u为中介点可以使dis_min[v]更优
                    dis_min[v] = dis_min[u] + Adj[u][j].dis;    //优化dis_min[v]
                    pre[v] = u;         //记录v的前驱顶点为u
                    num[v] = num[u];
                    max_weight[v] = max_weight[u] + weight[v];
                }
                else if (new_dis == dis_min[v])
                {
                    num[v] += num[u];
                    if (max_weight[u] + weight[v] > max_weight[v])
                    {
                        max_weight[v] = max_weight[u] + weight[v];
                    }
                }
            }
        }
    }
}

//计算路径
void DFS(int s, int v)      //s为起点，v为当前访问的顶点编号
{
    if (v == s)
    {
        cout << "start point " << s << endl;
        return;
    }
    DFS(s, pre[v]);
    cout << "every floor " << v << endl;
}

int main(void)
{
    int u = 0;
    int v = 0;
    int w = 0;  //u-->v边权
    int startPoint = 0;          //起点
    int endPoint = 0;
    int people = 0;
    NODE_S tmpNode;

    cin >> num_vertex >> num_side >> startPoint >> endPoint;         //顶点个数、边数、起点编号

    for (int i=0; i<num_vertex; i++)
    {
        cin >> people;
        weight[i] = people;
    }
    
    for (int i=0; i<num_side; i++)
    {
        cin >> u >> v >> w;     //u, v和u->v的边权
        tmpNode.v = v;
        tmpNode.dis = w;
        Adj[u].push_back(tmpNode);
#if 1   //双向边
        tmpNode.v = u;
        tmpNode.dis = w;
        Adj[v].push_back(tmpNode);
#endif
    }
    
    Dijkstra(startPoint);
//     DFS(startPoint, endPoint);
//     cout << dis_min[endPoint] << " " << num[endPoint] << " " << max_weight[endPoint] << endl;
    cout << num[endPoint] << " " << max_weight[endPoint] << endl;
//     for (int i=0; i<num_vertex; i++)
//     {
//         cout << i << " " << dis_min[i] << " " << num[i] << endl;
//     }
    
    return 0;
}
