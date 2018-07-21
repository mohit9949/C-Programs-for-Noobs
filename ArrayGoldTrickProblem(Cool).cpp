/*Hello my dear student! This exercise will make you think !

It's given an array (indexed from 1) of N elements on which we make M queries:

add(Left, Right, X) - all the elements between the position Left and Right (1<=Left<=Right<=N) are raising their values with X.

After all the operations are completed, print the array.

example

Array: 1 1 1 4 5 6

operations: (1, 5, 2), (2, 3, 10)

Final array: 3 13 13 6 7 6

Please think of any solution and then try to improve it! Try to use that we'll print the array after all operations are completed. 

You can find the solution in the next video.*/
#include <iostream>
#include<string.h>
#include <bits/stdc++.h>
using namespace std;
int arr[1000],B[1000],auxB,Left,Right,X;
int main(){
    int n;
    cout<<"How many numbers?:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int nq;
    cout<<"How many number of queries?"<<endl;
    cin>>nq;
    for(int i=0;i<nq;i++)
    {   
        cin>>Left;
        cin>>Right;
        cin>>X;
        //cout<<"X="<<X<<endl;
        B[Left-1]+=X;
        //cout<<"Right="<<Right<<endl;
        B[Right]-=X;
        //cout<<"i="<<i<<endl;
        //for(int j=0;j<n;j++){
        //cout<<B[j]<<" ";
        //}
       // cout<<endl;
    }
    cout<<"B[]="<<endl;
     for(int i=0;i<n;i++){
        cout<<B[i]<<" ";
    }
    cout<<endl;
    cout<<"Arr[]="<<endl;
    for(int i=0;i<n;++i){
        auxB+=B[i];
        arr[i]+=auxB;
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}