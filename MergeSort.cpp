#include <iostream>
using namespace std;

// Function to merge two sorted subarrays into one sorted array
void merge(int L[], int L_size, int R[], int R_size, int A[])
{
    int i = 0, j = 0, k = 0;

    // Merge the two subarrays into A[]
    while (i < L_size && j < R_size)
    {
        if (L[i] < R[j])
        {
            A[k++] = L[i++];
        }
        else
        {
            A[k++] = R[j++];
        }
    }

    // Copy remaining elements of L[], if any
    while (i < L_size)
    {
        A[k++] = L[i++];
    }

    // Copy remaining elements of R[], if any
    while (j < R_size)
    {
        A[k++] = R[j++];
    }
}

// Recursive function to perform merge sort
void mergesort(int array[], int size)
{
    if (size < 2)
    {
        return;
    }

    int mid = size / 2;

    // Create temporary arrays for the left and right subarrays
    int* Larray = new int[mid];
    int* Rarray = new int[size - mid];

    // Copy data to temporary arrays Larray[] and Rarray[]
    for (int i = 0; i < mid; i++)
    {
        Larray[i] = array[i];
    }
    for (int i = mid; i < size; i++)
    {
        Rarray[i - mid] = array[i];
    }

    // Recursively sort both subarrays
    mergesort(Larray, mid);
    mergesort(Rarray, size - mid);

    // Merge the sorted subarrays
    merge(Larray, mid, Rarray, size - mid, array);

    // Clean up dynamically allocated memory
    delete[] Larray;
    delete[] Rarray;
}

int main()
{
    int array[] = {5, 1, 6, 2, 3, 4};
    int size = sizeof(array) / sizeof(array[0]); 

    mergesort(array, size);

    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
