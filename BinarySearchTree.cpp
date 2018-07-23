#include <iostream>
#include<queue>
using namespace std;
struct Node{
  int data;
  struct Node *right;
  struct Node *left;
};
bool isEmpty(struct Node *root){
    if(root==NULL){
        return false;
    }
    return true;
}
Node* GetNewNode(int data){
    Node *node=new Node();
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}
Node* Insert(Node* root,int data){
    if(root==NULL){
        root=GetNewNode(data);
        cout<<"Added:"<<root->data<<endl;
    }
    else if(data==root->data){
        cout<<"Data already exist"<<endl;
    }
    else if(data<root->data){
        root->left=Insert(root->left,data);
    }
    else{
        root->right=Insert(root->right,data);
    }
    return root;
} 
//Order Traversals
void Inorder(Node *root) {
	if(root == NULL) return;

	Inorder(root->left);       //Visit left subtree
	cout<<root->data<<" ";  //Print data
	Inorder(root->right);      // Visit right subtree
}
void preorder(Node *root) {
	if(root == NULL) return;
    cout<<root->data<<" ";  //Print data
	Inorder(root->left);       //Visit left subtree
	Inorder(root->right);      // Visit right subtree
}
void postorder(Node *root) {
	if(root == NULL) return;
	Inorder(root->left);       //Visit left subtree
	Inorder(root->right);      // Visit right subtree
	cout<<root->data<<" ";  //Print data
}
//Level Order Traversal
void LevelOrder(struct Node *root){
    if(root==NULL) return;
    queue <Node *> q;
    q.push(root);
    while(!q.empty()){
        Node *current=q.front();
        q.pop();
        cout<<current->data<<" ";
        if(current->left!=NULL) q.push(current->left);
        if(current->right!=NULL) q.push(current->right);
    }
}
//Finding Max
Node *FindMin(Node *root){
    while(root->left!=NULL) root=root->left;
    return root;
}
//Finding Min
Node *FindMax(Node *root){
    while(root->right!=NULL) root=root->right;
    return root;
}
//Delete Elements
struct Node *Delete(struct Node *root,int data){
    //Base case
    if(root==NULL){
        cout<<"[!]Cant find"<<data<<endl;
    }
    else if(data<root->data){
        root->left=Delete(root->left,data);
    }
    else if(data>root->data){
        root->right=Delete(root->right,data);
    }
    else{
        //Case 1: No Child
        if(root->left==NULL && root->right==NULL){
            delete root;
            root=NULL;
        }
        //Case 2:One Child
        else if(root->left==NULL){
            struct Node *temp=root;
            root=root->right;
            delete temp;
        }
        else if(root->right==NULL){
            struct Node *temp=root;
            root=root->left;
            delete temp;
        }
        //Case 3:2 children
        else{
            struct Node *temp=FindMin(root->right);
            root->data=temp->data;
            root->right=Delete(root->right,temp->data);
        }
    }
    return root;
}
bool Search(struct Node *root,int data){
    if(root==NULL){
        return false;
    }
    if(root->data==data){
        return true;
    }
    else if(data <= root->data) {
		return Search(root->left,data);
	}
	else {
		return Search(root->right,data);
	}
}
void printLeafNodes(Node *root){
    if(!root){
        return;
    }
    if(!root->left && !root->right){
        cout<<root->data<<" ";
    }
    if(root->left){
        printLeafNodes(root->left);
    }
    if(root->right){
        printLeafNodes(root->right);
    }
}
int main() {
	// your code goes here
	Node *root=NULL;
	root=Insert(root,5);
	root=Insert(root,1);
	root=Insert(root,6);
	root=Insert(root,7);
	root=Insert(root,3);
	root=Insert(root,4);
	root=Insert(root,2);
	root=Insert(root,6);
    root=Delete(root,5);
	Inorder(root);
	cout<<endl;
	printLeafNodes(root);
	cout<<endl;
	LevelOrder(root);
	cout<<endl;
	if(Search(root,3)){
	    cout<<"Found"<<endl;
	}
	else{
	    cout<<"Not Found"<<endl;
	}
	return 0;
	
}
