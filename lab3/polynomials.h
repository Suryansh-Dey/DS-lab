#include <stdio.h>
#define SIZE 20
struct Polynomial{
        short deg;
        float coeff[SIZE];
        float roots[SIZE];
};
void readpoly(struct Polynomial* polynomial){
        scanf("%d", &(polynomial->deg));
        for(int i=0;i<polynomial->deg+1;i++){
                scanf("%f", &(polynomial->coeff[i]));
                polynomial->roots[i] = 0;
        }
}
void writepoly(struct Polynomial polynomial){
        printf("Polynomial of degree is %hd\n", polynomial.deg);
        printf("Coefficients in increasing order of exponent are: ");
        for(int i=0;i<polynomial.deg+1;i++)
                printf("%f, ", polynomial.coeff[i]);
        printf("\nRoots are: ");
        for(int i=0;i<polynomial.deg;i++)
                printf("%f, ", polynomial.roots[i]);
}
short degree(struct Polynomial p){
        return p.deg;
}
short nonzerocnt(struct Polynomial p){
        int ct=0;
        for(int i=0;i<p.deg+1;i++)
                ct+=(p.coeff[i]!=0);
        return ct;
}
float polyeval(struct Polynomial p, float x){
        float val=p.coeff[degree(p)];
        for(int i=1;i<degree(p)+1;i++)
                val=val*x+p.coeff[degree(p)-i];
        return val;
}
struct Polynomial derivpoly(struct Polynomial p){
        struct Polynomial dp;
        dp.deg=p.deg-1;
        for(int i=0;i<degree(dp)+1;i++)
                dp.coeff[i]=p.coeff[i+1]*(i+1);
                        return dp;
}
float findroot(struct Polynomial p, float x1){
                printf("> %f %f\n", polyeval(p, x1), polyeval(derivpoly(p), x1));
                return x1-polyeval(p, x1)/polyeval(derivpoly(p), x1);
}
struct Polynomial reducedpoly(struct Polynomial p, float root){
        struct Polynomial rp;
        rp.deg = degree(p) - 1;
        rp.coeff[0] = -p.coeff[0]/root;
        for(int i=1; i<degree(rp)+1; i++)
                rp.coeff[i]=(rp.coeff[i-1]-p.coeff[i])/root;
        return rp;
}