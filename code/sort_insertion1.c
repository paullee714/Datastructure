#include <stdio.h>
#define LEN 10
int main()
{    
    int s[LEN] = { 22, 10, 54, 25, 1, 5, 7, 34, 2, 3};
    int i,j,temp;
    printf("정렬 전 : ");
    for(int i = 0 ; i <10 ; i++){
        printf(" %d ",s[i]);
    }
    printf("\n\n 정렬중\n\n");
    for(i=1;i<LEN;i++)
    {
        temp = s[i];
        printf(" temp: %d --> ",temp);
        j = i-1;
        
        while(j>=0 && s[j] > temp)
        {   
            for(int k = 0 ; k<10;k++){
                printf(" \t %d",s[k]);
            }
            printf("\n");
            s[j+1] = s[j];
            j=j-1;
            
        }
        
        s[j+1] = temp;
        for(int k = 0 ; k<10;k++){
                printf(" \t %d",s[k]);
            }
        printf("\n");
    }
    printf("\n\n 정렬후\n\n");
    for(i=0;i<LEN; i++)
        printf("%d ",s[i]);
    
    return 0;
}