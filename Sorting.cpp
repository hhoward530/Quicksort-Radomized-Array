/*
* Written by: Hunter Howard
* 4/2/2023
* 
* The purpose of this code is to create an array of 10,000 numbers (0 through 9999),
* randomize the contents, and then quicksort the array. The time to sort the array
* is printed out.
*/

#include <iostream>
#include <stdlib.h>
#include <chrono>
using namespace std::chrono;

void quicksort(int arr[], int p, int r);
int partition(int arr[], int p, int r);

int main()
{
    srand((unsigned) time(0));
    int swap = 0;
    int* sortList = new int[10000]{};

    std::cout << "Initializing array...\n"; //initialize array 0-9999
    for (int i = 0; i < 10000; i++)
    {
        sortList[i] = i;
    }

    std::cout << "Randomizing array...\n";
    for (int i = 0; i < 10000; i++)
    {
        int randomizer = rand() % 9999;     //create a rondom number between 0 and 9999
        swap = sortList[randomizer];        //swap contents of index i with random index
        sortList[randomizer] = sortList[i];
        sortList[i] = swap;
    }

    /*//Test that array has been randomized
    for (int i = 0; i < 10000; i++)
    {
        std::cout << sortList[i] << std::endl;
    }
    */

    std::cout << "Sorting array...\n";
    auto start = high_resolution_clock::now();
    quicksort(sortList, 0, 9999);
    auto end = high_resolution_clock::now();

    /*//Test that array has been sorted
    for (int i = 0; i < 10000; i++)
    {
        std::cout << sortList[i] << std::endl;
    }
    */
    auto duration = duration_cast<microseconds>(end - start); //print sort time in microseconds
    std::cout << "Sorted array in " << duration.count() << " milliseconds\n";
}

/*
* Quicksort Function
* Accepts an array arr[], an int p (represents starting index of sort),
* and int r ( size of array - 1).
* Performs quicksort algorithm on arr[].
*/
void quicksort(int arr[], int p, int r)
{
    
    if (p < r)
    {
        int q = partition(arr, p, r); //function to partition array into smaller parts
        quicksort(arr, p, q - 1);     //recursion on first half of partition
        quicksort(arr, q + 1, r);     //partition on second half of partition
    }
}

/*
* Partition Function
* Accepts an array arr[], an int p (represents starting index of sort),
* and int r ( size of array - 1).
* Determines how to subdivide the array it is passed and returns the pivot index.
*/

int partition(int arr[], int p, int r)
{
    int x = arr[r]; //last index
    int i = p - 1;
    int y = 0;      //temp storage variable for swapping

    for (int j = p; j <= r - 1; j++)
    {
        if (arr[j] <= x) //if arr[j] is <= last index
        {
            i = i + 1;      //swap arr[i] and arr[j]
            y = arr[i];
            arr[i] = arr[j];
            arr[j] = y;
        }
    }
    y = arr[i + 1];         //swap arr[i+1] and arr[r]
    arr[i + 1] = arr[r];
    arr[r] = y;

    return i + 1;
}
