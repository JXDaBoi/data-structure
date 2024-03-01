#include <iostream>

using namespace std;

//Merging algorithm used by mergeSort algorithm
void merge(int a[], int head, int mid, int tail)
{
    //variables declaration
    int b[10];
    int h1 = head, t1 = mid, h2 = mid + 1, t2 = tail;
    int index = h1;

    /*
        For loop until one of the half array is
        completely merged into array b.
    */
    for (; (h1 <= t1) && (h2 <= t2); index++)
    {
        //Comparing elements between two half array
        if (a[h1] < a[h2])
        {
            b[index] = a[h1];
            h1++;
        }
        else
        {
            b[index] = a[h2];
            h2++;
        }
    }

    //To push the remaining elements into array b
    for (; h1 <= t1; h1++, index++)
    {
        b[index] = a[h1];
    }

    //To push the remaining elements into array b
    for (; h2 <= t2; h2++, index++)
    {
        b[index] = a[h2];
    }

    //Copy array b to array a
    for (index = head; index <= tail; index++)
    {
        a[index] = b[index];
    }
}

//mergeSort Function which calls recursive functions.
void mergeSort(int a[], int head, int tail)
{
    /*
        If the array is more than 2 elements,
        then run the below statements.

        It will calls recursive function which
        splits the array into halves.
        Then call the merge function to sort it
        and merge them.
    */
    if (head < tail)
    {
        int mid = (head + tail) / 2;
        mergeSort(a, head, mid);
        mergeSort(a, mid + 1, tail);

        merge(a, head, mid, tail);
    }
}

//Partion function used by quickSort
int partition(int a[], int head, int tail)
{
    //variables declaration
    int last1 = head, i = head + 1, pivot = head;

    /*
        While the array is larger than 1 element,
        it will then run the statements inside
        the while loop.
    */
    while (i <= tail)
    {
        /*
            The algorithm below is doing the partition
            of S1 and S2.
        */
        if (a[i] < a[pivot])
        {
            last1++;
            if (i != last1)
            {
                swap(a[i], a[last1]);
            }
        }
        i++;
    }
    /*
        Swap the head element with the last 1 element
        and point the pivot to the index of last1 element
    */
    swap(a[head], a[last1]);
    pivot = last1;

    //Return the index of pivot
    return pivot;
}

//quickSort function which calls the recursive functions
void quickSort(int a[], int head, int tail)
{
    //variable declaration
    int pivot;

    /*
        If the array is more than 1 element, then run the
        statements inside the if clause
    */
    if (head < tail)
    {
        /*
            Set the pivot index from the returned value
            by partition function
        */
        pivot = partition(a, head, tail);

        quickSort(a, head, pivot - 1);
        quickSort(a, pivot + 1, tail);
    }
}

//swap function
void swap(int &l, int &r)
{
    int temp = r;
    r = l;
    l = temp;
}

int main()
{
    //variables declaration
    int arr[10] = {24, 53, 66, 11, 44, 84, 25, 102, 32, 3};
    int tmpArr[10], a = 0, b = 5, n = 0;

    //Print out the array before sorting
    cout << "The array before sorting = ";

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    //Calls mergeSort on the first half of the array
    mergeSort(arr, 0, 4);

    //Print out the first half of the array after Merge Sort
    cout << "The first part of the array after Merge Sort = ";

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    //Calls quickSort on the last half of the array
    quickSort(arr, 5, 9);

    //Print out the last half of the array after Quick Sort
    cout << "The second part of the array after Quick Sort = ";

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i + 5] << " ";
    }
    cout << endl;

    //Print out the array before doing the final sorting
    cout << "The array before sorting the both part = ";

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    //Sorting both halves of the array by comparing the elements
    while (n < 10)
    {
        if (a < 5 && b < 10 && arr[a] <= arr[b])
        {
            tmpArr[n] = arr[a];
            a++;
            n++;
        }
        else if (a < 5 && b < 10 && arr[a] > arr[b])
        {
            tmpArr[n] = arr[b];
            b++;
            n++;
        }
        else if (a == 5)
        {
            tmpArr[n] = arr[b];
            b++;
            n++;
        }
        else
        {
            tmpArr[n] = arr[a];
            a++;
            n++;
        }
    }

    //Copy the elements from tmpArr to arr
    for (int i = 0; i < 10; i++)
    {
        arr[i] = tmpArr[i];
    }

    //Print out the array after sorting
    cout << "The array after sorting = ";

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n\n";

    return 1;
}