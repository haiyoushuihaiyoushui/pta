/*************************************************************************
	> File Name: 1006.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年05月23日 星期四 18时52分32秒
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

typedef struct
{
    string Id;
    string time;
}Id_Time;

int getTimeNum(string time)
{
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
    
    return allTime;
}

bool EarlyTime(string t1, string t2)
{
    if (getTimeNum(t1) < getTimeNum(t2))
    {
        return true;
    }
    else if (getTimeNum(t1) > getTimeNum(t2))
    {
        return false;
    }
    return false;
}

int main(void)
{
    string Id;
    string InTime;
    string OutTime;
    int num = 0;
    Id_Time early;
    Id_Time last;
    
    cin >> num;
    for (int i=0; i<num; i++)
    {
        cin >> Id >> InTime >> OutTime;
        if (0 == i)
        {
            early.time = InTime;
            last.time = OutTime;
            early.Id = Id;
            last.Id = Id;
        }

        if (EarlyTime(InTime, early.time))
        {
            early.time = InTime;
            early.Id = Id;
        }
        
        if (!EarlyTime(OutTime, last.time))
        {
            last.time = OutTime;
            last.Id = Id;
        }
    }
    
    cout << early.Id << " " << last.Id;
    
    return 0;
}
