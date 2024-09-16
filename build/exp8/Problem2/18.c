#include<stdio.h>

// Stores (i,j) and distance to each mine for a cell
struct node{
	int x,y;
	int d;
};
main(){
	int N;
	scanf("%d",&N);
	
	
    int i,j;
	struct node point[N*N];int p=0;
	
	int arr[N][N];//arr[i][j] stores the final answer.
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			arr[i][j]=-1;
     //if arr[i][j]=-1 it means that we are yet to explore that cell.
        int a,b;     
        while(scanf("%d%d",&a,&b)==2){
			    a--;b--;
				point[p].x = a;
				point[p].y = b;
				point[p].d=0;
				arr[a][b]=0;//the minimum distance from a mine to itself is 0
				p++;
			
	}
	

	
	int dx[]={0,0,-1,-1,-1,1,1,1};
	int dy[]={-1,1,0,1,-1,0,1,-1};
	/*dx,dy are used to explore the neighbours of a cell
	 if (i,j) is not a cell then (i+dx[k],j+dy[k]) for all 
	 0<=k<=7 is a neighbour of a cell. Note that (i+dx[k],j+dy[k]) 
	 may be invalid location. 
	*/
	/*if (i,j) is at a minimum distance d from one of 
	  the mines then its neighbour will be at a distance of d+1
	  */
	    int index;
    	for(index=0;index<N*N;index++){
         /*index deontes that we are considering point[index] currently
           if index is equal to all the number of points in grid
           it means that we have explored all points 
         */
         //start exploring the neighbours now
		for(i=0;i<8;i++){
                         
			int a=point[index].x+dx[i],b=point[index].y+dy[i],d=point[index].d+1;
			//check if (a,b) is a valid point in grid and it has not been explored yet
			if(a>=0 && b>=0 && a<N && b<N && arr[a][b]==-1){
				arr[a][b]=d;
				point[p].x = a;
				point[p].y = b;
				point[p].d= d;
				p++;
			}
		}
	}

    //printing the answer
	for(i=0;i<N;i++,puts(""))
		for(j=0;j<N;j++){
				if(arr[i][j]!=0)
					printf("%d ",arr[i][j]);
				else
					printf("X ");
		}
	
	return 0;
}
