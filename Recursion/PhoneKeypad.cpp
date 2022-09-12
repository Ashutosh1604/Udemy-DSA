/*
given a number N and a modern phone keypad.Find out all possible strings generated using that number

eg:- input:- 23
      output:- AD,AE,AF,BD,BE,BF,CD,CE,CF
*/

#include<bits/stdc++.h>
using namespace std;


string keypad[]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void printKeypadOutput(string input,string output,int i)
{
 if(i==input.size())
 {
     cout<<output<<endl;
     return;
 }

 int curr_digit=input[i]-'0';  //to convert current character into integer

 if(curr_digit==0 || curr_digit==1)
 {
     printKeypadOutput(input,output,i+1);
 }

 for(int k=0;k<keypad[curr_digit].size();k++)
 {
     printKeypadOutput(input,output+keypad[curr_digit][k],i+1);
 }
}

int main()
{
    string input;
    cin>>input;

    string output;

    printKeypadOutput(input,output,0);

}
