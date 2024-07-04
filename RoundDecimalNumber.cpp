#include <bits/stdc++.h>
using namespace std;
int main()
{
    double a = 0.123456;
    double b = 0.987654;

    double result = a * b;
    double rounded_number = round(result * 1e6) / 1e6;
    // Set precision to 6 decimal places
    cout << fixed << setprecision(6) << result << endl;
    cout << rounded_number << endl;
    if (result < 1e-6)
        std::cout << result << std::endl;
    else
        std::cout << "Result exceeds 10^-6" << std::endl;

    return 0;
};
