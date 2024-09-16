	
		#include<stdio.h>
#include<math.h>
int N;
double mysqrt(double start,double end){

	
	double mid = (start+end)/2;

	if(fabs(mid*mid-N)<=1e-4)
		return mid;

	if(mid*mid > N){
		return mysqrt(start,mid-1);
	}
	else {
		return mysqrt(mid+1,end);
	}

}
main(){
	scanf("%d",&N);
	printf("%.4lf\n",mysqrt(1,N));
return 0;
}