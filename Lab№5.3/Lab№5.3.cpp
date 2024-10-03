#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double s(const double t);

int main()
{
    double tp, tk;
    int n;
    cout << "tp = "; cin >> tp;
    cout << "tk = "; cin >> tk;
    cout << "n = "; cin >> n;
    double dt = (tk - tp) / n;
    double t = tp;

    cout << "--------------------------" << endl;
    cout << "|    t    |     s(t)     |" << endl;
    cout << "--------------------------" << endl;

    while (t <= tk)
    {
        double result = s(2 * t + 1) + 2 * s(t * t) + sqrt(s(t));
        cout << "| " << setw(8) << fixed << setprecision(2) << t
            << " | " << setw(11) << setprecision(4) << result << " |" << endl;
        t += dt;
    }
    cout << "--------------------------" << endl;

    return 0;
}

double s(const double x)
{
    if (abs(x) >= 1 || x == 0)
        return (pow(cos(x), 2) + 1) / exp(x);
    else
    {
        double S = 1;
        double a = 1;
        for (int k = 0; k <= 4; k++)
        {
            a *= pow(2 * x, 2 * k + 1) / (2 * k + 1);
            S += a / sin(2 * x);
        }
        return S;
    }
}