#include<bits/stdc++.h>
using namespace std;


char *mystrtok(char *str,char delin){
static char *input=NULL;
if(str!=NULL)
{
    input=str;
}
if(input==NULL)
{
    return NULL;
}

char *token =new char[strlen(input)+1];         //we created dynamic array so that we can return it

int i=0;

for( ;input[i]!='\0';i++)
{
    if(input[i]!=delin)
    {
        token[i]=input[i];
    }
    else
    {
      token[i]='\0';
      input=input+i+1;     //input is going to point element after i
      return token;
    }
}

//out of the loop
token[i]='\0';
input=NULL;
return token;


}
int main()
{
    char s[1000];
    cin.getline(s,1000);


    char *token=mystrtok(s,' ');

    while(token!=NULL)
    {
        cout<<token<<endl;
        token=mystrtok(NULL,' ');
    }
}
