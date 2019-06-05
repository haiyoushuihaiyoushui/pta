/*************************************************************************
	> File Name: priority_queue.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年04月29日 星期一 19时20分16秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <queue>

using namespace std;

typedef struct VERTEX_SIDE
{
    int vertex;
    int side;
    
    friend bool operator<(VERTEX_SIDE f1, VERTEX_SIDE f2)
    {
        return f1.side > f2.side;       //side小的放在队首
    }
}VERTEX_SIDE_S;

int main(void)
{
    priority_queue<VERTEX_SIDE_S> dis_min;
    VERTEX_SIDE_S tmpNode;
    
    tmpNode.vertex = 3;
    tmpNode.side = 4;
    dis_min.push(tmpNode);
    
    tmpNode.vertex = 5;
    tmpNode.side = 6;
    dis_min.push(tmpNode);
    
    tmpNode.vertex = 1;
    tmpNode.side = 2;
    dis_min.push(tmpNode);
    

    cout << dis_min.top().vertex << " " << dis_min.top().side << endl;
    
    return 0;
}
