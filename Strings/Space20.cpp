
/*
Given string write a function to replace all spaces in a string with '%20' it is given that the string has sufficient space
at the end to hold the additional characters
*/

//1st approach
//start from left as we incounter space put %20 and shift remaining string by 2 more places


//2nd approach
//calculate the no. of spaces eg:- if there are 5 space we need to store 10 characters as space for 1 char is already there only 2 char space need to be created
//so we traverse from right and shift characters and as we get space we store '%20'
#include<bits/stdc++.h>
using namespace std;


void replace_space(char *str)
{
    //calculating total spaces
    int spaces=0;
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]==' ')
        {
            spaces++;
        }
    }

    //to teminate string
    int idx=strlen(str) + 2*spaces;
    str[idx]='\0';


    //shifting and storing
    for(int i=strlen(str)-1;i>=0;i--)
    {
          if(str[i]==' ')
          {
             str[idx-1]='0';
             str[idx-2]='2';
             str[idx-3]='%';

             idx=idx-3;
          }
          else{
            str[idx-1]=str[i];
            idx--;
          }
    }
}
int main()
{
 char input[10000];
 cin.getline(input,1000);
 replace_space(input);
 cout<<input<<endl;


}
