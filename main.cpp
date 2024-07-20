#include <iostream>
#include <ctime>
#include <windows.h>


using namespace std;

void FillArray(int* const arr, const int size);
void DisplayArray(const int* const arr, const int size);

void push_back(int*& arr, int& size, const int value);

int main(){
   srand(time(NULL));

   int size = 5;
   int* arr = new int[size];

    FillArray(arr, size);
    DisplayArray(arr, size);

    for (int i = 0; i < 5; i++) {
        push_back(arr, size, rand()%20+1);
        DisplayArray(arr, size);
    }
    
    return 0;
}

void FillArray(int* const arr, const int size) {
    for (int i=0; i<size; i++) {
        arr[i] = rand() % 50 + 1;
    }
}

void DisplayArray(const int* const arr, const int size) {
    cout << '[';
    for (int i=0; i<size; i++) {
        cout << arr[i];
        if (i+1 != size) {
            cout << ", ";
        }
    }
    cout << ']' << endl;
}

void push_back(int*& arr, int& size, const int value) {
    int* newArray = new int[size+1];

    for (int i=0; i<size; i++) {
        newArray[i] = arr[i];
    }

    newArray[size] = value;

    size++;

    delete[] arr;

    arr = newArray;
}


