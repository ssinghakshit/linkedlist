#include<stdio.h>
#include<stdlib.h>
void display(int **a_20051716,int x_20051716,int y_20051716,int k_20051716){
	for(int i=x_20051716;i<x_20051716+k_20051716;i++){
		for(int j=y_20051716;j<y_20051716+k_20051716;j++){
			printf("%d ",a_20051716[i][j]);
		}
		printf("\n");
	}
	printf("____________________\n");
}
void solving(int **a_20051716,int n_20051716,int s_20051716,int b_20051716){
	for(int i=0;i<=n_20051716-b_20051716;i++){
		for(int j=0;j<=n_20051716-b_20051716;j++){
			int sum_20051716=0;
			for(int k=0;k<b_20051716;k++){
				for(int l=0;l<b_20051716;l++){
					sum_20051716=sum_20051716+a_20051716[i+k][j+l];
				}
			}
			if(sum_20051716==s_20051716){
				display(a_20051716,i,j,b_20051716);
			}
		}
	}
}
int main(){
	int n_20051716=9;
	int **a_20051716=(int **)malloc(sizeof(int *)*n_20051716);
	for(int i_20051716=0;i_20051716<n_20051716;i_20051716++){
		a_20051716[i_20051716]=(int *)malloc(sizeof(int)*n_20051716);
	}
	for(int i_20051716=0;i_20051716<n_20051716;i_20051716++){
		for(int j_20051716=0;j_20051716<n_20051716;j_20051716++){
			a_20051716[i_20051716][j_20051716]=rand()%10;
		}
	}
	printf("Original array: \n");
	display(a_20051716,0,0,n_20051716);
	int k_20051716=43;
    printf("Sum: %d\n\n",k_20051716);
    printf("Submatrix: \n");
	for(int i_20051716=1;i_20051716<n_20051716;i_20051716++)
	solving(a_20051716,n_20051716,k_20051716,i_20051716);
}