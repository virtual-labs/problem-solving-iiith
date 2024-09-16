#include<stdio.h>
int isPossible(int N,int D,int *weight){
    /*
       if D is 0 we dont keep any weights on any side 
       and achive it. Hence we return 1 indicating that 
       a solution is possible. 
    */
	if(!D)
		return 1;
	/*
	    if N has become 0 we have exhausted all weights but could not
	    achieve the weight D . Hence we return 0 indicating  no solution.
	*/
	if(!N) return 0;
	
	/*
	   With  weight[N-1] we have 3 possibilites 
	   1.Add the weight on left side in which case we need to achieve D+weight[N-1]
	   2.Add the weight on right side in which case we need to achieve D-weight[N-1]
	   3.Dont add this weight on any side so we need to achive a weight of D.
	*/
	return isPossible(N-1,D+weight[N-1],weight)||isPossible(N-1,D-weight[N-1],weight)||isPossible(N-1,D,weight);
}
main(){
    //Assume weight D is on left side and we are adding other weights on any side.
	int N,D;
	scanf("%d",&N);
	int weight[N],i;
	
	//scanning weights 
	for(i=0;i<N;i++)
		scanf("%d",weight+i);
		
	//scanning Destination weight	
	scanf("%d",&D);
	
	
	if(isPossible(N,D,weight)){
		printf("YES\n");
	}
	else
		printf("NO\n");
	return 0;
}
/*
   Hint1:
         Assume you are given 2 pans and you have N 
         weights.Now think what are you goin to do with 
         each weight.
   Hint2:
         Following up from Hint1 consider any weight.
         We can either keep it on left pan or the right
         pan or we dont keep it at all on either.Now think
         what must we need to keep track of.
   Hint3:
         We just need to keep track of the difference of 
         weights say difference between weights in left 
         pan and right pan.If we are to keep the ith weight
         in left pan the difference will increase by 
         weight[i], if we keep it in right pan the 
         difference would decrease by weight[i] or we 
         may not keep the ith weight on either pan in 
         which case the difference would remain same.
         Now if by any of the above 3 ways we were able
         to achieve  a weight difference of D then we 
         report yes else no.
*/
