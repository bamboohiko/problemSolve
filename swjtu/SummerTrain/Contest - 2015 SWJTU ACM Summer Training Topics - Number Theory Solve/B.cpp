#include<stdio.h>
int main()
{	long long t,count,i,m=1,a,b,c[6];
	c[0]=6;
	c[1]=28;
	c[2]=496;
	c[3]=8128;
	c[4]=33550336;
	c[5]=8589869056;
	scanf("%lld",&t);
	while(t--)
	{	count=0;
		scanf("%lld%lld",&a,&b);
		for(i=0;i<6;i++)
		{	if(c[i]>=a&&c[i]<=b)
			{	count++;
			}
		}
		printf("Case #%lld: %lld\n",m++,count);
	}
	return 0;
}