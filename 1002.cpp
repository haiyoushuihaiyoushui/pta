/*************************************************************************
	> File Name: 1002.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年04月08日 星期一 18时49分58秒
 ************************************************************************/

#include <iostream>
#include <map>
#include <iomanip>

const float EPSILON = 0.01;

using namespace std;

int main(void)
{
    int K1 = 0;
    int K2 = 0;
    int N = 0;
    double a = 0;
    map<int, float, greater<int>> p;
    map<int, float, greater<int>>::iterator it;
    map<int, float, greater<int>>::iterator it_find;

    cin >> K1;
    for (int i=0; i<K1; i++)
    {
        cin >> N >> a;
        p[N] = a;
        p.insert(make_pair(N, a));
    }
    
    cin >> K2;
    for (int i=0; i<K2; i++)
    {
        cin >> N >> a;
        it_find = p.find(N);
        if (it_find != p.end())
        {
            p.erase(it_find);
            p.insert(make_pair(N, a+it_find->second));
        }
        else
        {
            p.insert(make_pair(N, a));
        }
    }
    
    for (it=p.begin(); it!=p.end(); it++)
    {
        if (it->second >= -EPSILON && it->second <= EPSILON)
        {
            p.erase(it);
        }
    }
    
    cout << p.size();
    if (0 == p.size())
    {
        return 0;
    }
    else
    {
        cout << " ";
    }
    for (it=p.begin(); it!=p.end(); it++)
    {        
        if (it != p.end() && it!=p.begin())
        {
            cout << " ";
        }
        cout << it->first << " ";

        if (it->second >= -EPSILON && it->second <= EPSILON)
        {
            cout << "0";
        }
        else
        {
            cout << fixed << setprecision(1) << it->second;
        }
    }

    return 0;
}
