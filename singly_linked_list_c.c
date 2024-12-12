// Online C compiler to run C program online

#include <stdio.h>

#include <stdlib.h>

struct Node {

    int data ; 
    struct Node* next ; 

} ;
 
struct Node* create_new_node(int data,struct Node* ptr ) { 

    struct Node* new_node_pointer = (struct Node* ) malloc(sizeof(struct Node)) ; 
    new_node_pointer-> data = data ; 
    new_node_pointer-> next = ptr ;
    return new_node_pointer ; 

}
 
void insert_at_first(struct Node** ptr , int data ) { 

    if (*ptr == NULL) {*ptr =  create_new_node(data,NULL) ;} 
    else {*ptr = create_new_node(data,*ptr) ; }

} 

void delete_at_first(struct Node** ptr) { 

    if (*ptr == NULL) { return ;} 
    struct Node * tmp_ptr = *ptr ;
    *ptr = tmp_ptr->next ;
    free(tmp_ptr) ; 
    return ; 
} 


void insert_at_last(struct Node** ptr , int data ) { 

    struct Node * tmp_ptr = * ptr ;
    if (*ptr == NULL) {*ptr =  create_new_node(data,NULL)  ; } 
 
    else {
    while (tmp_ptr->next != NULL) {
        tmp_ptr = tmp_ptr->next ; 
    }
    
    tmp_ptr->next = create_new_node(data,NULL) ;
    }

} 

void delete_at_last(struct Node** ptr) { 

    struct Node * tmp_ptr = * ptr ;
    if (*ptr == NULL) {return;} 
 
    if ((*ptr)->next==NULL){ free(*ptr) ; *ptr = NULL ;} 
    
    else{
    while (tmp_ptr->next != NULL) {
        tmp_ptr = tmp_ptr->next ; 
    }
    
    free(tmp_ptr->next) ; 
    tmp_ptr->next = NULL ;
    
    }

} 

void insert_at_position(struct Node** ptr , int data, int position ) { 
    
    
    if ((position==0) || (*ptr == NULL)){ return insert_at_first(ptr,data) ;}
    
    struct Node * tmp_ptr = * ptr;
    struct Node * newnode;
    int tmp_pos = 0 ; 
    
    while ((tmp_ptr-> next != NULL )&&(tmp_pos<position)) { 
            
        if (position==tmp_pos+1){
            newnode =  create_new_node(data,NULL)  ; 
            newnode->next = tmp_ptr->next ;
            tmp_ptr->next = newnode ; 
            return ; 
        }
        tmp_ptr = tmp_ptr->next ;
        tmp_pos ++ ; 
    } 

    if (position==tmp_pos+1) {insert_at_last(ptr,data) ; return ;}
} 

void print_linked_list(struct Node** ptr)
{   
    if (*ptr==NULL){return ; } 
    struct Node * tmp_ptr = *ptr ; 
    while ( tmp_ptr->next != NULL ) { 
        printf("\t%d-->",tmp_ptr->data) ; 
        tmp_ptr = tmp_ptr->next ; 
    }
    printf("\t%d\n",tmp_ptr->data) ; 
    
} 
int main() {
 
    struct Node* head = NULL ; 

    insert_at_first(&head,3) ; 
    print_linked_list(&head) ;
    // printf("data is\t%d\n",head->data) ; 
    insert_at_last(&head,9) ; 
    print_linked_list(&head) ;
    insert_at_first(&head,4) ; 
    print_linked_list(&head) ;
    // printf("data is\t%d\n",head->data) ; 
    insert_at_first(&head,5) ; 
    print_linked_list(&head) ;
    // printf("data is\t%d\n",head->data) ; 
    insert_at_position(&head,90,2) ;
    print_linked_list(&head) ;
    insert_at_position(&head,90,0) ;
    print_linked_list(&head) ;
    insert_at_position(&head,90,6) ;
    print_linked_list(&head) ;
    insert_at_position(&head,90,10) ;
    print_linked_list(&head) ;
    
    delete_at_first(&head) ;
    print_linked_list(&head) ;

    delete_at_first(&head) ;
    print_linked_list(&head) ;

    delete_at_first(&head) ;
    print_linked_list(&head) ;

    delete_at_first(&head) ;
    print_linked_list(&head) ;

    delete_at_first(&head) ;
    print_linked_list(&head) ;

    delete_at_first(&head) ;
    print_linked_list(&head) ;

    delete_at_last(&head) ;
    print_linked_list(&head) ;

    delete_at_last(&head) ;
    print_linked_list(&head) ;

    


    // printf("data%d",head->data) ; 

    return 0 ;

}
