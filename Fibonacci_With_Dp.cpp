#include<iostream>
using namespace std;
int findfib(int n)
{
    if(n==0||n==1)
    {
        return n;
    }
    else
    {
        int *arr=new int[n+1];
        arr[0]=0;arr[1]=1;

        for(int i=2; i<=n; i++)
        {
            arr[i]=arr[i-1]+arr[i-2];
        }
        return arr[n];
    }
}
int main()
{
    int n;
    cout<<"Enter number"<<endl;
    cin>>n;

    int ans=findfib(n);

    cout<<ans;
}