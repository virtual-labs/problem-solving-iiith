#include<stdio.h>
main(){
	int N;
	scanf("%d",&N);
	int arr[N],i,j;
	for(i=0;i<N;i++)
		scanf("%d",arr+i);
	int ans = 0;
	int best[N];
	for(i=0;i<N;i++){
		best[i] = 1;
		for(j=0;j<i;j++)
			if(arr[j]<arr[i])
				best[i] = (best[i]>(best[j]+1))?best[i]:best[j]+1;
		if(ans<best[i])
			ans = best[i];
	}
	printf("%d\n",ans);
	return 0;
}
