#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

void print(vector<vector<int>> &doo)
{
    int n=doo.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<doo[i][j]<<" ";
        }
        cout<<endl;
    }
}

void task()
{
    int n;
    scanf("%d",&n);
    if (n==1)
    {
        cout<<"Hooray\n1\n";
        return;
    }
    if (n%2)
    {
        printf("Boo\n");
        return;
    }
    vector<vector<int> > doofish( n , vector<int> (n, -69));
    vector<int> list(n-1);
    for(int i=0;i<n-1;i++)//list
        list[i]=i+1;

    for(int i=0;i<n;i++)//diagonal
        doofish[i][i]=2*n-1;
    
    for(int i=1;i<n;i++)//top row except first element
        doofish[0][i]=i;
    
    int p=1;
    for(int i=1;i<n-1;i++)//last elements of each row except last row
    {
        doofish[i][n-1]=list[p];
        p=(p+2)%(n-1);
    }
    
    p=1;
    int temp;
    for(int i=1;i<n;i++)//rows of upper triangle except last element
    {
        temp=doofish[i][n-1]-1;
        for(int j=p+1;j<n-1;j++)
        {
            temp=(temp+1)%(n-1);
            doofish[i][j]=list[temp];
        }
        p++;
    }
    
    for(int i=0;i<n;i++)//lower triangle
    {
        for(int j=0;j<n;j++)
        {
            if (doofish[i][j]==-69)
                doofish[i][j]=doofish[j][i]+n-1;
        }
    }
    printf("Hooray\n");
    print(doofish);
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
        task();
    return 0;
}