#include<queue>
#include<functional>
#include<iostream>

using namespace std;

bool compare(vector<int> a,vector<int> b)
{
    return a[1]<b[1];
}

typedef priority_queue<vector<int>,vector<vector<int>>,function<decltype(compare)>> pqtype;

ostream& operator<<(ostream& stream,const vector<int> &qu )
{
    for(auto i:qu)
    {
        stream<<i<<",";
    }
    return stream;
}

void printq(pqtype qu)
{
    while(!qu.empty())
    {
        cout<<qu.top()<<"\n";
        qu.pop();
    }
}



int main()
{
    pqtype q(compare);

    q.push({2,3});
    q.push({4,3,1});
    q.push({9,9,0});
    q.push({1,0,2});
    q.push({6,5});


    printq(q);
}