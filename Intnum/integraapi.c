#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define USAGE "USAGE: ./pi.x n_points"
#define PI 3.14159264

int main(int argc, char **argv){

    int n_points;
    float *x;
    float *y;
    int i;
    int j;
    float a;
    float q;
    int seed;
    
    j=0;
    
    n_points = atoi(argv[1]);
    seed = atoi(argv[2]);
    
    
    x=malloc(n_points * sizeof(float));
    y=malloc(n_points * sizeof(float));
    
    if (argc!=3) {
        printf("%s\n", USAGE);
        exit(1);
    }
    
    
    printf ("Using %d points to integrate \n", n_points);
    printf ("Expected value %f\n",PI);
    
    
    srand(seed);
    
    for (i=0; i<n_points; i++) {
        x[i] = 2*drand48() - 1;
        y[i] = 2*drand48() - 1;
        
        a = pow(x[i],2)+pow(y[i],2);
        
        if (a<1.0) {
            j++;
        }
    }
    
    q = j*4.0;
    
    printf("%f\n",q/n_points);

}