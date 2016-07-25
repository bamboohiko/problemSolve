#include<iostream>
#include<cstring>
using namespace std;
int num[1010];
int prime[1010];
int ans[1010];
int main()
{int n,k,m=256,sum=0;
	memset(num,0,sizeof(num));
	num[1]=1;
	for (int i = 2;i <= m; i++)
		if (!num[i])
			{prime[++sum]=i;
			for (int j = i+i;j <= m; j+=i) num[j]=1;
			}
	//for (int i = 1;i <= sum; i++) cout << prime[i] << endl; 
	while (cin >> n)
		{k=0;
		 for (int i = 1;i <= sum; i++)
		 	{//cout << prime[i] << endl;
			 if (n != 1)
			 	while (!(n%prime[i])) 
			 		{ans[++k]=prime[i];
			 		n/=prime[i];
			 		//cout << ans[k] << endl; 
			 		}
			else break;
			}
		if (n != 1) ans[++k]=n;
		 for (int i = 1;i < k; i++) cout << ans[i] << "*";
		 cout << ans[k] << endl;
		}	
	return 0;
}
