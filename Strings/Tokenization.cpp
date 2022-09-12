/*
Tokenizing a string denotes splitting a string with respect to some delimiter(s)

eg:- input- "today is a sunny day"
    output- "today","is","a","sunny","day"

    methods:- 1.using stringstream class
              2.using strtok function
*/


#include<bits/stdc++.h>
using namespace std;

//using stringstream
/*
int main()
{
    string input;
    getline(cin,input);

    //create a string stream object

    stringstream ss(input);

    //this object supports the left and right shift operators which allows to read and write data to this string
    string token;
    vector<string> tokens;
    while(getline(ss,token,' '))   //it will read one word and put inside token as it encounter space
    {
        tokens.push_back(token);
    }

    for(auto token:tokens){
        cout<<token<<",";
    }
}
*/


//using strtok
int main()
{
    char input[1000];
    cin.getline(input,1000);

   char *token= strtok(input," ");



   while(token!=NULL)
   {
       cout<<token<<endl;
       token=strtok(NULL," ");
   }
}


















