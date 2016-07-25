/*#include<iostream>
#include<set>
using namespace std;
set<int> s;
int main()
{int a,b,n,m;
	while (cin >> a >> b >> n)
		{s.clear();
		s.insert(a);s.insert(b);s.insert(b-a);
		if (n > 3) s.insert(-a);
		if (n > 4) s.insert(-b);
		if (n > 5) s.insert(a-b); 
		cout << s.size() << endl;
		}
	return 0;
}*/
#include<stdio.h>
#include<string.h>
int num[10];
int main()
{int a,b,n;
	while (scanf("%d%d%d",&a,&b,&n) != EOF)
		{memset(num,0,sizeof(num)); //这里初始化好像没什么用…… 
		int m = 3;
		num[1] = a;num[2] = b;num[3] = b-a;
		if (n > 3) num[++m] = -a;
		if (n > 4) num[++m] = -b;
		if (n > 5) num[++m] = a-b;
		int ans = m; 
		for (int i = 1;i <= m; i++)
			for (int j = 1;j < i; j++)
				if (num[i] == num[j]) 
					{ans--;
					break;
					}
		printf("%d\n",ans);
		}
	return 0;
}

