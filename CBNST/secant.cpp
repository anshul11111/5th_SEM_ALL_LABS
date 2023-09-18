#include <iostream>
#include <iomanip>
#include <cmath>

#define F(x) (x * x * x - 4 * x -9)
// #define F(x) (x * x * x - 2 * x - 5)
#define SECANT(x0, x1) (x1 - ((x1 - x0) / (F(x1) - F(x0))) * F(x1))

using namespace std;

double SecantMethod(double x0, double x1){
    int itr = 0;
    double x2, prev_x2;
    prev_x2 = x1; // Initialize previous root value with x1 for Secant
    do{
        x2 = SECANT(x0, x1);
        itr++; // Increment the iteration count
        cout << "Iteration: " << itr << " value: " << x2 << "; "
             << "For x0: " << x0 << "x1: " << x1 << endl;
        if (fabs(x2 - prev_x2) <= 0.0001)
            break;    // stop on: |x(n) - x(n-1)| <= 0.0001
        prev_x2 = x2; // Update previous root value
        x0 = x1;      // Update x0 with the current value of x1
        x1 = x2;      // Update x1 with the current value of x2
    } while (true);
    cout << "Iterations: " << itr << endl;
    return x2;
}

int main(){
    double x0, x1, root;
    cout << fixed << setprecision(4);
    cout << "Enter Initial Guesses (x0, x1): ";
    cin >> x0 >> x1;
    root = SecantMethod(x0, x1);
    cout << "Root of F : " << root << endl;
    cout << "Function value at root of F(root) : " << F(root) << endl;
    return 0;
}
