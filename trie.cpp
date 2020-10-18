#include<iostream>

#include<string>

using namespace std;

class trie
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
    void insert(string &s)
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
        }
        (head->ends)++;
    }

    int searchstring(string &s)
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
    scanf("%d",&n);
    string s;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        root->insert(s);
    }
    cin>>s;
    cout<<root->searchstring(s)<<endl;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
        task();
    return 0;
}
