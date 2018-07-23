#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/** BINARY SEARCH ALGORITHM **/
void display(int arr[],int size){
    for(int i=0;i<size;i++){
	   cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void binarysearch(int arr[],int size,int X){
    int Left=0;
    int Right=size-1;
    int mid;
    while(Left<=Right){
        mid=(Left+Right)/2;
        if(X==arr[mid]){
            cout<<"****************"<<endl;
            cout<<"[*]Found"<<endl;
            cout<<"Index:"<<mid<<endl;
            cout<<"Value:"<<arr[mid]<<endl;
            cout<<"****************"<<endl;
            return;
        }
        else if(X<arr[mid]) Right=mid-1;
        else Left=mid+1;
    }
    cout<<"[!]Not Found"<<endl;
}
int main() {
	cout<<"Enter the array size:";
	int size;
	size=0;
	cin>>size;
	cout<<endl;
	int arr[100];
	cout<<"Enter values:"<<endl;
	for(int i=0;i<size;i++){
	   cin>>arr[i];
	}
	cout<<"Entered array:"<<endl;
	display(arr,size);
	//Sorting the array
	cout<<"Sorted array:"<<endl;
	sort(arr,arr+size);
	display(arr,size);
	int X;
	/*while(true){
	    cout<<"Enter the desired value to find in the array.\n(or)\n To quit press Ctrl+C"<<endl;
	    cin>>X;
	    binarysearch(arr,size,X);
	}*/
	 binarysearch(arr,size,3);
	return 0;
}
