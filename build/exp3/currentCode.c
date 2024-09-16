	
		#include<stdio.h>

main(){
  
	int unit_digit;
	scanf("%d",&unit_digit);
	int arr[500];
	int index=0;

    
	int multiplication_digit = unit_digit;
	int carry=0;

	do{
        
		int value = (multiplication_digit*unit_digit+carry);
		arr[index]=value%10;
		carry=value/10; 
		multiplication_digit = arr[index];
		index++;
	}while((multiplication_digit!=unit_digit)||carry);
	
	
	int i;
	for(i=index-2;i>=0;i--)
		printf("%d",arr[i]);
	printf("%d\n",arr[index-1]);
    
	
	return 0;
}