// Perry Bunn
// ptb0010
// hw4_ptb0010.cpp
// program that merges the numbers in two files and writes all the numbers into a
// third file. Your program takes input from two different files and writes its output to a
// third file. Each input file contains a list of numbers of type int in sorted order from the
// smallest to the largest. After the program is run, the output file will contain all the
// numbers in the two input files in one longer list in sorted order from smallest to largest.
// Help

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

const int MAX_SIZE = 100;

// returns the size of the file "array"
int readFileSize(char inputArray[], ifstream &instream) {
    int index = 0;
    char temp;
    instream >> temp;
    inputArray[index] = (int)(temp);
    cout << inputArray[index] << "\n";
    index++;
    while (!instream.eof()) {
        instream >> inputArray[++index];
        cout << inputArray[index] << "\n";
    }
    return index;
}



int sort(int inputArray1[], int inputArray1_size,
         int inputArray2[], int inputArray2_size, int outputArray[]) {
    return 0;
}

void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void writefile(int outputArray[], ifstream &outputArray_size) {

}

int main() {
    cout << "*** Welcome to Perry Bunn's sorting program ***\n";
    cout << "Enter the first input file name:\t";
    string fileName1;
    cin >> fileName1;
    ifstream inStream1;
    inStream1.open((char*)fileName1.c_str());
    char blank[MAX_SIZE];
    int index = readFileSize(blank, inStream1);
    inStream1.close();
    cout << "The list of " << index << " numbers in file input1.txt is:" << fileName1 << "\n";
    return 0;
}
