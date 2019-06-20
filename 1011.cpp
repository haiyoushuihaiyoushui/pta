/*************************************************************************
	> File Name: 1011.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年06月19日 星期三 18时13分54秒
 ************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
    double sum = 1;
    double tmp = 0;
    double max = 0;
    int index = 0;
    const char array[3] = {'W', 'T', 'L'};
    
    for (int i=0; i<3; i++)
    {
        index = 0;
        max = 0;
        for (int j=0; j<3; j++)
        {
            cin >> tmp;
            if (max < tmp)
            {
                max = tmp;
                index = j;
            }
        }
        cout << array[index] << " ";
        sum *= max;
    }

    cout.setf(ios::fixed);
    cout << setprecision(2) << (sum * 0.65 - 1) * 2;
    
    return 0;
}
