/*************************************************************************
	> File Name: 1005.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年05月20日 星期一 19时12分35秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

#define BIT_LEN (4)

int main(void)
{
    int sum = 0;
    int i = 0;
    char bit[BIT_LEN];
    char a = '\0';
    const char *test[] = {"zero", "one", "two", "three", "four", "five", "six",\
                   "seven", "eight", "nine"};

    while (1)
    {
        a = getchar();
        if ('\n' == a)
        {
            break;
        }
        sum += a - '0';
    }
    while (1)
    {
        bit[i++] = sum % 10;
        sum /= 10;
        if (sum <= 0)
        {
            break;
        }
    }
    
    for (; i>0; i--)
    {
        printf("%s", test[int(bit[i-1])]);
        if (i > 1)
        {
            printf(" ");
        }
    }

    return 0;
}
