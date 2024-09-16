	
	#include<stdio.h>
main(){
char str1[2000];
char str2[2000];
scanf("%s %s",str1,str2);
int index1,index2;
for(index1=0,index2=0;str1[index1]!='\0'&&str2[index2]!='\0';index1++){
		if(str2[index2]==str1[index1]) 
			index2++;
}
if(str2[index2]=='\0') 
	puts("YES");
else 
	puts("NO");
return 0;
}	