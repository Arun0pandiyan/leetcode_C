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



struct node * Inpre(struct node * root){
    while(root!=NULL){
        root = root->right ; 
    }
    return root ; 
}

struct node * Insuc(struct node * root){
    while(root->left!=NULL){
        root = root->left ; 
    }
    return root ; 
}

int Height(struct node * root){
    int x,y ; 
    if (root==NULL){
        return 0 ; 
    }
    x = Height(root->left) ; 
    y = Height(root->right) ;
    return x>y ? x+1 : y+1 ;
    
}



void Delete(struct node * root,key){
    ; 
    
    step 1 . go find the node
    step 2 . find its height 
    step 3 . swap it with its predecessor or successor based on its height
    
    struct node * temp_ptr ; 
    if(root->left==NULL && root->right==NULL) { 
        
        free(root) ; 
        return NULL ;
    }
    
    
    if(root->data<key){ 
        Delete(root->right,key) ; 
    }
    
    
    else if(root->data>key){
        Delete(root->left,key) ; 
    }
    
    else {
        
        if ( Height(root->left) <  Height(root->right) ) { 
             
            temp_ptr = Inpre(root)  ; 
            root->data = temp_ptr->data  ; 
            Delete(temp_ptr,temp_ptr->data) ; 
         
        }
        
        else {
            temp_ptr = Insuc(root)  ; 
            root->data = temp_ptr->data  ; 
            Delete(temp_ptr,temp_ptr->data) ; 
            
        }
    }
    
    
}

// void rInsert(struct node * root){
//     ;
// }

void print_tree(struct node * root){
    if (root==NULL){return ; } 
    print_tree(root->left) ; 
    printf("%d-->",root->data) ; 
    print_tree(root->right) ; 
    
}

void print_tree_lvl_order(struct node * root){
    
    if (root!=NULL)
    {printf("%d\n",root->data) ; }
    
    root->left?printf("%d %d\n",root->left->data) : ;;
    root->right?printf("%d %d\n",root->left->data) : ;;
    

    
}
int main() {
    // Write C code here
    struct  node * root = NULL ; 
    struct  node * result = NULL ; 
    int height ;
    insert_tree(&root,10);
    insert_tree(&root,15);
    insert_tree(&root,13);
    insert_tree(&root,18);
    insert_tree(&root,12);
    insert_tree(&root,14);
    insert_tree(&root,17);
    insert_tree(&root,8);
    insert_tree(&root,7);
    insert_tree(&root,9);
    
    print_tree(root) ;
    // result = search_node(root,8) ; 
    // printf("%d",result->data) ; 
    // height = Height(root) ; 
    // printf("%d",height) ; 
    struct node * successor = Insuc(root->right) ;
    printf("%d",successor->data) ;
    return 0;
}
