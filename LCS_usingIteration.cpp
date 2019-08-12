#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

int main()
{
  string s1,s2;

  cout <<"Enter your first string : ";
  cin>>s1;
  cout<<"Enter your second string : ";
  cin>>s2;

  int m=s1.length();
  int n=s2.length();

  int M[m+1][n+1];
  for(int i=0;i<=m;i++)
  for(int j=0;j<=n;j++)
        M[i][j]=0;


  for(int i=1;i<=m;i++)
  {
      for(int j=1;j<=n;j++)
      {
          if(s1[i-1]==s2[j-1])
           {

            M[i][j]=1+M[i-1][j-1];
            cout<<endl<<"Equal : "<<s1[i-1]<<"  at i="<<i<<" and j= "<<j<<" Subsequence length :"<<M[i][j]<<endl;

            }

          else{
            M[i][j] = max(M[i-1][j],M[i][j-1]);

          }
      }
  }
    cout<<endl<<"LCS Matrix : "<<endl<<endl;
  for(int i=0;i<=m;i++)
  {for(int j=0;j<=n;j++)
        cout<<M[i][j]<<" ";
        cout<<endl;}

  cout<<endl<<"Length of longest common subsequence is : "<<M[m][n]<<endl;

  return 0;
}
