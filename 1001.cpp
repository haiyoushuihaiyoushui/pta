/*************************************************************************
	> File Name: 1001.cpp
	> Author:
	> Mail:
	> Created Time: 2019年03月13日 星期三 18时48分04秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

void printString(int num)
{
    string str;
    int len = 0;

    str = to_string(num);
    len = str.size();
    for (int i=0; i<len; i++)
    {
        cout << str[i];     //依次打印字符
        if ('-' == str[i])
        {
            continue;
        }
        if (((i+1) % 3 == len % 3)
                && (i != len - 1))
        {
            cout << ",";
        }
    }
}

int main(void)
{
    int a = 0;
    int b = 0;
    int sum = 0;

    cin >> a >> b;

    sum = a + b;
    printString(sum);

    return 0;
}
