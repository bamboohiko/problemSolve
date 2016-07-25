#include<iostream>
#include<cstring>
using namespace std;
int rec[15];
int num[15];
int main()
{int t,n,now,k,i;
	cin >> t;
	while (t--)
		{cin >> n;
		 memset(num,0,sizeof(num));
		 now=k=n%10;i=0;
		 while (!num[now])
			{num[now]=1;
			 rec[i++]=now;
			 now=now*k%10;
			}
		 cout << rec[(n-1)%i] << endl;		 
		}
	 
	return 0;
}
