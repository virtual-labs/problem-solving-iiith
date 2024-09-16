#include<stdio.h>
int main(){
	int N;
	scanf("%d",&N);
	int ans=0;
	while(N){
		ans+=N/5;N/=5;
	}
	printf("%d\n",ans);
	return 0;
}
