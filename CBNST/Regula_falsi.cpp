#include <iostream>
#include <iomanip>
#include <cmath>

#define F(x) (x * x * x - 4 * x - 9)
#define Fu "f(x) = x^2 - 4x - 9 = 0"
#define REGULA_FALSI(x0, x1) ((x0 * F(x1) - x1 * F(x0)) / (F(x1) - F(x0)))

using namespace std;

int FindRoot(double x0, double x1, double &root) { // Pass root by reference
    int itr = 0;
    double false_root, prev_false_root;
    prev_false_root = x0; // Initialize previous root value with x0
    do {
        false_root = REGULA_FALSI(x0, x1);
        if (F(x0) * F(false_root) < 0)
            x1 = false_root; // solution is in the left side of false_root
        else if (F(false_root) * F(x1) < 0)
            x0 = false_root; // solution is in the right side of false_root
        cout << "Iteration: " << ++itr << " value: " << false_root << endl;
        if (fabs(false_root - prev_false_root) <= 0.0001)
            break; // stop on: |x(n) - x(n-1)| <= 0.0001
        prev_false_root = false_root; // Update previous false_root value
    } while (true);
    root = false_root; // Modify the root variable
    return itr;
}

int main() {
    int ch;
    double x0, x1, root; // Set precision to 4 decimal places
    cout << "Enter Interval (x0, x1): ";
    cin >> x0 >> x1;
    cout << fixed << setprecision(4);
    cout << "\t\tRegular_Falsi" << endl;
    int itr = FindRoot(x0, x1, root); // Pass root by reference
    cout << "Root of Function " << Fu << ": " << root << endl
         << "After: " << itr << " Iterations" << endl;
    return 0;
}


// Sample Output:
// Enter Interval (x0, x1): 2 3
//                 Regular_Falsi
// Iteration: 1 value: 2.6000
// Iteration: 2 value: 2.6933
// Iteration: 3 value: 2.7049
// Iteration: 4 value: 2.7063
// Iteration: 5 value: 2.7065
// Iteration: 6 value: 2.7065
// Root of Function f(x) = x^2 - 4x - 9 = 0: 2.7065
// After: 6 Iterations
