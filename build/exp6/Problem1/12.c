#include<stdio.h>
int N;

/*the variable index denotes that I have weights 
  2^index , 2^(index+1), 2^(index+2),...,2^(N-1)
  and W denotes the weight we need to achieve.
*/
int no_ways(int W,int index){
    
    /*If need to achieve W=0 we simply dont choose any weights 
       and it is a solution.. so we return 1.
    */
    
    /*
      if index==N we could not achieve the weight W and so we return 0
         
    */
	if(!W)
		return 1;
	if(index==N)
		return 0;
		
	int i,ans=0;
	/*
	  The variable i indicates that I have choosen
	  i weights of 2^index
	  If I choose i weights of 2^index the 
	  weight we need to achieve becomes W-i*(2^index)
	*/
	for(i=0;i*(1<<index)<=W;i++)
		ans+=no_ways(W-i*(1<<index),index+1);
	return ans;
}
main(){
	int W;
	scanf("%d%d",&N,&W);
	
	printf("%d\n",no_ways(W,0));
	return 0;
}
/*
      Hint1:
             How many ways are there inorder to 
             get a weight W using 2^0,2^1,...,2^(N-1)
             weights.Formulate the problem
             mathematically.
      Hint2:
            Mathematical Formulation: How many tuples
            x1,x2,x3,...,xN are there such that
            x1*2^0+x2*2^1+x3*2^2+...+xN *2^(N-1) = W
            and x1>=0 , x2>=0,...xN>=0.
      Hint3:
            We reformulate the task in a slightly different
            way. How many ways can we achieve a weight W
            given that we can choose any weights from 
            2^i,2^(i+1),..2^(N-1). Suppose we choose x(i)
            number of weights of type 2^i we would need to 
            achieve a weight of W-x(i)*2^i from 2^(i+1),2^(i+2),
            ...,2^(N-1) which leads us to the simple recursive 
            equation no_ways[W][i] = sigma(no_ways[W-x*2^i][i+1])
            , x varies from 0 to W/2^i
      
*/
