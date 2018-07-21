#include <iostream>
using namespace std;
int backind=-1;
int frontind=0;
int Queue[100];
void Queuee(int x){
    ++backind;
    Queue[backind]=x;
}
void Dequeue(){
    Queue[frontind]=0;
    ++frontind;
}
bool isEmpty(){
    if(backind<frontind){
        return true;
    }
    return false;
}
int Front(){
    if(isEmpty()){
        cout <<"[!] Queue is Empty"<<endl;
        return frontind;
    }
    return Queue[frontind];
}

int main() {
	Queuee(1);
	Queuee(2);
	Queuee(3);
	cout<<Front()<<endl;
	Dequeue();
	cout<<Front()<<endl;
	return 0;
}
