/*
	Program #3
	Programmer: Viet Truong
	Account: masc0859
	Date: 10/08/14
*/

#include <stdio.h>
#include <stdlib.h>

int i, j, k;

void read_matrices(int **A, int **B, int **C, int *m, int *n, int *p, char *datafile){
    /* Assigns # of rows and columns based on input from datafile */
    FILE *fp;
    fp = fopen(datafile, "r");
    
    if (fp==NULL){
        printf("Cannot open file\n");
        exit(0);
    }
    
    fscanf(fp, "%d", m);
    fscanf(fp, "%d", n);
    fscanf(fp, "%d", p);
    
    *A = malloc(*m * *n * sizeof(int));
    *B = malloc(*n * *p * sizeof(int));
    *C = malloc(*m * *p * sizeof(int));
    
    /* SCAN ELEMENTS INTO MATRIX A */
    for (i=0; i<*m; i++)
        for (j=0; j<*n; j++)
        {
            int offset= i * *n + j;
            if (!fscanf(fp, "%d", &(*((*A)+offset))))
            {	
            	printf("Error in scanning Matrix A");
            	exit(0);
            }
        }
    
    /* SCAN ELEMENTS INTO MATRIX B */
    for (i=0; i<*n; i++)
        for (j=0; j<*p; j++)
        {
            int offset = i * *p + j;
            if (!fscanf(fp, "%d", &(*((*B)+offset))))
            {
                printf("Error in scanning Matrix B");
                exit(0);
            }
        }
    fclose(fp);
}

void mult_matrices(int *A, int *B, int *C, int m, int n, int p)
{
    for (i=0; i<m; i++)
        for(j=0; j<p; j++)
        {
            *(C+(i*p+j)) = 0;
            for (k=0; k<n; k++)
                *(C+(i*p+j)) += (*(A+(i*n+k)) * *(B+(k*p+j)));
        }
}

void print_matrices(int *matrix, int row, int column)
{
    for (i=0; i<row; i++)
    {
        for (j=0; j<column; j++)
            printf("\t%d", *(matrix+i*column+j));
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Enter a file to be scanned.\n");
        exit(0);
    }
    printf("Program #3, masc0859, Viet Truong\n");
    
    int *A, *B, *C;
    int m, n, p;
    
    read_matrices(&A, &B, &C, &m, &n, &p, *(argv+1));
    mult_matrices(A, B, C, m, n, p);
    
    printf("\nMatrix A contents:\n");
    print_matrices(A, m, n);
    
    printf("\nMatrix B contents:\n");
    print_matrices(B, n, p);
    
    printf("\nMatrix A * B is:\n");
    print_matrices(C, m, p);
    
    free(A);
    free(B);
    free(C);
    
    exit(0);
}
