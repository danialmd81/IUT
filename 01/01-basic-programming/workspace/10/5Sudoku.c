#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

int **mal()
{
    int **sudoku;
    sudoku=malloc(9*sizeof(int*));
    for(int i=0;i<9;i++)
    {
        sudoku[i]=malloc(9*sizeof(int));
    }
    return sudoku;
}

void print(int **sudoku)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            printf("%d ",sudoku[i][j]);
        }
        printf("\n");
    }
}

bool find_zero(int** sudoku,int *row, int *col)
{
    int i,j;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(sudoku[i][j] == 0)
            {
                *row = i;
                *col = j;
                return true;
            }
        }
    }
    return false;
}

bool checkRow(int **sudoku,int n, int r)
{
    int i,j;
    for(i=0;i<9;i++)
    {
        if(sudoku[r][i] == n)
            return false;
    }
    return true;
}

bool checkCol(int **sudoku,int n, int c)
{
    int i,j;
     for(i=0;i<9;i++)
    {
        if(sudoku[i][c] == n)
            return false;
    }
    return true;
}

bool checkSqu(int **sudoku,int n, int r, int c)
{
    int i,j;
    int row_start = (r/3)*3;
    int col_start = (c/3)*3;
    for(i=row_start;i<row_start+3;i++)
    {
        for(j=col_start;j<col_start+3;j++)
        {
            if(sudoku[i][j]==n)
                return false;
        }
    }
    return true;
}

bool solve_sudoku(int **sudoku)
{
    int row;
    int col;
    if(find_zero(sudoku,&row, &col) == false)
        return true;
    int n,i;
    for(i=1;i<=9;i++)
    {
        if(checkRow(sudoku,i,row)&&checkCol(sudoku,i,col)&&checkSqu(sudoku,i,row,col))
        {
            sudoku[row][col] = i;
            if(solve_sudoku(sudoku))
                return true;
            sudoku[row][col]=0;
        }
    }
    return false;
}

int main()
{
    int **sudoku=mal();
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            scanf("%d",&sudoku[i][j]);
        }
    }
    solve_sudoku(sudoku);
    print(sudoku);
    
    return 0;
    
}
