#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

class trie              //prefix trie
{
    public:
    int ends;
    trie *child[26];
    trie()
    {
        ends=0;
        for(int i=0;i<26;i++)
            child[i]=NULL;
    }
    void insert(string const &s) 
    {
        trie* head=this;
        for(auto c:s)
        {
            if (head->child[c-'a']==NULL)
            {
                trie* temp=new trie;
                head->child[c-'a']=temp;
            }
            head=head->child[c-'a'];
            (head->ends)++;
        }
    }

    int searchstring(string const &s)
    {
        trie* head=this;
        for(auto c:s)
        {
            if (head->child[c-'a']==NULL)
            {
                return 0;
            }
            head=head->child[c-'a'];
        }
        return head->ends;
    }

};


void task()
{
    trie* root=new trie;
    int n;
    string query;
    scanf("%d",&n);
    cin.ignore();
    for(int i=1;i<=n;i++)
    {
        getline(cin,query);
        root->insert(query.substr(4));
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
        task();
    return 0;
}