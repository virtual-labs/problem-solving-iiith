#include<stdio.h>
int main(){

	int N,count=0;
	scanf("%d",&N);
	while(N){
		        N>>=1;
			        count++;
	}
	printf("%d\n",count);

	return 0;
}
