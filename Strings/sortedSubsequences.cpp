/*
You are given a string a string you need to print all the subsequences of the sting sorted by length
 and lexicographic sorted order if length is same.


 eg:- input:- abcd

      output:- ,a,b,c,d,ab,ac,ad,bc,bd,cd,abc,abd,acd,bcd,abcd,
*/
#include<bits/stdc++.h>
using namespace std;


int subseq(string str,string ans[])
{

    if(str.length()==0)
    {
        ans[0]=" ";
        return 1;
    }
    int halflength=subseq(str.substr(1),ans);

    for(int i=0;i<halflength;i++)
    {
        ans[halflength+i]=str[0] + ans[i];
    }

    return halflength*2;
}

bool compare(string s1,string s2)
{
    if(s1.length()==s2.length())
    {
        return s1<s2; //lexographic comparision
    }
    else{
        return s1.length()<s2.length(); //length comparision
    }
}
int main()
{
    string str="abcd";

    string ans[30];

    int fullLength=subseq(str,ans);

    cout<<"BEFORE SORT:-";
    for(int i=0;i<fullLength;i++)
    {
        cout<<ans[i]<<",";
    }
         cout<<endl;

    sort(ans,ans+fullLength,compare);

    cout<<"AFTER SORT:-";
     for(int i=0;i<fullLength;i++)
    {
        cout<<ans[i]<<",";
    }
}






