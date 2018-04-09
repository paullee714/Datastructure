/*
Sparse Matrix.
:Most of the matrix is filled with zeros.(Almost Empty)
*/

#include <stdio.h>
#include <stdlib.h> //using malloc

typedef struct _sparse{
    int col;
    int row;
    int value;
}SprMtrx;

SprMtrx *getSparse(int A[][6],int col, int row, int *cnt);

int main(void){
    int i;
    int cnt = 0;
    int A[][6] = {0,0,0,0,0,0,0,1,0,0,0,2,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,4};
    SprMtrx *S = getSparse(A,sizeof(A)/(sizeof(int)*6),6,&cnt);
    
    for(i = 0 ; i<cnt;i++){
        printf("[%d][%d][%d]\n",S[i].col,S[i].row,S[i].value);
    }
    return 0;
}

SprMtrx *getSparse(int A[][6],int col, int row, int *cnt){
    int i,j;
    SprMtrx *S;
    for(i=0;i<col;i++){
        for(j=0;j<row;j++){
            if(A[i][j]){
                (*cnt)++; 
            }
        }
    }
    S = (SprMtrx *)malloc(sizeof(SprMtrx)*((*cnt)+1));

    S[0].col = col;
    S[0].row = row;
    S[0].value = *cnt;

    *cnt = 1;
    for(i = 0 ;i<col;i++){
        for(j=0;j<row;j++){
            if(A[i][j]){
                S[*cnt].col = i;
                S[*cnt].row = j;
                S[(*cnt)++].value = A[i][j];
            }
        }
    }
    return S;
}