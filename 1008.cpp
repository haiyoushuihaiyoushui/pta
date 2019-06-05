/*************************************************************************
	> File Name: 1008.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年05月28日 星期二 19时00分20秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main(void)
{
    int N = 0;
    int last = 0;
    int next = 0;
    int sum = 0;
    
    cin >> N;
    for (int i=0; i<N; i++)
    {
        cin >> next;
        if (last > next)
        {
            sum += 4 * (last - next);
        }
        else if (last < next)
        {
            sum += 6 * (next - last);
        }

        last = next;
    }
    
    sum += N * 5;
    
    cout << sum;
    
    return 0;
}
