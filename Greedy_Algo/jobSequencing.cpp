#include<bits/stdc++.h>

using namespace std;

struct Job
{
    char id;
    int deadline,profit;
    /* data */
};

bool compare(struct Job a,struct Job b)
{
    return (a.profit>b.profit);
}

int main()
{
    int n;
    cin>>n;
    int max=INT_MIN;
    struct Job jobs[n];
    for (int i = 0; i < n; i++)
    {
        cin>>jobs[i].id;
        cin>>jobs[i].deadline;
        cin>>jobs[i].profit;
        if(max<jobs[i].deadline)
        {
            max=jobs[i].deadline;
        }
    }

    char available[max+1];
    memset(available,'-',sizeof(available));
    sort(jobs,jobs+n,compare);
    
    int profit=0;

    for (int i = 0; i < n; i++)
    {
        if (available[jobs[i].deadline]=='-')
        {
            available[jobs[i].deadline]=jobs[i].id;
            profit+=jobs[i].profit;
        }
        else
        {
            int j = jobs[i].deadline;
            while(j>0)
            {
                if (available[j]=='-')
                {
                    available[j]=jobs[i].id;
                    profit+=jobs[i].profit;
                    break;
                }
                j--;
            }
        }
    }

    for (int i = 1; i < max+1; i++)
    {
        cout<<available[i]<<" ";
    }
    cout<<endl<<profit<<endl;
    
    
}