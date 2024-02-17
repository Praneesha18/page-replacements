#include<math.h>
#include<stdio.h>
struct arr{
    int pos;
    int ind;
};
struct arr maxfunction(int a[],int n1,int b[],int n2){
    int temp[n1];
    int large;
    int i;
    int index;
    struct arr a1;
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(a[i]==b[j]){
                temp[i]=j;
                break;
            }
        }
    }
    large=temp[0];
    for(i=0;i<n1;i++){
        if(temp[i]>large){
            large=temp[i];
            index=i;
        }
    }
    a1.pos=large;
    a1.ind=index;
    return a1;
    
    
}
int main(){
    int pagefaults=0;
    int i,j,f,r,hits=0;
    struct arr a2;
    printf("enter the size of the frame:");
    scanf("%d",&f);
    int fr[f];
    int max[f];
    printf("enter the size of reference string");
    scanf("%d",&r);
    int rs[r];
    for(i=0;i<r;i++){
        scanf("%d",&rs[i]);
    }
    for(i=0;i<f;i++){
        fr[i]=-1;
    }
    for(i=0;i<r;i++){
        for(j=0;j<f;j++){
            if(fr[j]==rs[i]){
                hits++;
                printf("hit:");
                goto print;
            }
        }
        pagefaults++;
        if(pagefaults<f){
            fr[(pagefaults-1)%f]=rs[i];
        }
        else{
            a2=maxfunction(fr,f,rs,r);
            fr[a2.ind]=rs[a2.pos];
        }
        print:for(int c;c<f;c++){
            printf("%d ",fr[c]);
        }
        printf("\n");
    }
    printf("the total pagefaults is %d\n",pagefaults);
    printf("the total pagehits is %d",hits);
    return 0;
}
