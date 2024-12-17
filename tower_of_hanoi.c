// Online C compiler to run C program online
#include <stdio.h>

void pm(int start, int end){
    printf("calling pm") ; 
    printf("%d--->%d\n",start,end) ;
}

void hanoi(int n, int start, int end){
    // printf("calling hanoi") ; 
    if (n==1){pm(start,end) ; return ;}
    int other = 6 - ( start + end ) ; 
    // printf("other is %d",other) ;
    hanoi(n-1,start,other) ; 
    pm(start,end);
    hanoi(n-1,other,end) ;
}
int main() {
    // Write C code here
    // printf("Try programiz.pro");
    hanoi(12,1,3) ; 
    return 0;
}
