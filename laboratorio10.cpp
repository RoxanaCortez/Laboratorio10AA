#include <iostream> 
#include <cmath> 
#include<bits/stdc++.h> 
using namespace std; 
  
class Node  
{  
    public: 
    int data;  
    Node* left;  
    Node* right;  
};  
  
Node* newNode(int data);  
  

Node* balance(int arr[], int start, int end)  
{  

    if (start > end)  
    return NULL;  
  
    int mid = ceil((start + end)/2);  
    Node *root = newNode(arr[mid]);  
  
    root->left = balance(arr, start, mid - 1);  

    root->right = balance(arr, mid + 1, end);  
  
    return root;  
}  
  

Node* newNode(int data)  
{  
    Node* node = new Node(); 
    node->data = data;  
    node->left = NULL;  
    node->right = NULL;  
  
    return node;  
}  
  
/*Preorder*/
void preorder(Node* node)  
{  
    if (node == NULL)  
        return;  
    cout << node->data << " ";  
    preorder(node->left);  
    preorder(node->right);  
}  
/*inorder*/
void inorder (Node* node)  
{  
    if (node == NULL)  
        return;  
    inorder(node->left);  
    cout<<node->data<<" ";  
    inorder(node->right);  
} 

/*Postorder*/
void postorder(Node* node) 
{ 
    if (node == NULL) 
        return; 
   	postorder(node->left); 
    postorder(node->right); 
    cout << node->data << " "; 
} 
  
int main()  
{  
    int arr[] = {3, 6, 7, 8, 9, 10, 12, 15};  
    int n = sizeof(arr) / sizeof(arr[0]);  
  
   
    Node *root = balance(arr, 0, n-1);  
    cout << "\nTree balanced: \n\n";  
    preorder(root);  
  
    return 0;  
}  
