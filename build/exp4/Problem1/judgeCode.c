#include<stdio.h>
#include<math.h>
int main(){
	int N,i;
	scanf("%d",&N);
	double ans=0;
	for(i=1;i<=N;i++){
		ans+=log10(i);
	}
	printf("%d\n",(int)ans+1);
	return 0;
}

