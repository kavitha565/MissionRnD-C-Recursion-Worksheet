/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
void fun(int n,int columns,int **input_array,int *res,int p)
{
	int i, j,k=p;
	for (i = n, j = 0; j < columns - 1; j++)
	{
		res[k++] = input_array[i][j];
	}
	fun(n - 1,columns,input_array,res,p);
}
int *spiral(int rows, int columns, int **input_array)
{
	if (input_array==NULL||rows<=0||columns<=0)
	return NULL;
	int i, j, k = 0;
	int n = rows*columns;
	int *res = (int *)malloc(n*sizeof(int));
	for (i = 0, j = 0; j < columns; j++)
	{
		res[k++] = input_array[i][j];
	}
	for (i = 1, j = columns - 1; i < rows; i++)
	{
		res[k++] = input_array[i][j];
	}
	for (i = rows - 1, j = columns - 2; j >= 0; j--)
	{
		res[k++] = input_array[i][j];
	}
	if (rows >= columns)
	{
		int p = k;
		int n = rows - 2;
		fun(n, columns, input_array, res,p);
	}
	return res;
}
