#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void run();
string reverse(string);

int main()
{
    run();
    cout << "\nProgram Finised.\n";
}

string reverse(string str)
{
    int len = str.length();
    string newStr;

    for (int i = 0; i < len; i++)
    {
        newStr += str[len - 1 - i];
    }

    return newStr;
}

void run()
{
    int max = 0;
    for (int a = 500; a < 1000; a++)
    {
        for (int b = 500; b < 1000; b++)
        {
            stringstream ss;
            int product = a * b;
            ss << product;
            string productStr = ss.str();
            string reverseStr = reverse(productStr);

            if (productStr.compare(reverseStr) == 0)
            {
                if (product > max)
                {
                    max = product;
                    cout << "\rNew max palindrome found: " << product;
                    cout << "\ta, b = " << a << ", " << b;
                }
            }
        }
    }
}
