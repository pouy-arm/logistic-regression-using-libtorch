#include <iostream>
#include <torch/torch.h>
#include <vector>
#include <numbers>
#include <math.h>

using namespace std;

int main() {
    vector<double> x(2000);
    vector<double> y(2000);

    double s = 2 * numbers::pi / (1999);
    for (int i = 0; i < 2000; ++i) {
        x[i] = - numbers::pi + i * s;
        y[i] = sin(x[i]);
    }

    double a = ((double) rand() / RAND_MAX) * 2 - 1;
    double b = ((double) rand() / RAND_MAX) * 2 - 1;
    double c = ((double) rand() / RAND_MAX) * 2 - 1;
    double d = ((double) rand() / RAND_MAX) * 2 - 1;
    
    for (int t = 0; t < 2000; ++t) {
        vector<double> y_pred(2000);
        for (int i = 0; i < 2000; ++i) {
            y_pred[i] = a + b * x[i] + c * x[i] * x[i] + d * x[i] * x[i] * x[i];
        }

        double l = 0;
        for (int i = 0; i < 2000; ++i) {
            l += (y_pred[i] - y[i]) * (y_pred[i] - y[i]);
        }

        if (t % 100 == 99) {
            cout << t << " " << l << endl;
        }

        double a_grad = 0, b_grad = 0, c_grad = 0, d_grad = 0;

        for (int i = 0; i < 2000; ++i) {
            double grad_y_pred = 2.0 * (y_pred[i] - y[i]);
            a_grad += grad_y_pred;
            b_grad += grad_y_pred * x[i];
            c_grad += grad_y_pred * x[i] * x[i];
            d_grad += grad_y_pred * x[i] * x[i] * x[i];
        }
    }

    cout << "Result: y = " << a << " + " << b << " x + " << c << " x^2 + " << d << " x^3" << endl;
    return 0;
}

























