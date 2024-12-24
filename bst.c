// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data ; 
    struct  node *  left ; 
    struct node * right ;
} ; 


void insert_tree(struct  node ** root,int data){
    struct  node * new_node = (struct node *) malloc(sizeof(struct node)) ; 
    new_node->data  = data ; 
    new_node->left  = NULL ; 
    new_node->right  = NULL ; 
    
    struct node * temp_root = *root ; 
    struct node * temp_root2 = *root ; 
    if (*root==NULL) { 
        *root  = new_node ;
        return ;
    }
    
    
    while(temp_root!=NULL){
        temp_root2 = temp_root ; 
        if (temp_root->data>data){
            temp_root = temp_root->left ; 
        }
        
        else if (temp_root->data<data) { 
            temp_root = temp_root->right ; 
        }
        
        else { return ; } 
    }
    
    if (temp_root2->data>data) {
       temp_root2->left = new_node ;  
    }
    
    if (temp_root2->data<data) {
       temp_root2->right = new_node ;  
    }
    
}

struct node * search_node(struct node * root,int target){
    if (root==NULL){
        return NULL;
    }
    
    while(root!=NULL){
    if (root->data>target){
        root = root->left ; 
    }
    
    else if (root->data==target){
        return root  ; 
    }
    
    else {
        root = root->right ; 
    }
    }
}


void print_tree(struct node * root){
    if (root==NULL){return ; } 
    print_tree(root->left) ; 
    printf("%d-->",root->data) ; 
    print_tree(root->right) ; 
    
}
int main() {
    // Write C code here
    struct  node * root = NULL ; 
    struct  node * result = NULL ; 
    insert_tree(&root,10);
    insert_tree(&root,8);
    insert_tree(&root,9);
    insert_tree(&root,15);
    print_tree(root) ;
    result = search_node(root,8) ; 
    printf("%d",result->data) ; 
    return 0;
}
