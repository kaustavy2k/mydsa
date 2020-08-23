#include<bits/stdc++.h>

using namespace std;

#define ll long long int

void update(vector<ll> &fenwick,ll len,ll i,ll change)
{
    while(i<len)
    {
        fenwick[i]=fenwick[i]+change;
        i=i+(i&(-i));
    }
}

ll sum(vector<ll> &fenwick,ll len,ll i)
{
    ll sum=0;
    while(i>0)
    {
        sum=sum+fenwick[i];
        i=i-(i&(-i));
    }
    return sum;
}

ll main()
{
    ll n,k;
    cin>>n;
    vector<ll> a(n);
    vector<ll> fenwick(n+1);
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i-1];
        update(fenwick,n+1,i,a[i-1]);
    }
    for(auto i:fenwick)
        cout<<i<<" ";
    cout<<endl;
    ll b,c;
    for(ll qu=1;qu<=1000;qu++)
    {
        cin>>k>>b>>c;
        if (k==1)
        {
            update(fenwick,n+1,b,c-a[b-1]);
            a[b-1]=c;
        }
        else if(k==2)
        {
            cout<<sum(fenwick,n+1,b)-sum(fenwick,n+1,c-1)<<endl;
        }
    }
    return 0;
}