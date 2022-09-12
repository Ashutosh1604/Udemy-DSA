
//code by- ASHUTOSH DHYANI
//the recursive call will be equal to the length of string
#include<bits/stdc++.h>
#include<string>
using namespace std;


void AllPermutations(string str,string ans)
{

if(str.length()==0)         //base case
{
    cout<<ans<<" ";        //when string is empty print output and return
    return;
}

for(int i=0;i<str.length();i++)               //traverse each element of input string
{
    char ch=str[i];     //take out the current element
    //ans=ans+ch;

    string leftSubstr=str.substr(0,i);
    string rightSubstr=str.substr(i+1);

    string rest=leftSubstr+rightSubstr;        //take out the rest elements

    AllPermutations(rest,ans+ch);            //recursive call with rest of the elements as string and add the ch to the output
}



}
int main()
{
    string str="ABC";   //input

    string ans;       //output string
    AllPermutations(str,ans);
}
