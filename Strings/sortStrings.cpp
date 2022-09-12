/*
eg:-  sample inputs:- 3                              -size of inputs
                      92  022
                      82  12
                      77  13
                      2   false  numeric             -column no. , reverse output or not , type of comparision

     sample output:-  82   12
                      77   13
                      92   022

Explanation:- in 2nd column 12 is smallest 13 is second smallest and than 022 is greatest and we will not reverse the output

Logic:- 1.extract key from every string using tokenization and store (string1,key1)
        2. sort accordingly
        3.check if we have to reverse or not
*/
#include<bits/stdc++.h>
using namespace std;






string extractToken(string str,int key)
{
    char *s=strtok((char *)str.c_str()," ");      //strtok()  accepts char array

    while(key>1)
    {
        s=strtok(NULL," ");
        key--;
    }

    return (string)s;     //converted back to string
}


int convertToInt(string s)
{
    int ans=0;
    int p=1;

    for(int i=s.length()-1;i>=0;i--)
    {
        ans=ans+ ((s[i]-'0')*p);
        p=p*10;
    }

    return ans;
}
bool lexicoCompare(pair<string,string> s1,pair<string,string> s2)
{
    string key1,key2;

    key1=s1.second;
    key2=s2.second;

    return key1 < key2;    //compare two strings

}

bool numericCompare(pair<string,string> s1,pair<string,string> s2)
{
    string key1,key2;

    key1=s1.second;
    key2=s2.second;

    return convertToInt(key1) < convertToInt(key2);
}
int main()
{
    int n;
    cin>>n;

    cin.get();//consume the extra \n

       string temp;
       vector<string> v;

    for(int i=0;i<n;i++)
    {
    getline(cin,temp);   //includes white spaces
    v.push_back(temp);
    }

    int key;
    string reversal,ordering;
    cin>>key>>reversal>>ordering;


   // 1.extract key from every string using tokenization and store (string1,key1)
    vector<pair<string,string>> vp;

       for(int i=0;i<n;i++)
       {
           vp.push_back({v[i],extractToken(v[i],key)});
       }


        //2. sort accordingly

        if(ordering=="numeric")
        {
            sort(vp.begin(),vp.end(),numericCompare);
        }
        else{

            sort(vp.begin(),vp.end(),lexicoCompare);
        }


        //3.reversal

        if(reversal=="true")
        {
            reverse(vp.begin(),vp.end());
        }

        //4.output

        for(int i=0;i<n;i++)
        {
            cout<<vp[i].first<<endl;
        }
}








