#include<stdio.h>
main(){
	int p,q;
	scanf("%d%d",&p,&q);
	/* the positive Rational number
	   as represented as p/q*/

	while(1){
		int x = p%q;
		int y = p/q;
		/*y is the quotient
		 Now
		     p/q = y  + (p-q*y)/q;
		     => p/q = y + 1/(q/(p-q*y))
		     => p/q = y+1/(q/x)
		     so now the new pair will be (q,x)
		     and we do this operation again.
		     (p,q) = (q,x)
		*/
		
		if(!x){                      /*If q divides p perfectly result will be num-1 + 1/1*/
            printf("%d\n",y-1);
			break;
		}
		printf("%d ",y);
		p = q;
		q = x;


	}
	return 0;
}
/*
  Hint1: Consider a division operation of A by B.Take a fraction 
         say A=10 and B=3. Now examine how can we obtain q and E
         such that A/B = q + 1/E. 
  Hint2: 
        Now observe that q can be obtained independent of E.
        q = 10/3 = 3. Now try to find E using mathematics. 
  Hint3:
        As suggested in the question E is also to be expressed 
        in terms of fraction.By math A/B = q + (A-q*B)/B
  Hint4:
        From the  expression  in Hint3 
        A/B = q + 1/(B/(A-q*B)). So now 
        E will be B/(A-q*B). We have to do 
        the same process again until A=q*B;
        
*/
