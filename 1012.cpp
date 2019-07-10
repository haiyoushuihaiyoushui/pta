/*************************************************************************
	> File Name: 1012.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月10日 星期三 18时57分57秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef struct
{
    string id;
    int C;
    int M;
    int E;
    int A;
}STUDENT_S;

bool myCom_C(STUDENT_S a, STUDENT_S b)
{
    return (a.C > b.C);
}

bool myCom_M(STUDENT_S a, STUDENT_S b)
{
    return (a.M > b.M);
}

bool myCom_E(STUDENT_S a, STUDENT_S b)
{
    return (a.E > b.E);
}

bool myCom_A(STUDENT_S a, STUDENT_S b)
{
    return (a.A > b.A);
}

int main(void)
{
    int M = 0;
    int N = 0;
    string id_tmp;
    vector<STUDENT_S> stu_vec;
    STUDENT_S stu_tmp;
    map<string, int> map_C;
    map<string, int> map_M;
    map<string, int> map_E;
    map<string, int> map_A;
    
    cin >> M >> N;
    for (int i=0; i<M; i++)
    {
        cin >> stu_tmp.id >> stu_tmp.C >> stu_tmp.M >> stu_tmp.E;
        stu_tmp.A = (stu_tmp.C + stu_tmp.M + stu_tmp.E) / 3;
        stu_vec.push_back(stu_tmp);
    }
    
    sort(stu_vec.begin(), stu_vec.end(), myCom_C);
    for (int i=0; i<stu_vec.size(); i++)
    {
        if (0 == i)
        {
            map_C[stu_vec[i].id] = i;
            continue;
        }
        if (stu_vec[i].C == stu_vec[i-1].C)
        {
            map_C[stu_vec[i].id] = i - 1;
        }
        else
        {
            map_C[stu_vec[i].id] = i;
        }
    }
    
    sort(stu_vec.begin(), stu_vec.end(), myCom_M);
    for (int i=0; i<stu_vec.size(); i++)
    {
        map_M[stu_vec[i].id] = i;
    }
    
    sort(stu_vec.begin(), stu_vec.end(), myCom_E);
    for (int i=0; i<stu_vec.size(); i++)
    {
        map_E[stu_vec[i].id] = i;
    }
    
    sort(stu_vec.begin(), stu_vec.end(), myCom_A);
    for (int i=0; i<stu_vec.size(); i++)
    {
        map_A[stu_vec[i].id] = i;
    }
    
    for (int i=0; i<N; i++)
    {
        cin >> id_tmp;
        map<string, int>
    }
    
    return 0;
}
