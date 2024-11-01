#include<stdio.h>

struct block{
	int size;
	int isallocated;
	int pallocated;
	int frag;
};

int main(){
	int no_b,no_p;
	printf("Enter the number of blocks: " );
	scanf("%d",&no_b);

	struct block BLOCK[no_b];

	for(int i=0;i<no_b;i++){
		printf("Enter size of block%d :",i);
		scanf("%d",&BLOCK[i].size);
		BLOCK[i].isallocated=0;
		BLOCK[i].pallocated=-1;
		BLOCK[i].frag=BLOCK[i].size;
		
	}

	printf("Enter the number of process: " );
	scanf("%d",&no_p);
	int p_size[no_p];
	for(int i=0;i<no_p;i++){
		printf("Enter size of process%d :",i);
		scanf("%d",&p_size[i]);
	}

	
	
	for(int i=0;i<no_p;i++){
		for(int j=0;j<no_b;j++){
			if(p_size[i]<=BLOCK[j].size && BLOCK[j].isallocated==0){
				int large=j;
				for(int k=j+1;BLOCK[k].size>=p_size[i] &&BLOCK[k].size>=BLOCK[j].size;k++){
					large=k;
				}
				BLOCK[large].isallocated=1;
				BLOCK[large].pallocated=i;
				BLOCK[large].frag=BLOCK[large].size-p_size[i];
				break;
			}
		}
	}

	printf("Block_Number  isallocated	 Allocated_Process 		Block_size    	Fragment\n");
	for(int i=0;i<no_b;i++){
		printf("B%d		 %d			%d			%d			%d\n",i,BLOCK[i].isallocated,BLOCK[i].pallocated,BLOCK[i].size,BLOCK[i].frag);
	}
}


/*
OUTPUT

*/
