void swap(int *a,int *b)
{
  int temp=*a;
  *a=*b;
  *b=temp;
}

void heapify(int a[],int n,int i)
{
  int max=i;
  int lc=2*i + 1;
  int rc=2*i + 2;
  if(lc<n && a[lc]>a[max])
  {
    max=lc;
  }
  if(rc<n && a[rc]>a[max])
  {
    max=rc;
  }
  if(a[max] != a[i])
  {
    swap(&a[max],&a[i]);
    heapify(a,n,max);
  }
}

void buildHeap(int a[],int n)
{
  for(int i=n/2;i>=0;i--)
    heapify(a,n,i);
}

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	buildHeap(arr,n);
	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
}
