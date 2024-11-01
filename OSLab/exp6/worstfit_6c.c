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
		int large=-1;
		for(int j=0;j<no_b;j++){
			if(BLOCK[j].size >=p_size[i]&& BLOCK[j].isallocated==0){
				if(large==-1){
					large=j;				
				}
				else if(BLOCK[j].size>BLOCK[large].size){
					large=j;
				}
			}
		}
		if(large!=-1){
			BLOCK[large].isallocated=1;
			BLOCK[large].pallocated=i;
			BLOCK[large].frag=BLOCK[large].size-p_size[i];
		}
	}

	printf("Block_Number  isallocated   Allocated_Process 	Block_size    Fragment\n");
	for(int i=0;i<no_b;i++){
		printf("   %d	  	%d		%d		   %d		%d\n",i,BLOCK[i].isallocated,BLOCK[i].pallocated,BLOCK[i].size,BLOCK[i].frag);
	}
}


/*
OUTPUT

pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp6$ gcc worstfit_6c.c
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp6$ ./a.out
Enter the number of blocks: 4
Enter size of block0 :10
Enter size of block1 :20
Enter size of block2 :30
Enter size of block3 :40
Enter the number of process: 5
Enter size of process0 :25
Enter size of process1 :15
Enter size of process2 :8
Enter size of process3 :6
Enter size of process4 :10
Block_Number  isallocated   Allocated_Process 	Block_size    Fragment
    0	  	 1		3		   10		4
    1	  	 1		2		   20		12
    2	  	 1		1		   30		15
    3	  	 1		0		   40		15

*/
