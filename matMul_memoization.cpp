// this code is the program showing matrix multiplication using recursion along with memoization...

//   IN this program i have falsely declared the actual size of the matrix as 50 by default..
//   then also i am taking the the size of the matrix input from the user...which should be less than 51...
//   for proper working of the program...
//   I had to do this due to compilation error related to the size of the matrix...
//   as i am taking the size of the matrix from the user ...but before that i need to define the size of
//   the matrix in the function 'matrixMultiplication(int[][n1],int sizes[],int i,int j)'...
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

using namespace std;
  const int n1=50;
int matrixMultiplication(int[][n1],int sizes[],int i,int j);

int main()
{
   int n;
   cout<<"Enter the no. of matrices you want to multiply: ";
   cin>>n;
   int sizes[n+1]={0};

   int matrix[n1][n1];

    // setting all the elements of the matrices to INT_MAX...
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            matrix[i][j]=INT_MAX;
            //cout<<matrix[i][j];
        }
    }

    cout<<endl;

    // taking the entry of dimensions of all the matrices...

   for(int i=0;i<n;i++)
{

    cout<<"Enter the size of matrix no. : "<<i+1<<endl;
    cin>>sizes[i]>>sizes[i+1];

}
    cout<<endl;
    cout<<"The minimum scaler cost of multiplying the matrices of given dimensions is : "<<matrixMultiplication(matrix,sizes,0,n-1) ;
    cout<<endl;
}

int matrixMultiplication(int M[][n1],int sizes[],int i,int j)
{
    if(M[i][j]<INT_MAX)
        return M[i][j];

    else if(i==j)
    {
        M[i][j] = 0;
        return 0;
    }

    else
    {
        int minimum = INT_MAX;

        for(int k=0;k<j-i;k++)
        {
            int x = matrixMultiplication(M,sizes,i,i+k)   +
                    matrixMultiplication(M,sizes,i+k+1,j) +
                    sizes[i]*sizes[i+k+1]*sizes[j+1];

            if(x<minimum)
                minimum=x;

        }

        M[i][j] = minimum;
        return minimum;
    }
}

