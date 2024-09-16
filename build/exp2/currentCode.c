	
#include<stdio.h>
#include<math.h>
main(){
	/*perfect number or not*/
	
	long long n;
	scanf("%lld",&n);
	long long sum_factors = 0;
	long long temp = (int)sqrt((double)n);
	long long i;
	
	for(i=2;i<=temp;i++){
		if(n%i==0)
			sum_factors+=i+(n/i);
	}
	if(n>1) //adding 1 to the sum of factors if n>1
		sum_factors++;

	/*if the number is a perfect square then 
	 observe that the square root gets added twice , i=n/i will occur */
	if(n==temp*temp) 
		sum_factors-=temp;
	if(sum_factors==n)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}		