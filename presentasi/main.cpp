#include <array>
#include <iostream>
#include <chrono>

using namespace std;

void insertionSwap (int arr[], int i) {
  // basis
  if (i == 0) return;

  if (arr[i - 1] > arr[i]) {
    swap(arr[i - 1], arr[i]);
  }

  // recurse
  insertionSwap(arr, i - 1);
}

void insertionSort (int arr[], int n, int lindex = 0) {
  // basis
  if (lindex == n) return;

  // for (int i = lindex; i > 0; i--) {
  //   if (arr[i - 1] > arr[i]) {
  //     swap(arr[i], arr[i - 1]);
  //   }
  // }
  insertionSwap(arr, lindex);

  // recurse
  insertionSort(arr, n, lindex + 1);
}

void bubbleSwap (int arr[], int n, int lindex = 0) {
  // basis
  if (lindex == n) return;

  if (arr[lindex] > arr[lindex + 1]) {
    swap(arr[lindex], arr[lindex + 1]);
  }

  // recurse
  bubbleSwap(arr, n, lindex + 1);
}

void bubbleSort (int arr[], int n, int lindex = 0) {
  // basis
  if (lindex == n - 1) return;

  // for (int i = 0; i < n - lindex - 1; i++) {
  //   if (arr[i] > arr[i + 1]) {
  //     swap(arr[i], arr[i + 1]);
  //   }
  // }
  bubbleSwap(arr, n - lindex - 1);

  // recurse
  bubbleSort(arr, n, lindex + 1);
}

int selectionSwap (int arr[], int n, int minIndex , int lindex = 0) {
  // basis
  if (lindex == n) return minIndex;

  if (arr[minIndex] > arr[lindex]) minIndex = lindex;

  // return recurse
  return selectionSwap(arr, n, minIndex, lindex + 1);
};

void selectionSort (int arr[], int n, int lindex = 0) {
  // basis
  if (lindex == n - 1) return;

  int minIndex = selectionSwap(arr, n, lindex, lindex);
  // int minIndex = lindex;
  // for (int i = lindex + 1; i < n; i++) {
  //   if (arr[minIndex] > arr[i]) minIndex = i;
  // }
  swap(arr[minIndex], arr[lindex]);

  // recurse
  selectionSort(arr, n, lindex + 1);
}

int main () {
  const int n = 10;
  int arr[n];

  // init
  for (int i = 0; i < n; i++) {
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    arr[i] = rand() % 100;
    cout << arr[i] << ", ";
  }
  cout << endl;

  selectionSort(arr, n);

  for (int i = 0; i < n; i++) {
    cout << arr[i] << ", ";
  }

  return 0;
}
