#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int timer=0;

void dfs(vector<vector<int>> &edge,vector<int> &ft,vector<int> &st,vector<int> &et,int current=1,int parent=0)
{
    timer++;
    ft[timer]=current;
    st[current]=timer;
    for(auto i:edge[current])
    {
        if (i!=parent)
            dfs(edge,ft,st,et,i,current);
    }
    timer++;
    ft[timer]=current;
    et[current]=timer;
}

int main()
{
    int n,a,b;
    cin>>n;
    vector<vector<int>> edge(n+1);
    vector<int> ft(2*n+1);
    vector<int> st(n+1);
    vector<int> et(n+1);
    for(int i=1;i<n;i++)
    {
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(edge,ft,st,et);
    cout<<"FT : ";
    for(int i=1;i<2*n+1;i++)
        cout<<ft[i]<<",";
    cout<<"\nET : ";
    for(int i=1;i<n+1;i++)
        cout<<st[i]<<" ";
    cout<<"\nST : ";
    for(int i=1;i<n+1;i++)
        cout<<et[i]<<" ";
}