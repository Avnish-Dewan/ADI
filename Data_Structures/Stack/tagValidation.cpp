#include<bits/stdc++.h>

using namespace std;

bool validateTags(string s)
{
    stack<string> st;

    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == '<' && s[i+1]!='/')
        {
            string tag;
            while(s[i]!='>' && i<s.length())
            {
                tag+=s[i++];
            }
            tag+=s[i];
            st.push(tag);
        }
        else if(s[i] == '<' && s[i+1]=='/')
        {
            string tag;
            while(s[i]!='>' && i<s.length())
            {
                tag+=s[i++];
            }
            tag+=s[i];
            tag.erase(remove(tag.begin(), tag.end(),'/'),tag.end());

            if(tag.compare(st.top()) == 0)
                st.pop();
            else
                return false;
        }
    }
    if(st.empty())
        return true;
    return false;
}

int main()
{
    string s;
    ifstream fin("test.html");// change The File Name As Per file
    char c;
    while (fin.eof() == 0)
    {
        fin.get(c);
        if(fin.eof()==0)
            s+=c;
    }
    // cout<<s;

 
    
    cout<<validateTags(s)<<endl;
}
