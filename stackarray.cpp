#include <iostream>
using namespace std;
char stack[1000];
int ind;
void push(char x){
    ++ind;
    stack[ind]=x;
}
bool isEmpty(){
    if(ind>=1){return false;}
    else return true;
}
void pop(){
    stack[ind]='\0';
    --ind;
}
char top(){
    return stack[ind];
}
int main(){
    ind=0;
    int flag=0;
    string input;
    cin>>input;
    //cout<<input.length()<<endl;
    for(int i=0;i<input.length();i++){
        //cout<<"Input"<<input[i]<<endl;
        //if(!isEmpty()){
        //    cout<<top()<<endl;
        //}
        if(input[i]=='('||input[i]=='['||input[i]=='{'){
            push(input[i]);
        }
        else if(input[i]==')'&& top()=='('||input[i]==']'&& top()=='['||input[i]=='}'&&top()=='{'){
            if(isEmpty()){
                flag=1;
                break;
            }
            else{
                flag=0;
                //cout<<"Popped:"<<top()<<endl;
                pop();
            }
           
        }
         else{
                flag=1;
            }
}
if(isEmpty()&&flag!=1){
    cout<<"True"<<endl;
}
else{
    cout<<"False"<<endl;
}
}