#include<stdio.h>
main(){

	int N;
	scanf("%d",&N);
	char input_chars[N];
	int i;
	for(i=0;i<N;i++)
	{
		scanf(" %c",&input_chars[i]);
	}
	char input[100];
	scanf("%s",&input);
	int position=0,j=0; 
	// position store the rank of the word.
	// j stores index of the input charecter set
	int addValue[N];
	for(i=0,j=N-1;i<N;i++,j--)
	   addValue[i] = (1<<j);
	// number of words starting with the 
	
	
	for(i=0,j=0;input[i];i++){
        /*Suppose the characters are A,B,C,D
          and the input string is AD
          while moving from ith character of the string 
          to the i+1 th character we need to surpass all the 
          characters b/w the two. Like for example moving from 
          0th character(A) to 1st character(D) in the input string 
          we need to add the number of strings starting with 
          AB , AC. So for each character we surpassed we just add the 
          number of strings starting with it which is present in addValue[i]
        */
		while(input_chars[j]!=input[i]){ 
			position+=addValue[j];
			j++;
		}
		j++;
		position++;/*Here we increment the position to take care single A in the example
		            for AD to move from A to D we have considered the number of strings starting
                    with AB , AC but we havent considered that A also appears before AD so incrementing
                    the answer by 1 */
	}
	printf("%d\n",position);

	return 0;
}
