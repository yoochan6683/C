#include<iostream>
#include<vector>

using namespace std;
// template function to perform sort on array, arr
// n: size of arr

template<typename T>
void MySort(T arr[], int n)
{
    T* arr2 = new T[n];

    for (int i=0; i<n; i++) {
        arr2[i] = arr[i];
    }

    int i = 0;
    while(n > 0) {
        T minVal = arr2[0];
        int minIndex = 0;
        for (int j=1; j<n; j++) {
            if (arr2[j] < minVal) {
                minVal = arr2[j];
                minIndex = j;
            }
        }

        arr[i] = minVal;

        for (int j = minIndex; j<n-1; j++) {
            arr2[j] = arr2[j+1];
        }

        n--;
        i++;
    }

    delete[] arr2;
    /* Implement this part!!

    create a new arr2[] from the heap;
    

    copy arr[] into arr2[];

    int i = 0;

    loop(some sonditions) {

        Find the min from arr[];

        insert the min into arr2[i];

        Remove the min from arr[];

        i++;

     } 

     copy arr2[] into arr[];

     delete [] arr2;

     */

}
// Template function to print array

// n: size of arr[]

template<typename T>

void PrintArray(T arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()

{
    int arr[] = { 1, 10, 90, 100, -1, 11, 9, 14, 3, 2, 20, 19 };
    int n = sizeof(arr) / sizeof(int);
    MySort(arr, n);
    PrintArray(arr, n);

    char arr2[] = { 'c', 'x', 'a', 't', 'r', 'z' };
    n = sizeof(arr2) / sizeof(char);
    MySort(arr2, n);
    PrintArray(arr2, n);

    double arr3[] = { -1000.3, -1, 100.3, 100.1, 1000, -200 };
    n = sizeof(arr3) / sizeof(double);
    MySort(arr3, n);
    PrintArray(arr3, n);
}