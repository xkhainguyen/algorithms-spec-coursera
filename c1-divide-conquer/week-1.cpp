#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Karatsuba
{
    //Karatsuba's alogrithm on integer multiplication
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

    // vector<string> mul(const string num1, const string num2)
    // {
    //     vector<string> num;
    //     int n;
    //     num = pad_zero(num1, num2);
    //     n = num[1].length();

    // } 
};

int main()
{
    Karatsuba alg;
    string num1 = {"1111"};
    string num2 = {"23"};
    vector<string> num = alg.pad_zero(num1, num2);
    for (const string& c : num)
        std::cout << c << ' ';
}