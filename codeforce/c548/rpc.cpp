#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<ctime>
using namespace std;
int main()
{
    srand(time(NULL));
    printf("%d\n",rand()%11);
    for (int i = 1;i <= 4; i++)
        cout << (rand()%11) << " "; cout << endl;
    for (int i = 1;i <= 4; i++)
        cout << (rand()%11) << " "; cout << endl;
	return 0;
}

