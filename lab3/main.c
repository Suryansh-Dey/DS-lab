#include "polynomials.h"
int main(){
        struct Polynomial poly;
        readpoly(&poly);
        writepoly(poly);
        short ct = nonzerocnt(poly);
        printf("\nnon zero coefficient count: %hd", ct);
        if(ct < (degree(poly)+1)/2)
                printf("\nPolynomial is sparse");
        else printf("\nPolynomial is not sparse\n");

        float points[5] = {0, 1, 2, 3, 4};
        float pval;
        for (int i = 0; i < 5; i++){
                pval = polyeval(poly, points[i]);
                printf ("Value of Polynomial poly at %f is %f \n", points[i], pval);
        }
        struct Polynomial der1;
        der1 = derivpoly(poly);
        printf(" first derivative of p1 : \n");
        writepoly(der1);

        float guess = 20.0, root;
        struct Polynomial temp = poly;
        for (short j = 1; j < degree(poly); j++){
                printf(" Finding root no %hd \n", j);
                root = findroot(temp, guess);
                printf(" A root of p1 reached from guess %f using NR is %f \n",
                guess, root);
                poly.roots[j-1] = root;
                temp = reducedpoly(temp, root);
                printf(" Reduced poly after root %f is removed from p1 : \n", root);
                writepoly(temp);
                if (degree(temp) == 1) break;
        }
        root = -temp.coeff[0]/temp.coeff[1];
        poly.roots[poly.deg-1] = root;
        printf(" Polynomial p1 after extraction of all roots \n");
        writepoly(poly);


        printf("\n");
        return 0;
}