#include<stdio.h>
/*the program counts the number of bits in a positve integer*/
main(){
	int n;
	scanf("%d",&n);
	int count=0;
	/*
	   Every positive integer is represented in binary in the computer
	   for example 10 is stored as 000000...1010.
	   Now when we do right shift the number the number of bits will decrease
	   by 1.For 10 after 4 shifts the value will become 0.
	 */
	while(n){
		count++;
		n=n>>1; 
	}
	printf("%d\n",count);
	return 0;
}
