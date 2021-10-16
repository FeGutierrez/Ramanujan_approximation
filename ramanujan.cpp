#include <iostream>
#include <cmath>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;
using namespace boost::multiprecision; //Include boost namespace
typedef number<cpp_dec_float<100>> cpp_dec_float_100; //define type
typedef number<cpp_dec_float<50>> cpp_dec_float_50; //define type
typedef number<cpp_dec_float<1000>> cpp_dec_float_1000; //define type

int factorial(int);

int factorial(int n) {
    int fact = 1;
    for (int ii = 1; ii <= n; ii++) {
        fact = fact * ii;
    }
    return fact;
}

cpp_dec_float_50 ramanujan_approx() {
    cpp_dec_float_50 ram_p = 0, one = 1;
    int k = 0;
    cpp_dec_float_50 proporcion = (2 * sqrt(2)) / 9801;
    bool flag = true;
    while (flag) {
        cpp_dec_float_50 numerador = (cpp_dec_float_50)factorial(k * 4) * (1103 + (26390 * k));
        cpp_dec_float_50 denominador = (cpp_dec_float_50) pow(396, k * 4) * pow(factorial(k), 4);
        cpp_dec_float_50 evaluado = (proporcion * numerador) / (cpp_dec_float_50) denominador;
        ram_p += evaluado;
        if (evaluado < 1e-1000) { //Machine zero
            flag = false;
        }
        ++k;
    }
    return one / ram_p; // 1 / (1/PI) --> PI
}

cpp_dec_float_100 ramanujan_approx2() {
    cpp_dec_float_100 ram_p = 0, one = 1;
    int k = 0;
    cpp_dec_float_100 proporcion = (2 * sqrt(2)) / 9801;
    bool flag = true;
    while (flag) {
        cpp_dec_float_100 numerador = (cpp_dec_float_100)factorial(k * 4) * (1103 + (26390 * k));
        cpp_dec_float_100 denominador = (cpp_dec_float_100)pow(396, k * 4) * pow(factorial(k), 4);
        cpp_dec_float_100 evaluado = (proporcion * numerador) / (cpp_dec_float_100)denominador;
        ram_p += evaluado;
        if (evaluado < 1e-300) { //Machine zero
            flag = false;
        }
        ++k;
    }
    return one / ram_p; // 1 / (1/PI) --> PI
}

cpp_dec_float_1000 ramanujan_approx3() {
    cpp_dec_float_1000 ram_p = 0, one = 1;
    int k = 0;
    cpp_dec_float_1000 proporcion = (2 * sqrt(2)) / 9801;
    bool flag = true;
    while (flag) {
        cpp_dec_float_1000 numerador = (cpp_dec_float_1000)factorial(k * 4) * (1103 + (26390 * k));
        cpp_dec_float_1000 denominador = (cpp_dec_float_1000)pow(396, k * 4) * pow(factorial(k), 4);
        cpp_dec_float_1000 evaluado = (proporcion * numerador) / (cpp_dec_float_1000)denominador;
        ram_p += evaluado;
        if (evaluado < 1e-300) { //Machine zero
            flag = false;
        }
        ++k;
    }
    return one / ram_p; // 1 / (1/PI) --> PI
}

int main(void) {
    cpp_dec_float_50 O = ramanujan_approx();
    cout << "PI Approximation using Ramanujan series with lower precision:\n" << fixed << setprecision(112) << O << endl;
    cpp_dec_float_100 N = ramanujan_approx2();
    cout << "PI Approximation using Ramanujan series with intermediate precision:\n" << fixed << setprecision(112) << N << endl;    
    cpp_dec_float_1000 P = ramanujan_approx3();
    cout << "PI Approximation using Ramanujan series with higher precision:\n" << fixed << setprecision(1008) << P << endl;
    return (0);
}