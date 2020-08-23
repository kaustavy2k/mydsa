#include<stdio.h>
#include<iostream>
#include<map>
#include<string>
#include<vector>

#define ll long long int
using namespace std;

class trie              //prefix trie
{
    public:
    ll visits;
    trie *child[26];//to store the poller to the actual children
    vector<ll> childset;//to store set of all child array indexes which are not null
    ll depth;
    trie()
    {
        visits=0;
        for(ll i=0;i<26;i++)
            child[i]=NULL;
        depth=0;
    }
    void insert(string const &s) 
    {
        trie* head=this;
        for(auto c:s)
        {
            ll d=0;
            if (head->child[c-'a']==NULL)
            { 
                trie* temp=new trie;
                head->child[c-'a']=temp;
                head->childset.push_back(c-'a');
            }
            head=head->child[c-'a'];
            head->depth=++d;
            (head->visits)++;
        }
    }
};

ll res=0;
ll dfs(trie *head,ll level=0)
{
    ll used=0;
    for(ll i:head->childset)
    {
        used=used+dfs(head->child[i],level+1);
    }
    head->visits=head->visits-used;
    ll pair=head->visits/2;
    res=res+pair*(level/2)*(level/2);
    return (pair*2+used);
}

string convert(string const &s)
{
    ll n=s.size();
    string c;
    for(int i=0;i<n;i++)
    {
        c=c+s[i]+s[n-1-i];
    }
    return c;
}

void task()
{
    ll n;
    string s;
    trie *root=new trie;
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>s;
        root->insert(convert(s));
    }
    dfs(root);
    printf("%lld\n",res);
    res=0;
}

int main()
{
    ll t;
    scanf("%d",&t);
    for(ll i=1;i<=t;i++)
        task();
    return 0;
}