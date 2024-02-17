#include<stdio.h>
int main(){
    int hits=0;
    int pagefaults=0;
    int r_length;
    int i;
    int f_length;
    printf("enter the size of the frame:");
    scanf("%d",&f_length);
    int f[f_length];
    printf("enter the size of the reference string:");
    scanf("%d",&r_length);
    int rf[r_length];
    printf("enter the values of reference string:");
    for(i=0;i<r_length;i++){
        scanf("%d",&rf[i]);
    }
    for(i=0;i<f_length;i++){
        f[i]=-1;
    }
    for(i=0;i<r_length;i++){
        for(int j=0;j<f_length;j++){
            if(f[j]==rf[i]){
                hits++;
                printf("hit:");
                goto print;
            }
        }
         pagefaults++;
            f[(pagefaults-1)%f_length]=rf[i];
            print:for(int c=0;c<f_length;c++){
                printf("%d ",f[c]);
            }
            printf("\n");
    }
    printf("total pagefaults is %d\n",pagefaults);
    printf("total hits is %d\n",hits);
    return 0;
}
