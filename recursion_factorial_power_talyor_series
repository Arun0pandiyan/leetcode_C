// Online C compiler to run C program online
#include <stdio.h>
static double p =1 , f =1 ; 
int factorial(int x){
    if (x==1){ return x ;}
    
    return x+factorial(x-1);
}

int powe(int x, int y){
    
    if (y==1){return x ; } 
    return x*powe(x, y-1) ; 
}

int addd(int x){
    if (x==1){return x ; }
    return x+addd(x-1) ; 
}

double taylor_series(int y,int n) {
    double r ; 
    if (n==0){return 1 ; } 
    r = taylor_series(y,n-1) ; 
    p = p * y ; 
    f = f* n ; 
    return r+(p/f) ; 

}
int main() {
    // Write C code here
    double ans ; 
    ans = taylor_series(3,11) ; 
    printf("%f",ans) ; 
    return 0;
}
