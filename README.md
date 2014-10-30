matrix-mult-c
=============

Matrix Multiplication in C using just pointers

Program takes input from from a text file, containing values for matrix indices. The format is as follows:

3 
2 
4 
1 2 
3 4 
5 6 
7 8 9 10 
11 12 13 14

This denotes that Matrix A is 3x2, Matrix B is 2x4, and the resulting matrix is 3x4. The values following this are read in by the program and stored in Matrix A and B. The values are then multiplied and stored in a new matrix, and the output is printed. For the values above, the output would be as follows:

Matrix A contents:
	1	2
	3	4
	5	6

Matrix B contents:
	7	8	9	10
	11	12	13	14

Matrix A * B is:
	29	32	35	38
	65	72	79	86
	101	112	123	134
