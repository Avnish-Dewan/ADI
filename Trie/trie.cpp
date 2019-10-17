#include<bits/stdc++.h>

using namespace std;

class Trie
{
    struct Node
    {
        // char data;
        struct Node* arr[26];
        bool isEndOfWord;
        Node()
        {
            isEndOfWord=false;
            for(int i=0;i<26;i++)
            {
                arr[i]=NULL;
            }
        }
    };
    struct Node* root;
    public:
        Trie()
        {
            root=new struct Node();
        }

        void insert(string s)
        {
            struct Node* curr = root;
            for(int i = 0;i<s.length();i++)
            {
                if(curr->arr[s[i] - 'a'] == NULL)
                {
                    curr->arr[s[i]-'a']= new struct Node;
                }
                curr = curr->arr[s[i]-'a'];
            }
            curr->isEndOfWord=true;
        }
        bool searchString(string str)
        {
            struct Node *curr=root;
            for(int i=0;i<str.length();i++)
            {
                if(curr->arr[str[i]-'a']==NULL)
                    return false;
                
                curr=curr->arr[str[i]-'a'];
            }
            return (curr!=NULL&& curr->isEndOfWord);
        }
};




int main()
{
    
    int n;
    cin>>n;
    string str[n];
    for(int i=0;i<n;i++)
        cin>>str[i];
    Trie t1;
    for(int i=0;i<n;i++)
        t1.insert(str[i]);
    
    string s;
    cin>>s;
    if(t1.searchString(s))
        cout<<"Yes\n";
    else
        cout<<"No\n";
}
