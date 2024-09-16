#include<stdio.h>
main(){
	int N=10,i;
	srand(time(NULL));
	printf("%d\n",N);
	for(i=0;i<N;i++)
		printf("%d\n",rand()%100+1);
	return 0;
}
