#include<bits/stdc++.h>

using namespace std;

class hashTable
{
    int capacity;
    list<int> *hash;

    public:
        hashTable(int cap)
        {
            this->capacity=cap;
            hash=new list<int>[cap];
        }

        int hashFunc(int x)
        {
            return x%capacity;
        }

        void insert(int data)
        {
            int index=hashFunc(data);
            hash[index].push_back(data);
        }

        void displayHashTable()
        {
            for(int i = 0;i<capacity;i++)
            {
                cout<<i;
                for(auto it=hash[i].begin();it!=hash[i].end();it++)
                {
                    cout<<"--> "<<*it<<' ';
                }
                cout<<endl;
            }
        }
};

int main()
{
    hashTable ht(10);
    int n;
    cin>>n;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        ht.insert(x);
    }
    cout<<endl;
    ht.displayHashTable();
}