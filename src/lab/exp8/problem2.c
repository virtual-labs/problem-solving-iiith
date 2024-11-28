#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b){
	return *((int *)a)>*((int *)b);
}
int search(int *a,int start,int end,int num){
	if(start>end)
		return 0;
	int mid = (start+end)>>1 ;
	if(a[mid]>num)
		return (end-mid+1)+search(a,start,mid-1,num);
	else
		return search(a,mid+1,end,num);
}
main(){
	int N;
	scanf("%d",&N);
	int arr[N];
	int i,j;
	for(i=0;i< N;i++)
		scanf("%d",arr+i);
	qsort(arr,N,sizeof(int),compare);
	int ans=0;
	for(i=0;i< N;i++)
		for(j=i+1;j< N;j++)
			ans+=search(arr,0,N-1,arr[i]+arr[j]);
	printf("%d\n",ans);
	return 0;
}
