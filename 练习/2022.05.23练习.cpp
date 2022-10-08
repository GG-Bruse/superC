//f(x) = 0

#include<iostream>
#include<iomanip>

using namespace std;

double f(double x)
{
        return 2 * x * x * x - 4 * x * x + 3 * x - 6;
}

double SeachRet(double a, double b, double n)
{
        if (f(a) * f(b) > 0)
                return 0;
        while (1)
        {
                double x = (a + b) * 0.5;
                double y = abs(f(x));
                if (y < n)
                        return x;
                if (f(x) * f(b) < 0)
                        a = x;
                else
                        b = x;
        }
}

int main()
{
        double a, b;
        cout << "输入区间范围:";
        cin >> a >> b;
        double m = SeachRet(a, b, 0.001);
        int i = 0;
        cout << "函数 f(x) = 2x^3 - 4x^2 + 3x - 6 在区间[" << a << "," << b << "]上的根为：";
        cout << setiosflags(ios::fixed) << setprecision(3) << m << endl;
        return 0;
}

