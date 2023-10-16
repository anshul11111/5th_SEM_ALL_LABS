#include <stdio.h>
float p_cal(float p, int n){
float temp = p;
for (int i = 1; i < n; i++)
{if (i % 2 == 1)
temp *= (p - i);
else
temp *= (p + i);}
return temp;}
int fact(int n){
int f = 1;
for (int i = 2; i <= n; i++)
f *= i;
return f;}
int main(){int n = 7;
float x[] = {1, 1.05, 1.10, 1.15, 1.20, 1.25, 1.30};
float y[7][7] = {0};
y[0][0] = 2.7183;
y[1][0] = 2.8577;
y[2][0] = 3.0042;
y[3][0] = 3.1582;
y[4][0] = 3.3201;
y[5][0] = 3.4903;
y[6][0] = 3.6693;
for (int i = 1; i < n; i++){
for (int j = 0; j < n - i; j++){
y[j][i] = ((y[j + 1][i - 1] - y[j][i - 1]));}}
for (int i = 0; i < n; i++){
printf("%.4f\t", x[i]);
for (int j = 0; j < n - i; j++){
printf("%.4f\t", y[i][j]);}
printf("\n");}
float value = 1.17;
float sum = y[n / 2][0];
float p = (value - x[n / 2]) / (x[1] - x[0]);
for(int i = 1; i < n; i++){
sum = sum + (p_cal(p, i) * y[(n - i) / 2][i]) / fact(i);}
printf("\nValue at %.2f is %.4f\n", value, sum);}
