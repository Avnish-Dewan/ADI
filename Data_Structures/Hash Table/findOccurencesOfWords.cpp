#include<bits/stdc++.h>

using namespace std;

void countOccurences(string s)
{
    vector<string> v;
    //char delim[2]=" ";
    char str1[s.length()];

    strcpy(str1,s.c_str());
    // cout<<str1;
    char *str=strtok(str1," ");
    while (str!=NULL)
    {
        string s1(str);
        v.push_back(s1);
        str=strtok(NULL," ");
    }
    
    map<string,int> mp;

    for(int i=0;i<v.size();i++)
    {
        mp[v[i]]++;
    }

    for(auto it=mp.begin();it!=mp.end();it++)
    {
        cout<<it->first<<"-->"<<it->second<<endl;
    }
}

int main()
{
    string s;
    getline(cin,s);
    // cout<<s;
    countOccurences(s);
}