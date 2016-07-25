#include<cstdio>
#include<map>
#include<vector>
using namespace std;
map<int,int> cou;
vector<int> v;
int main()
{int t;
    scanf("%d",&t);
    while (t--)
        {int n;
        cou.clear();
        v.clear();
        scanf("%d",&n);
        for (int i = 1;i <= n; i++)
            {int x;
            scanf("%d",&x);
            v.push_back(x);
            if (!cou.count(x)) cou[x] = 0;
            else cou[x]++;
            }
        for (int i = 0;i < v.size(); i++)
            if (!cou[v[i]])
            {printf("%d\n",v[i]);
            break;
            }
        }
    return 0;
}



