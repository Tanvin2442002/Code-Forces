#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=n-i;j>=0;j--)
        {
            cout<<" ";
        }
        for(int j=1;j<=2*i-1;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    int k=2*n-1;
    k=k-n;
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<" ";
        }
        for(int j=(k-i)*2+1;j>0;j--)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}