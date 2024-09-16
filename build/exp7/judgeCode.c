#include<stdio.h>
#include<math.h>
main(){
	int num;
	float root,mid,l_limit,u_limit ;
	fscanf(stdin,"%d",&num); // Scan the number
	l_limit=1;		 // Lower limit
	u_limit=num;		 // Upper Limit
	mid=(1+num)/2;		 // Middle Value
	root=mid;		
	while(fabs(root*root-num)>0.01)
	{
		if(root*root<num)
			l_limit=mid;	  // Updating the value of lower limit because estimated root is less than required	
		else
			u_limit = mid;    // Updating the value of upper limit because estimated root is more than required
		mid=(u_limit+l_limit)/2;  // Updating the value of mid
		root=mid;                
	}
	printf("%f\n",root);
	return 0;
}
