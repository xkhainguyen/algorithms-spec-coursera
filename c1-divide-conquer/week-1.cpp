#include <string>
#include <vector>
#include <iostream>
#include <math.h>       /* ceil */
#include <cmath>

using namespace std;

class Karatsuba
{
    /* Karatsuba's alogrithm on integer multiplication */
    public:

    vector<string> pad_zero(string num1, string num2)
    {
        int n0 = num1.length() - num2.length();
        while (!(n0 == 0))
        {
            if (n0 > 0) num2 = '0' + num2;
            if (n0 < 0) num1 = '0' + num1;
            n0 = num1.length() - num2.length();
        }
        vector<string> num = {num1, num2};
        return num;
    }

    string mul(const string num1, const string num2)
    {
        vector<string> num = pad_zero(num1, num2);
        int n = num[1].length();
        if (n > 1)
        {
            int hdigit = ceil(n/2.);

            string a = num[0].substr(0, hdigit);
            string b = num[0].substr(hdigit, n - hdigit);
            string c = num[1].substr(0, hdigit);
            string d = num[1].substr(hdigit, n - hdigit);

            string ac = mul(a, c);
            string bd = mul(b, d);

            string a_b = to_string(stoi(a) + stoi(b));
            string c_d = to_string(stoi(c) + stoi(d));
            string sum = mul(a_b, c_d);
            string ad_bc = to_string(stoi(sum) - stoi(ac) - stoi(bd));

            int a1 = stoi(ac)*pow(10,((n - hdigit)*2));
            int a2 = stoi(ad_bc)*pow(10,(n - hdigit));
            int a3 = stoi(bd);
            string res = to_string(a1 + a2 + a3);
            // cout << res << endl;
            return res;
        }            
        else
            return to_string(stoi(num1)*stoi(num2));
    } 
};

int main()
{
    Karatsuba alg;
    string num1 = {"12593"};    // Only work with small numbers
    string num2 = {"36623"};
    vector<string> num = alg.pad_zero(num1, num2);
    for (const string& c : num)
        std::cout << c << ' ';
    cout << endl << alg.mul(num1, num2) << endl;
    cout << stoi(num1)*stoi(num2);
}