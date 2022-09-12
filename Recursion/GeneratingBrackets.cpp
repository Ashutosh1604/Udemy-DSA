/*
write  a function to generate all possible n pairs of balanced parantheses '(' and ')'.

eg:- input=2

   output:-()()
           (())
*/

/*rules:- 1. if we are placing a closing bracket there should be a opening bracket before.
          2.  open < N

*/
#include<bits/stdc++.h>
using namespace std;


void generateBrackets(string output,int n,int open,int close,int i)
{

    if(i==2*n)
    {
        cout<<output<<endl;
        return;
    }

    //open
    if(open<n)
    {
        generateBrackets(output + '(',n,open+1,close,i+1);
    }
    //close
    if(close<open)
    {
        generateBrackets(output + ')',n,open,close+1,i+1);
    }

}
int main()
{
    int n;
    cin>>n;
    string output;
    generateBrackets(output,n,0,0,0);
}

