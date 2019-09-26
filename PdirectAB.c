#include<stdio.h>

struct Point {
    double x;
    double y;
};

struct Point Translate(struct Point Y, struct Point X) {
    Y.x=Y.x-X.x; 
    Y.y=Y.y-X.y;
    return Y;
}

double CrossProduct(struct Point A, struct Point B) {
    return (A.x)*(B.y) - (A.y)*(B.x);
}

double GetDirection(struct Point X, struct Point Y, struct Point P) {
    Y = Translate(Y,X);
    P =Translate(P,X);
    // X = Translate(X,X);
    return CrossProduct(Y,P); 
}

int main() {
    struct Point A={-30,10},B={29,-15},P={15,28};
    double crossprod = GetDirection(A,B,P);
    if(crossprod==0) printf("P is on line AB");
    else if(crossprod<0) printf("P is on right of line AB");
    else printf("P is on left of line AB");
    return 0;
}