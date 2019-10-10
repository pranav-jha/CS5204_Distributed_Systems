//CS16B019 Pranav Jha
#include<iostream>
using namespace std;

int main()
{
    int n=5; //size of matrixes
    int A[n][n],B[n][n],C[n][n];

   #pragma omp parallel for
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        A[i][j] = i+1; B[i][j] = j+1;
      }
    }
    
    double start = omp_get_wtime();
    #pragma omp parallel for private(i,j,k) shared(A,B,C)
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){  
        C[i][j] = 0;
        for(int k=0;k<n;k++) C[i][j] += A[i][k] * B[k][j];
      }
    }  
    double end = omp_get_wtime();
    cout<<"It is executed in "<<end-start<< "secs";

    cout<<"Matrix A:"<<endl;
    for(int i=0;i<n;i++){
      for(int j=0;j<n; j++) cout<<A[i][j]<<"\t";
      cout<<endl;
    }
    cout<<"Matrix B:"<<endl;
    for(int i=0;i<n;i++){
      for(int j=0;j<n; j++) cout<<B[i][j]<<"\t";
      cout<<endl;
    }
    cout<<"Matrix C=A*B:"<<endl;
    for(int i=0;i<n;i++){
      for(int j=0;j<n; j++) cout<<C[i][j]<<"\t";
      cout<<endl;
    }
    return 0;
}