	
#include<stdio.h>
int sum_digits(long long n){
	return n?(n%10)+sum_digits(n/10):0;
}


int main(){
	long long n;
	scanf("%lld",&n);
	/*we go on calculating the sum of the digits 
	  of the resulting number until it becomes less
	 than or equal to 9*/
	while(n&gt9)
          n=sum_digits(n);
    
	
	if(n==9)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
