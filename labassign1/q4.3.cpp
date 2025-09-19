#include<iostream>
using namespace std;
int main(){
    int A[100][100];
    int transpose[100][100];
    int c, r;
    //take collumns and rows
    cout<<"enter row and collumns: "<<endl;
    cin>>r>>c;
    //input a matrix
    cout<<"enter values of matrix: "<<endl;
    for(int i = 0; i<r;i++){
        for(int j=0;j<c;j++){
            cin>>A[i][j];
        }
    }
    //transpose the matrix
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            transpose[i][j] = A[j][i];
        }
    }
    //output the transpose matrix
    cout<<"transpose matrix is: "<<endl;
    for(int i = 0; i<c;i++){
        for(int j=0;j<r;j++){
            cout<<transpose[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}