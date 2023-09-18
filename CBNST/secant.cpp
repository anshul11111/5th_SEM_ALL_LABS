#include <iostream>
#include <iomanip>
#include <cmath>

#define F(x) (x * x * x - 4 * x -9)
#define Fu "f(x) = x^2 - 4x - 9 = 0"
#define SECANT(x0, x1) (x1 - ((x1 - x0) / (F(x1) - F(x0))) * F(x1))

using namespace std;

int FindRoot(double x0, double x1, double &root){
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
    root = x2;
    return itr;
}

int main() {
    int ch;
    double x0, x1, root; // Set precision to 4 decimal places
    cout << "Enter Interval (x0, x1): ";
    cin >> x0 >> x1;
    cout << fixed << setprecision(4);
    cout << "\t\tSecant Method" << endl;
    int itr = FindRoot(x0, x1, root); // Pass root by reference
    cout << "Root of Function " << Fu << ": " << root << endl
         << "After: " << itr << " Iterations" << endl;
    return 0;
}

// Sample Output:
// Enter Interval (x0, x1): 2 3
//                 Secant Method
// Iteration: 1 value: 2.6000; For x0: 2.0000x1: 3.0000
// Iteration: 2 value: 2.6933; For x0: 3.0000x1: 2.6000
// Iteration: 3 value: 2.7072; For x0: 2.6000x1: 2.6933
// Iteration: 4 value: 2.7065; For x0: 2.6933x1: 2.7072
// Iteration: 5 value: 2.7065; For x0: 2.7072x1: 2.7065
// Root of Function f(x) = x^2 - 4x - 9 = 0: 2.7065
// After: 5 Iterations