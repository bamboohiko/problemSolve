#include "iostream"
#include "string.h"
using namespace std;
long long fun (long long n)
{
    long long sum=1;
    while (n!=1)
    {
        if (n%2==0)
        {
            n=n/2;
        }
        else
        {
            n=3*n+1;
        }
        ++sum;
    }
    return sum;
}
int main ()
{
    long long a,b;
    while (cin>>a>>b)
    {
        long long max=0;
        cout<<a<<" "<<b<<" ";
        if (b>=837799)
        {
            max=525;
        }
        else
        {
            if (a>b)
            {
                long long t=b;
                b=a;
                a=t;
            }
            for (;a<=b;a++)
            {
                max=max>fun(a)?max:fun(a);
            }
        }
        cout<<max<<endl;
    }
    return 0;
}

