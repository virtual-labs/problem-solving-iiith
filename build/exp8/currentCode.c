	
		#include<stdio.h>
#include<string.h>

main(){
	int N;
	char str[1000001];
	scanf("%s",str);
	scanf("%d",&N);
	if(!N)
	{
		printf("0\n");
		return 0;
	}
	int i,j;
	char input_char[N];
	for(i=0;i< N;i++){
		scanf(" %c",&input_char[i]);
	}
	
	int pos[N];
	for(i=0;i< N;i++)
		pos[i]=-1;

	int minLength = strlen(str)+1;

	for(i=0;str[i];i++){
		for(j=0;j< N;j++){
			if(input_char[j]==str[i])
				pos[j]=i;
		}
		int minValue = 1000001;
		for(j=0;j< N;j++)
			if(minValue >  pos[j])
				minValue = pos[j];

		if(minValue!=-1 && minLength> (i-minValue+1)){
			minLength = i-minValue+1;
		}

	}
	if(minLength==strlen(str)+1){
		printf("-1\n");
	}
	else{
		printf("%d\n",minLength);
	}
	return 0;
}