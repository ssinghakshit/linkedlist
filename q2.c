#include<stdio.h>
#include<stdlib.h>

//hello stupid
void main(){
    int n=rand()%10;
    int a[n];
    printf("\nEnter array elements: ");
    for(int i=0;i<n;i++){
        a[i]=rand()%10;
    }
    int i,j;
    printf("\nArray: ");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    int temp;
    for(i=1;i<n;i++){
        if(a[i]<10){
            temp=a[i-1]+1;
            while(temp%10!=a[i]){
                temp++;
            }
            a[i]=temp;
        }
        else if(a[i]>=10){
            int rem,quo,first,second,check;
            temp=a[i-1]+1;
            first=a[i]%10;
            second=a[i]/10;
            rem=temp%10;
            quo=temp/10;
            while((quo!=second || rem!=first) && (quo!=first || rem!=second)){
                check=0;
                rem=temp%10;
                quo=temp/10;
                if(temp>=100){
                    if(a[i]==quo || a[i]==quo+rem){
                        check=1;
                        break;
                    }
                }
                temp++;
            }
            if(check==0){
                temp--;
            }a[i]=temp;
        }
    }
    printf("\nArray: ");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
