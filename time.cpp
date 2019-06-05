/*************************************************************************
	> File Name: time.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年05月23日 星期四 19时14分50秒
 ************************************************************************/

#include<iostream>
#include <string>

using namespace std;

int main(void)
{
    string time = "12:33:32";
    string c = ":";
    string tmp;
    string::size_type pos1, pos2;
    int allTime = 0;

    pos2 = time.find(c);
    pos1 = 0;
    
    for (int i=0; i<3; i++)
    {
        tmp = time.substr(pos1, pos2 - pos1);
        if (0 == i)
        {
            allTime += 3600 * stoi(tmp);
        }
        else if (1 == i)
        {
            allTime += 60 * stoi(tmp);
        }
        else
        {
            allTime += stoi(tmp);
        }
        pos1 = pos2 + c.size();
        pos2 = time.find(c, pos1);
    }

    cout << allTime << endl;

    return 0;
}
