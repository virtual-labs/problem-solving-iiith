#include<stdio.h>
int N;

int f2(int *arr,int *mark,int index,int S){
	if(index==N){
		int flag=0,i;
		for(i=0;i<N;i++)
			if(mark[i] && S==arr[i]){
				++flag;
			}
		return flag;
	}
	mark[index]=0;
	int x1 = f2(arr,mark,index+1,S+arr[index]);
	mark[index]=1;
	int x2 = f2(arr,mark,index+1,S);
	return x1+x2;
}
main(){
		scanf("%d",&N);
		int arr[N];
		int i;
		for(i=0;i<N;i++)
			scanf("%d",arr+i);
		int mark[N];
		for(i=0;i<N;i++)
			mark[i]=1;
		printf("%d\n",f2(arr,mark,0,0));

}
