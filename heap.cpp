
//heap sort

void heapify(int arr[],int n,int i)
{
   int large=i;
   int left=2*i+1;
   int right=2*i+2;
   if((left<n )&& (arr[left]>arr[large]))
   {
	large=left;
   }
   if((right<n)&&(arr[right]>arr[large]))
   {
	large=right;
   }
   if(large!=i)
   {
	swap(large,arr[i]);
   }
   heapify(arr,n,large);

}
void heapsort(int a[],int n)
{
	 for (int i = n / 2 - 1; i >= 0; i--)  
        heapify(a, n, i);   
     for (int i = n - 1; i >= 0; i--) {   
        int temp = a[0];  
        a[0] = a[i];  
        a[i] = temp;  
          
        heapify(a, i, 0);  
    } 
}
int main()
{
	int a[20]={10,30,20,40,60,15,25};
	int n=sizeof(a)/sizeof(a[0]);
	heapsort(a,n);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	
} 


