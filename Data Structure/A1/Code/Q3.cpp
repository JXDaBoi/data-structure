#include <iostream>

using namespace std;

//Merge function using merging algorithm from mergesort
void merge(int *a, int size_a, int *b, int size_b, int *temp)
{
    int i = 0, j = 0, x = 0;

    //Check if one of the loop has reached the end
    while (i < size_a && j < size_b)
    {
        //To push the larger number into the temp array
        if (a[i] >= b[j])
        {
            temp[x] = a[i];
            x++;
            i++;
        }
        else if (a[i] < b[j])
        {
            temp[x] = b[j];
            x++;
            j++;
        }
    }

    //While loop to push the remaining values in array a to temp array after array b has reached the end from the first while loop
    while (i < size_a)
    {
        temp[x] = a[i];
        i++;
    }

    //While loop to push the remaining values in array b to temp array after array a has reached the end from the first while loop
    while (j < size_b)
    {
        temp[x] = b[j];
        j++;
    }
}

int main()
{
    //Declaration of variables
    int size_1, size_2;

    //Input for array size
    cout << "Please enter the size of Array 1: ";
    cin >> size_1;

    //Input validation
    while (size_1 <= 0)
    {
        cout << "\nPlease enter a number larger than 0.\n";
        cout << "Please enter the size of Array 1: ";
        cin >> size_1;
    }

    //Declare array1
    int array1[size_1];

    //User input
    for (int i = 0; i < size_1; i++)
    {
        cout << "Please enter the value of array1[" << i << "]: ";
        cin >> array1[i];
        cout << endl;

        //To make sure it is in descending order
        if ((array1[i] > array1[i - 1]) && i != 0)
        {
            cout << "The integer you have entered is larger than the previous integer.\n\n";
            i--;
        }
    }

    //Input for array size
    cout << "Please enter the size of Array 2: ";
    cin >> size_2;

    //Input validation
    while (size_2 <= 0)
    {
        cout << "\nPlease enter a number larger than 0.\n";
        cout << "Please enter the size of Array 2: ";
        cin >> size_2;
    }

    //Declare array2
    int array2[size_2];

    //User input
    for (int i = 0; i < size_2; i++)
    {
        cout << "Please enter the value of array1[" << i << "]: ";
        cin >> array2[i];
        cout << endl;

        //To make sure it is in descending order
        if ((array2[i] > array2[i - 1]) && i != 0)
        {
            cout << "The integer you have entered is larger than the previous integer.\n\n";
            i--;
        }
    }

    //Declare temparr
    int temparr[size_1 + size_2];

    //Calls the merge function
    merge(array1, size_1, array2, size_2, temparr);

    cout << "The temparr = ";

    //Printing temparr
    for (int i = 0; i < (size_1 + size_2); i++)
    {
        cout << temparr[i] << " ";
    }

    cout << "\n\n";

    return 1;
}