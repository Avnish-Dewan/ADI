#include<bits/stdc++.h>

using namespace std;

struct Item
{
    int profit,weight;
    double ppw;
};

bool compare(struct Item a,struct Item b)
{
    return (a.ppw>b.ppw);
}



int main()
{
    int n,capacity;
    cin>>n;
    struct Item items[n];

    for (int i = 0; i < n; i++)
    {
        cin>>items[i].weight;
        cin>>items[i].profit;
        items[i].ppw=(double)items[i].profit/items[i].weight;
    }
    
    cout<<"Enter Knapsack Capacity:";
    cin>>capacity;
    
    sort(items,items+n,compare);

    // for (int i = 0; i < n; i++)
    // {
    //     cout<<items[i].profit<<" "<<items[i].weight<<endl;
    // }

    int currentWeight=0;
    double finalVal=0.0;

    for (int i = 0; i < n; i++)
    {
        if(items[i].weight+currentWeight<=capacity)
        {
            currentWeight+=items[i].weight;
            finalVal+=items[i].profit;
        }
        else
        {
            capacity=capacity-currentWeight;
            finalVal+=capacity*items[i].ppw;
            break;
        }
        
    }
    cout<<finalVal<<endl;
    

}
