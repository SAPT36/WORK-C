// Binary search of a sorted array.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 15

// function prototypes
size_t binarySearch(const int b[], int searchKey, int low, int high);
void printHeader(void);
void printRow(const int b[], size_t low, size_t mid, size_t high);
void bubbleSort(int arr[], int len);
// function main begins program execution
int main(void)
{
    srand(time(NULL));

    int a[SIZE] = {0};// create array a
    int repeat[256] = { 0 };
    for (size_t i = 0; i < SIZE; ++i) {
        do {
            a[i] = rand() % 256;
        } while (repeat[a[i]]);
        repeat[a[i]]++;
    }
    bubbleSort(a,SIZE);
    for (size_t i = 0; i < SIZE; ++i) {
        printf("%d ", a[i]);
    }

    printf("%s", "\nEnter a number between 0 and 255: ");
    int key; // value to locate in array a
    scanf("%d", &key);

    printHeader();

    // search for key in array a
    size_t result = binarySearch(a, key, 0, SIZE - 1);

    // display results
    if (result != -1) {
        printf("\n%d found at index %d\n", key, result);
    }
    else {
        printf("\n%d not found\n", key);
    }
}

// function to perform binary search of an array
size_t binarySearch(const int b[], int searchKey, int low, int high)
{
    // loop until low index is greater than high index
    if (low > high || (low + high) / 2 < 0) {
        return -1;
    }
    else {
        // determine middle element of subarray being searched
        size_t middle = (low + high) / 2;

        // display subarray used in this loop iteration
        printRow(b, low, middle, high);

        // if searchKey matched middle element, return middle
        if (searchKey == b[middle]) {
            return middle;
        }

        // if searchKey is less than middle element, set new high
        else if (searchKey < b[middle]) {
            high = middle - 1; // search low end of array      
        }

        // if searchKey is greater than middle element, set new low
        else {
            low = middle + 1; // search high end of array     
        }
    }
    return binarySearch(b, searchKey, low, high);
}

// Print a header for the output
void printHeader(void)
{
    puts("\nSubscripts:");

    // output column head
    for (unsigned int i = 0; i < SIZE; ++i) {
        printf("%3u ", i);
    }

    puts(""); // start new line of output

    // output line of - characters
    for (unsigned int i = 1; i <= 4 * SIZE; ++i) {
        printf("%s", "-");
    }

    puts(""); // start new line of output
}

// Print one row of output showing the current
// part of the array being processed.
void printRow(const int b[], size_t low, size_t mid, size_t high)
{
    // loop through entire array
    for (size_t i = 0; i < SIZE; ++i) {

        // display spaces if outside current subarray range
        if (i < low || i > high) {
            printf("%s", "    ");
        }
        else if (i == mid) { // display middle element
            printf("%3d*", b[i]); // mark middle value
        }
        else { // display other elements in subarray
            printf("%3d ", b[i]);
        }
    }

    puts(""); // start new line of output
}
void bubbleSort(int arr[], int len)
{

    int i, j, temp;
     int exchanged = 1;

    for (i = 0; exchanged && i < len - 1; i++) { /* 外迴圈為排序趟數，len個數進行len-1趟,只有交換過,exchanged值為true才有執行迴圈的必要,否則exchanged值為false不執行迴圈 */
        exchanged = 0;
        for (j = 0; j < len - 1 - i; j++)
        { /* 內迴圈為每趟比較的次數，第i趟比較len-i次  */
            if (arr[j] > arr[j + 1])
            { /* 相鄰元素比較，若逆序則互換（升序為左大於右，逆序反之） */
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                exchanged = 1; /*只有數值互換過, exchanged才會從false變成true,否則數列已經排序完成,exchanged值仍然為false,沒必要排序 */
            }
        }
    }
}