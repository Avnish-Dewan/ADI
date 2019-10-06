#include<bits/stdc++.h>

using namespace std;

struct Interval
{
    int start,end;
};

bool compare(struct Interval a,struct Interval b)
{
    return (a.end<b.end);
}

int main()
{
    int n;
    cin>>n;

    struct Interval intervals[n];

    for (int i = 0; i < n; i++)
    {
        cin>>intervals[i].start>>intervals[i].end;
    }

    sort(intervals,intervals+n,compare);

    int count=1,i=intervals[0].end,j=1;
    while(j<n)
    {
        if(intervals[j].start>=i)
        {
            i=intervals[j].end;
            count++;
        }
        //  cout<<i<<endl;
        j++;
    }
    cout<<endl<<count<<endl;
}
