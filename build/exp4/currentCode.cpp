	
#include <stdio.h>
#include <math.h>
main(){
int N,i;
double result = 0;
scanf("%d",&N);

for(i=1;i<=N;i++)
	result+=log10(i);

printf("%d\n",(int)result+1);
return 0;
}