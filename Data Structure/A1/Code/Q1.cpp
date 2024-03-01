#include <iostream>

using namespace std;

int binarySearch(int *a, int head, int tail, int x) //Function for Binary Search
{
    //If condition is used here to prevent the mid iterator to go over the head or tail
    if (head <= tail)
    {
        //Calculate the mid point
        int mid = (head + tail) / 2;

        //Check if the middle value is smaller than x
        if (a[mid] < x)
        {
            //Call recursion with head set to mid+1 and tail set to itself
            return binarySearch(a, mid + 1, tail, x);
        }

        //Check if the middle value is larger than x
        if (a[mid] > x)
        {
            //Call recursion with head set to itself and tail set to mid-1
            return binarySearch(a, head, mid - 1, x);
        }

        //Check if the value is found
        if (a[mid] == x)
        {
            return mid;
        }
    }

    //To let the result checking statement to know the value does not exist
    return -1;
}

int main()
{
    //Declaration of variables
    int size = 10, result, num;
    int arr[size], mid = (0 + (size - 1)) / 2;

    //Loop to accept user input into each array index
    for (int i = size - 1; i >= 0; i--)
    {
        cout << "Please enter an integer into arr[" << i << "] : ";
        cin >> arr[i];
        cout << endl;

        /*
            If statement -> To make sure it is in descending order
            Else if statement -> To make sure the integer is unique
        */
        if ((arr[i] > arr[i + 1]) && i != size - 1)
        {
            cout << "The integer you have entered is larger than the previous integer.\n\n";
            i++;
        }
        else if (arr[i] == arr[i + 1] && i != size - 1)
        {
            cout << "The integer you have entered is not unique.\n\n";
            i++;
        }
    }

    //Asking user input
    cout << "What integer are you finding in the array? ";
    cin >> num;

    //Store the returned value from the binarySearch function
    result = binarySearch(arr, 0, size - 1, num);

    //Check result for the returned value from binarySearch
    if (result == -1)
    {
        cout << "\nThe integer does not exist in the array.\n";
    }
    else
    {
        cout << "\nThe integer is located at index [" << result << "] of the array.\n\n";
    }

    return 1;
}