#include<stdio.h>
#include<math.h>


double mysqrt(int N){
	double ans = 1;
	double error = 1e-4;
	//implementing the Newton Raphson's method.
	while(fabs(ans*ans-N)>error){
		ans = (ans + N/ans)/2.0;
	}
	return ans;
}
main(){
	int N;
	scanf("%d",&N);
	printf("%.4lf\n",mysqrt(N));//prints the squareroot of the number upto 6 digits
}
