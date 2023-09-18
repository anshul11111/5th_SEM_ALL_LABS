#include <iostream>
#include <iomanip>
#include <cmath>

#define F(x) (x * x * x - 4 * x -9)
#define Fu "f(x) = x^2 - 4x - 9 = 0"
#define BISECTION(x0, x1) ((x0 + x1) / 2)

using namespace std;

int FindRoot(double x0, double x1, double &root){
    if (F(x0) * F(x1) >= 0) return -1; // Return NaN for invalid input
    int itr = 0;
    double x2, prev_x2;
    prev_x2 = x1; // Initialize previous root value with x1 for Secant
    do{
        x2 = BISECTION(x0, x1);
        itr++; // Increment the iteration count
        cout << "Iteration: " << itr << " value: " << x2 << "; "
             << "For x0: " << x0 << " x1: " << x1 << endl;
        if (F(x0) * F(x2) < 0)
            x1 = x2; // solution is in the left side of x2
        else if (F(x2) * F(x1) < 0)
            x0 = x2; // solution is in the right side of x2
        if (fabs(x2 - prev_x2) <= 0.0001)
            break;    // stop on: |x(n) - x(n-1)| <= 0.0001
        prev_x2 = x2; // Update previous root value
        
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
    cout << "\t\tBisection Method" << endl;
    int itr = FindRoot(x0, x1, root); // Pass root by reference
    if(itr == -1) cout << "Invalid Interval " << endl;
    cout << "Root of Function " << Fu << ": " << root << endl
         << "After: " << itr << " Iterations" << endl;
    return 0;
}
