#include<stdio.h>
int func(int N,int *weight,int S){
	if(!S)
		return 1;
		
	if(!N) 
		return 0;
		
	return func(N-1,weight,S-weight[N-1])+func(N-1,weight,S); 
}
main(){
	int N;
	scanf("%d",&N);
	int weight[N],i;
	
	for(i=0;i<N ;i++)
		scanf("%d",weight+i);
	int Sum;
	scanf("%d",&Sum);
	int no_ways = func(N,weight,Sum);
	if(!no_ways)
		no_ways = -1;
	printf("%d\n",no_ways);
	return 0;
}
