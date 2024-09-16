#include<stdio.h>
main(){
	int N;
	char file_name[100];
	scanf("%s",file_name);
	FILE *f = fopen(file_name,"r");
	int num;
	int length=1;
	int max_length=0,i,curr_num;
	if(fscanf(f,"%d",&num)!=EOF) /* If there is no number in the input file maximum length must be 0,
                                 otherwise it is atleast 1*/
		max_length=1;
		
	while(fscanf(f,"%d",&curr_num)!=EOF){
    // Scan and compute longest subsequence till EOF
		if(curr_num<num)
			length++;
		else
			length = 1;
		if(max_length<length)
			max_length = length;
		num = curr_num;
	}
	printf("%d\n",max_length);
	fclose(f);
	return 0;
}
