//gauss seidal
#include <stdio.h>
#include <math.h>
int main()
{int n, maxIter;
printf("Enter the number of equations: ");
scanf("%d", &n);
double A[n][n], B[n], X[n], Xnew[n];
printf("Enter the coefficients of the equations:\n");
for(int i = 0; i < n; i++){
for(int j = 0; j < n; j++){
scanf("%lf", &A[i][j]);}
printf("Enter the right-hand side value for equation %d: ", i + 1);
scanf("%lf", &B[i]);
X[i] = 0;}
printf("Enter the maximum number of iterations: ");
scanf("%d", &maxIter);
for(int iter = 0; iter < maxIter; iter++){
for (int i = 0; i < n; i++){
double sum = 0.0;
for (int j = 0; j < n; j++){
if (j != i){
sum += A[i][j] * X[j];}}
Xnew[i] = (B[i] - sum) / A[i][i];}
for(int i = 0; i < n; i++){
X[i] = Xnew[i];}}
printf("Solution after %d iterations:\n", maxIter);
for (int i = 0; i < n; i++){
printf("X[%d] = %.4lf\n", i, X[i]);}}
