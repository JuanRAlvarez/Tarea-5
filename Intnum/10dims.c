#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define USAGE "USAGE: ./pi.x n_points"
#define PI 25.83333333

int main(int argc, char **argv){
    
    int n_points;
    float **x;
    int i;
    int j;
    int k;
    float a;
    float q;
    int seed;
    float suma;
    float integrando;
    float integral;
    int n_dims;
    
    n_dims = 10;
    
    
    j=0;
    
    n_points = atoi(argv[1]);
    seed = atoi(argv[2]);
    
    
    x=malloc(n_points * sizeof(float *));
    for (i=0;i<n_points;i++){
        x[i] = malloc(n_dims*sizeof(float));
    
    }
    
    if (argc!=3) {
        printf("%s\n", USAGE);
        exit(1);
    }
    
    
    /*printf ("Using %d points to integrate \n", n_points);
    printf ("Expected value %f\n", PI);*/
    
    
    srand48(seed);
    
    integrando = 0.0;
    
    for (i=0; i<n_points; i++){
        suma = 0;
        for (j=0;j<n_dims;j++){
        x[i][j] = drand48();
        suma = suma + x[i][j];
        }
        integrando = integrando + pow(suma,2);
        }
    
    integral = integrando/n_points;
    
    printf("%f \n",integral);
    
}