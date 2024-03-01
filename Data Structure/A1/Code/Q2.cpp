#include <iostream>

using namespace std;

//Function prototypes
int fOdd(int n);
int fEven(int n);

int fOdd(int n)
{
    //Check if n is equals to 0 or to call the recursion
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return 3 + fEven(n - 1);
    }
}

int fEven(int n)
{
    //Check if n is equals to 0 or to call the recursion
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return 4 * fOdd(n - 1);
    }
}

int main()
{
    //Declaration of variable
    int n;

    //Ask for user input
    cout << "Please enter the value of n: ";
    cin >> n;
    cout << endl;

    //Input validation
    while (n < 0)
    {
        cout << "The value of n you have entered is not valid.\n";
        cout << "Please enter the value of n again (n>=0): ";
        cin >> n;
        cout << endl;
    }

    //To check if the user input is even or odd number, then trigger the function
    if (n % 2 == 0)
    {
        cout << "The result of the mathematical formula is " << fEven(n) << ".\n\n";
    }
    else
    {
        cout << "The result of the mathematical formula is " << fOdd(n) << ".\n\n";
    }

    return 1;
}