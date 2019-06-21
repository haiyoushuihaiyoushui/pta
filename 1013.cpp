/*************************************************************************
	> File Name: 1013.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年06月19日 星期三 19时43分06秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;
const int MAX_NUM = 1001;

int main(void)
{
    int N = 0;
    int M = 0;
    int K = 0;
    int x = 0;
    int y = 0;
    vector<int> path[MAX_NUM];
       
    cin >> N >> M >> K;
    
    for (int i=0; i<M; i++)
    {
        cin >> x >> y;
        path[x].push_back(y);
    }
    
    for (int i=0; i<K; i++)
    {
//         cin >> 
    }
    
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<path[i].size(); j++)
        {
            cout << path[i].at(j) << " ";
        }
        cout << endl;
    }
    
    for (int i=0; i<K; i++)
    {
        cout << " " << endl;
    }
    
    return 0;
}
