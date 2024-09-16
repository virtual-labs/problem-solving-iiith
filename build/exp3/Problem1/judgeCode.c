#include<stdio.h>

/*calculates the sum of digits  of the number*/
int sum_digits_number(long long n){
	int sum=0;
	while(n){
		sum+=n%10;
		n/=10;
	}
	return sum;
}

int main(){
	long long n;
	scanf("%lld",&n);
	/*we go on calculating the sum of the digits 
	  of the resulting number until it becomes less
	 than or equal to 9*/
	while(n>9){
          n=sum_digits_number(n);
    }
	
	if(n==9)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
/*
   Hint1:
          See the sample example2 to observe what is to do
          be done.
   Hint2:
          We are repeatedly calculating the sum of digits
          of the number.It is fairly obvious how to calculate  
          the sum of the digits.
   Hint3:
         We do the above operation again and again until the 
         sum of the digits is becomes lesser than 10.If it reaches
         9 then yes the number is divisible by 9.
   
*/
