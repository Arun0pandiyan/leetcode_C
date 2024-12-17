#include <stdio.h>

int F[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1} ; 
int fibonacci(int n){
  if (n<=1) { return n ;}
  
  else { 
      if (F[n-2]==-1){
           F[n-2] = fibonacci(n-2) ;    
      }
      
      if (F[n-1]==-1){
           F[n-1] = fibonacci(n-1) ;    
      }
      
      return F[n-2] + F[n-1] ; 
  } 
    
    
}

int main() {
    // Write C code here
    int ans ; 
    ans = fibonacci(4) ; 
    printf("%d",ans) ;
    
    return 0;
}
