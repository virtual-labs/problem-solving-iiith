#include<stdio.h>

main(){
  
	int unit_digit;
	scanf("%d",&unit_digit);
	int arr[500];
	/*The arr array will store the product of the number required with its unit digit
	It will not store the value we need.
	*/
    /*assuming that the output number will be less than 500 digits*/
	int index=0;

    /*multiplication digit is the digit to be multiplied with unitdigit/input number*/
    
	int multiplication_digit = unit_digit;
	int carry=0;

	do{
        
		int value = (multiplication_digit*unit_digit+carry);
		arr[index]=value%10;
		carry=value/10; 
		multiplication_digit = arr[index];//calculates the next digit to be multiplied 
		index++;
	}while((multiplication_digit!=unit_digit)||carry);//for the number to be circular the digit last calculated is same as input
	
	
	int i;
	for(i=index-2;i>=0;i--)
		printf("%d",arr[i]);
	printf("%d\n",arr[index-1]);
    
	
	return 0;
}
/*
      Hint1:
            See what is given. We know the units digit
            and also the number with which we multiply is 
            the same say it is x.Consider say x=4 case.
      Hint2:
            Now see what the problem wants us to do.
            It just simply wants us to multiply initially
            x with itself. For x=4 we get 16, 
            6 is to be written down and 1 will be the carry.
      Hint3:
            Check the question again.It wants the number to be
            circular. Suppose assume the answer is pqrx. Now when 
            we multiply x we need to get xpqr, which means
            units digit in product must be same as 10's place 
            in the number and 10's place in the product must be
            same as 100's place in the number.Now use this hint.
      Hint4:
            Following the  Hint3, consider the example for x=4
            and start work with it. 4*4 = 16. So 6 must be in 
            units place of product and thus must be the 10's place
            in the actual number and 1 is the carry. ****64 is 
            the number till now and the product is ****6.
            Now multiply the 6 with '4' and add  the carry. 
            6*4+1 = 25. So now the carry becomes 2 and 
            10's digit in product is 5.So the product will become
            ****56 and the number now will be ****564.Continue
            doing the same process and it is a simple exercise
            when to terminate this process.
*/
