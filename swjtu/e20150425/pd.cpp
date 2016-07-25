#include "iostream"
using namespace std;
int main ()
{
    int n;
    while (cin>>n)
    {
        int i;
        for (i=0;i<n;i++)
        {
            int t;
            cin>>t;
            if (t==1)
            {
                cout<<"1"<<endl;
            }
            if (t==2)
            {
                cout<<"2 1"<<endl;
            }
            if (t==3)
            {
                cout<<"3 1 2"<<endl;
            }
            if (t==4)
            {
                cout<<"2 1 4 3"<<endl;
            }
            if (t==5)
            {
                cout<<"3 1 4 5 2"<<endl;
            }
            if (t==6)
            {
                cout<<"4 1 6 3 2 5"<<endl;
            }
            if (t==7)
            {
                cout<<"5 1 3 4 2 6 7"<<endl;
            }
            if (t==8)
            {
                cout<<"3 1 7 5 2 6 8 4"<<endl;
            }
            if (t==9)
            {
                cout<<"7 1 8 6 2 9 4 5 3"<<endl;
            }
            if (t==10)
            {
                cout<<"9 1 8 5 2 4 7 6 3 10"<<endl;
            }
            if (t==11)
            {
                cout<<"5 1 6 4 2 10 11 7 3 8 9"<<endl;
            }
            if (t==12)
            {
                cout<<"7 1 4 9 2 11 10 8 3 6 5 12"<<endl;
            }
            if (t==13)
            {
                cout<<"4 1 13 11 2 10 6 7 3 5 12 9 8"<<endl;
            }
            if (t==14)
            {
                cout<<"10 1 7 6 2 12 8 5 3 14 13 11 9 4"<<endl;
            }
        }
    }
    return 0;
}

