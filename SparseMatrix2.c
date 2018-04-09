/*
Sparse Matrix ver2.
:Most of the matrix is filled with zeros.(Almost Empty)

Using calloc, you don't need initialize the matrix.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct ma{
    int row,col,value;
}M;

typedef struct mb{
    int rows, cols, terms;
    M data[9];
}MA;


void Mat_init(int** ary, int row, int col){
    for(int i = 0 ; i<row;i++){
        for(int j = 0 ; j<col;j++){
            ary[i][j]=0;
        }
    }
}
int main(void){
    MA m={3,3,4, {{0,2,2}, {1,0,1}, {2,1,3},{2,2,8}}};
    MA s={3,3,3, {{0,2,3}, {1,0,2}, {2,2,8}}};

    int **ap,**bp,**cp;
    int i , j ,c;

    /*
    ap=(int**)calloc(m.rows,sizeof(int*));
    bp=(int**)calloc(s.rows,sizeof(int*));
    cp=(int**)calloc(m.rows,sizeof(int*));
    */
    ap=malloc(sizeof(int*)*m.rows);
    bp=malloc(sizeof(int*)*s.rows);
    cp=malloc(sizeof(int*)*m.rows);
    for(int i = 0 ; i<m.rows;i++){
        ap[i] = malloc(sizeof(int)*m.cols);
        bp[i] = malloc(sizeof(int)*s.cols);
        cp[i] = malloc(sizeof(int)*m.cols);
        /*ap[i]=(int*)calloc(m.cols,sizeof(int));
        bp[i]=(int*)calloc(s.cols,sizeof(int));
        cp[i]=(int*)calloc(m.cols,sizeof(int));
        */
    }
    //Matrix Initialize. using calloc, you can skip initialize.
    Mat_init(ap,m.rows,m.cols);
    Mat_init(bp,s.rows,s.cols);
    Mat_init(cp,m.rows,m.cols);
    
    for(i = 0 ; i<m.terms;i++){
        ap[m.data[i].row][m.data[i].col]=m.data[i].value;
    }
    for(i = 0 ; i<s.terms;i++){
        bp[s.data[i].row][s.data[i].col]=s.data[i].value;
    }

    //Sparse Matrix Summation
    printf(">>>>>>>>>>>Sparse Matrix Summation\n");
    for(i = 0 ; i<m.rows;i++){
        for(j=0;j<s.cols;j++){
            cp[i][j]=ap[i][j]+bp[i][j];
        }
    }
    for(i = 0; i<m.rows;i++){
        for(j = 0 ; j<m.cols;j++){
            printf("[%2d]",ap[i][j]);
        }
        printf("    +    ");
        
        for(j = 0 ; j<s.cols;j++){
            printf("[%2d]",bp[i][j]);
        }

        printf("    =    ");


        for(j = 0 ; j<m.cols;j++){
            printf("[%2d]",cp[i][j]);
        }
        printf("\n");
    }
    
    // Sparse Matrix Multiplication
    printf(">>>>>>>>>>>Sparse Matrix Multiplication\n");
    Mat_init(cp,m.rows,m.cols);
    
    for(i = 0 ; i<m.rows;i++){
        for(j = 0; j<s.cols;j++){
            for(c = 0; c<m.rows;c++){
                cp[i][j] = cp[i][j]+(ap[i][c]*bp[c][j]);
            }
        }
    }
    for(i = 0; i<m.rows;i++){
        for(j = 0 ; j<m.cols;j++){
            printf("[%2d]",ap[i][j]);
        }
        printf("    X    ");
        
        for(j = 0 ; j<s.cols;j++){
            printf("[%2d]",bp[i][j]);
        }

        printf("    =    ");


        for(j = 0 ; j<m.cols;j++){
            printf("[%2d]",cp[i][j]);
        }
        printf("\n");
    }
    return 0;
}