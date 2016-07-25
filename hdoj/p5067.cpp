#include<iostream>
using namespace std;
int main()
{int n,m,t;
	while (cin >> n >> m)
		{t=0;
		for (int i = 1;i <= n;i++ )
			for (int j = 1;j <= m;j++)
				{cin >> x;
				if (x > 0) 
					{t++;
					pos[t].x=i;pos[t].y=j;
					}
				}
		state=(1 << (t+1)) -1;
		
		for (int i = 1;i <= state; i++ )
			for (int j = 1;j <= t; j++ )
				{f[i][j]=3*n*m;
				for (int k = 1;k <= t; k++)
					if ((i >> (k-1)) & 1) 
						f[i][j]=max(f[i][j],f[i][k]+dis(j,k)); 
			   }
		for (int i = 1;i <= t; i++)
		}
	return 0;
}
