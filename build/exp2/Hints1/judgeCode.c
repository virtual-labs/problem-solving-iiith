#include<stdio.h>
#include<math.h>
main(){
	/*perfect number or not*/
	
	long long n;
	scanf("%lld",&n);
	long long sum_factors = 0;
	long long temp = (int)sqrt((double)n);long long i;
	/*Finding the sum of the divisors
	using that fact that if I is a divisor n/I
	  is also a divisor*/
	
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
/*
   Hint1 : To check if a number is a perfect number or not
           we need to find the sum of the divisors and compare with n
   Hint2 : 
           Now the task is to find the sum of the divisors.
           One way is to check if every number in closed interval [1 n-1]
           is a divisor of n.Now think of optimising it. Can we do any better.
           Can we utilize any property which can reduce the range of the 
           search from [1 n-1] to anything less.
           
   Hint3: 
          We now note that any divisor cant be  greater than ceil(n/2).
          Using this idea we can do a optimization.But can we still do any better?
          Think of how we solve the problem of finding whether a given number
          is prime or not.The same idea can be applied here
   Hint4:
          
          While checking whether a number if prime or not we check for
          divisors lesser than or equal to sqrt(n).So thinking on the 
          same lines we use the property if P is a divisor of N then 
          so is N/P and limit on P will be sqrt(N).   
   
*/
