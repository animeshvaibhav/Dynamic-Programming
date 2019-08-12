#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;


int main()
{
    int n;
   cout<<"Enter the no. of matrices you want to multiply: ";
   cin>>n;
   int sizes[n+1]={0}, matrix[n][n] ;

    // setting all the elements of the matrices to 0...
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            matrix[i][j]=0;
        }
    }

    cout<<endl;

    // taking the entry of dimensions of all the matrices...

   for(int i=0;i<n;i++)
{

    cout<<"Enter the size of matrix no. : "<<i+1<<endl;
    cin>>sizes[i]>>sizes[i+1];
}

    for(int i=0;i<n;i++)
  {
    // calculating the no. of scaler multiplications to be done for multiplying adjacent matrices...
    if(i<n-1)
    {

        matrix[i][i+1] = sizes[i]*sizes[i+1]*sizes[i+2];
    }
  }

    for(int split=2;split<n;split++)
    {
        for(int i=0;i+split<n;i++)
        {
            int x=i,y=i+split,value=0;

            int minimum = INT_MAX;

            for(int k=0;k<y-x;k++)
            {
                value = matrix[x][x+k] + matrix[x+k+1][y] + sizes[x]*sizes[x+k+1]*sizes[y+1];
                if(value<minimum)
                    minimum = value;
            }
            matrix[x][y] = minimum;
        }
    }

    cout<<endl;
    // for looking the calculations of the matrix...
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"The minimum scaler cost of multiplying the matrices of given dimensions is : "<<matrix[0][n-1];
    cout<<endl;

}


