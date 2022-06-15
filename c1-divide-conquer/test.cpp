#include "../../programming-library/infint/InfInt.h"
#include <string>
#include <vector>
#include <iostream>
#include <math.h>       /* ceil */
#include <cmath>

using namespace std;
// int main()
// {
// InfInt myint1 = "15432154865413186646848435184100510168404641560358";
// InfInt myint2 = 156341300544608LL;

// // myint1 *= --myint2 - 3;
// std::cout << myint2 << std::endl << "DONE!";
// }

// ====================
// Class definition
// ====================

class Karatsuba
{
    /* Karatsuba's alogrithm on integer multiplication */
    public:

    vector<string> pad_zero(InfInt num1, InfInt num2)
    {
        string str1 = num1.toString();
        string str2 = num2.toString();
        int n1 = str1.length() - str2.length();
        while (!(n1 == 0))
        {
            if (n1 > 0) str2 = '0' + str2;
            if (n1 < 0) str1 = '0' + str1;
            n1 = str1.length() - str2.length();
        }
        vector<string> str = {str1, str2};
        return str;
    }

    InfInt mul(InfInt num1, InfInt num2)
    {
        vector<string> num = pad_zero(num1, num2);
        int n = num[0].length();

        if (n > 1)
        {
            int hdigit = ceil(n/2.);

            string a = num[0].substr(0, hdigit);
            string b = num[0].substr(hdigit, n - hdigit);
            string c = num[1].substr(0, hdigit);
            string d = num[1].substr(hdigit, n - hdigit);

            InfInt ac = mul(InfInt(a), InfInt(c));
            InfInt bd = mul(InfInt(b), InfInt(d));

            InfInt a_b = InfInt(a) + InfInt(b);
            InfInt c_d = InfInt(c) + InfInt(d);
            InfInt sum = mul(a_b, c_d);
            InfInt ad_bc = sum - ac - bd;

            InfInt res = ac*pow(10,((n - hdigit)*2)) + ad_bc*pow(10,(n - hdigit)) + bd;
            // cout << res << endl;
            return res;
        }
        else
            return num1*num2;
    }
};

int main()
{
    Karatsuba alg;
    InfInt num1 = "89993";    // Only work with small numbers
    InfInt num2 = "99993";
    // vector<string> num = alg.pad_zero(num1, num2);
    // for (const string& c : num)
    //     cout << c << ' ';
    cout << endl << alg.mul(num1, num2) << endl;
    // cout << num1*num2;
}