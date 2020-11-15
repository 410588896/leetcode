
/*******************************
* merge sort
* 稳定
* 时间复杂度O(nlogn)
* 空间复杂度O(n)
*******************************/
void merge(vector<int> &arr,int L,int mid,int R)
{
	int *help = new int(R-L+1);
	int p1=L,p2=mid+1,i=0;
	while(p1<=mid && p2<=R)
	{
		help[i++] = arr[p1]>arr[p2] ? arr[p2++] : arr[p1++];
	}
	while(p1<=mid)
		help[i++] = arr[p1++];
	while(p2<=R)
		help[i++] = arr[p2++];
 
	for (int i=0;i<R-L+1;i++)
	{
		arr[L+i] = help[i];
	}
}
void merge_sort(vector<int> &arr,int L,int R)
{
	if (L < R)
	{
		int mid = L + ((R-L)>>2);  //  (L+R)/2
		merge_sort(arr,L,mid);
		merge_sort(arr,mid+1,R);
		merge(arr,L,mid,R);
	}
}
 
void MergeSort(vector<int> &arr,int L,int R)
{
	if (arr.size()<2)
		return;
	merge_sort(arr,L,R);
}

