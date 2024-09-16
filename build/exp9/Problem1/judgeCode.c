#include<stdio.h>
int func(int N,int *weight,int S){
	if(!S)// If target weight has been achieved, we have found a solution.
		return 1;
		
	if(!N) // We have exhausted all the weights
		return 0;
		/* Case1: We consider the weight for the solution
           Case2: We discard the weight for the solution
           */
	return func(N-1,weight,S-weight[N-1])+func(N-1,weight,S); 
}
main(){
	int N;
	scanf("%d",&N);
	int weight[N],i;
	// Weight array stores the respective weights
	for(i=0;i<N;i++)
		scanf("%d",weight+i);
	int Sum;
	scanf("%d",&Sum);
	int no_ways = func(N,weight,Sum);
	if(!no_ways)
		no_ways = -1;
	printf("%d\n",no_ways);
	return 0;
}
