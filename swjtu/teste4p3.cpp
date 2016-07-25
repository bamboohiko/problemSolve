#include<iostream>
#include<cstring>
using namespace std;
const int p[]={3,5,7,11,13,17,19,23,29,31,37};
int num[25];
int use[25];
int n;
void order()
{
    for (int i = 1;i < n; i++) cout << num[i] << " ";
    cout << num[n] << endl;
}
bool prime(int a)
{
    for (int i = 0;i < 11;i++)
        if (a == p[i]) return true;
    return false;
}
void dfs(int k)
{
    //1cout << k << " " << num[k] << endl;
    if (k == n)  
        {if ( prime(num[n]+1) ) order();
         return;
        }
    for (int i = 2;i <= n; i++)
        if ((!use[i]) && (prime(num[k]+i)))
            {use[i]=1;num[k+1]=i;
            dfs(k+1);
            use[i]=0;
            }
}
int main()
{int t=0;
    while (cin >> n)
        {cout << "Case " << ++t << ":" << endl;
         memset(use,0,sizeof(use));
         num[1]=1;
         dfs(1);
         cout << endl;
        }
    return 0;
}
