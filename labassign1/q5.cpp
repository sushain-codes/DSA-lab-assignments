#include<iostream>
using namespace std;
int main(){
    int A[100][100];
    int c, r, sum = 0;
    //take collumns and rows
    cout<<"enter row and collumns: "<<endl;
    cin>>r>>c;
    //input the 2d array
    cout<<"enter values of matrix: "<<endl;
    for(int i = 0; i<r;i++){
        for(int j=0;j<c;j++){
            cin>>A[i][j];
        }
    }
    //sum of matrix
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            sum += A[i][j];
        }
    }
    //output the sum
    cout<<"The sum of every row and every column of the 2d array is: "<<endl;
    cout<<sum;


    return 0;
}