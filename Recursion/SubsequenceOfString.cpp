
#include<bits/stdc++.h>
using namespace std;


int findSubseq(string s,string arr[])
{
    if(s.size()==0)
    {
        arr[0]=" ";
        return 1;
    }

    int halfsize=findSubseq(s.substr(1),arr);

    for(int i=0;i<halfsize;i++)
    {
        arr[halfsize+i]=s[0]+arr[i];
    }

    return halfsize*2;
}

int main()
{
    string s;
    cin>>s;

    string arr[50];

    int fullSize=findSubseq(s,arr);
    for(int i=0;i<fullSize;i++)
    {
        cout<<arr[i]<<endl;
    }
}

