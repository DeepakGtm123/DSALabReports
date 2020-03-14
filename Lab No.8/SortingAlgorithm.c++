// C++ program for implementation of selection sort 

#include <bits/stdc++.h>
#include<iostream> 
using namespace std; 

void swap(int *xp, int *yp) { 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
}

int partition (int arr[], int low, int high){ 
	int pivot = arr[high]; // pivot 
	int i = (low - 1); // Index of smaller element 
	for (int j = low; j <= high - 1; j++){ 
		// If current element is smaller than the pivot 
		if (arr[j] < pivot){ 
			i++; // increment index of smaller element 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
}

void merge(int arr[], int l, int m, int r){ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 
	int L[n1], R[n2]; 
	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j]; 
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2){ 
		if (L[i] <= R[j]){ 
			arr[k] = L[i]; 
			i++; 
		} 
		else{ 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 
	while (i < n1){ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 
	while (j < n2){ 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
}

void heapify(int arr[], int n, int i){ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2  
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
    if (largest != i){ 
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); 
    } 
}  

// A function to implement selection sort
void selectionSort(int arr[], int n) { 
	int i, j, min_idx; 
	// One by one move boundary of unsorted subarray 
	for (i = 0; i < n-1; i++) { 
		// Find the minimum element in unsorted array 
		min_idx = i; 
		for (j = i+1; j < n; j++) 
		if (arr[j] < arr[min_idx]) 
			min_idx = j; 
		// Swap the found minimum element with the first element 
		swap(&arr[min_idx], &arr[i]); 
	} 
} 

// A function to implement insertion sort
void insertionSort(int arr[], int n){ 
	int i, key, j; 
	for (i = 1; i < n ; i++) { 
		key = arr[i]; 
		j = i - 1; 
		while (j >= 0 && arr[j] > key){ 
			arr[j + 1] = arr[j]; 
			j = j - 1; 
		} 
		arr[j + 1] = key; 
	} 
}

// A function to implement quick sort
void quickSort(int arr[], int low, int high){ 
	if (low < high){ 
		int pi = partition(arr, low, high); 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
}

// A function to implement bubble sort 
void bubbleSort(int arr[], int n){ 
	int i, j; 
	for (i = 0; i < n-1; i++)	 
	for (j = 0; j < n-i-1; j++) 
		if (arr[j] > arr[j+1]) 
			swap(&arr[j], &arr[j+1]); 
}

// A function to implement merge sort
void mergeSort(int arr[], int l, int r){ 
	if (l < r){ 
		int m = l+(r-l)/2; 
		// Sort first and second halves 
		mergeSort(arr, l, m); 
		mergeSort(arr, m+1, r); 
		merge(arr, l, m, r); 
	} 
} 

// A function to implement heap sort
void heapSort(int arr[], int n){ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
    for (int i=n-1; i>=0; i--) { 
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0); 
    } 
}

// Function to print an array 
void printArray(int arr[], int size) { 
	int i; 
	for (i=0; i < size; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

// Driver program to test above functions 
int main(){ 
	int arr[] = {64, 25, 12, 22, 11, 23, 56, 78, 89};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<< "Given array: \n"; 
	printArray(arr, n);
	cout<<endl;
	// Selection sort
	selectionSort(arr, n); 
	cout << "Selection Sorted Array: \n"; 
	printArray(arr, n);
	cout<<endl;
	// Insertion Sort
	insertionSort(arr, n);
	cout << "Insertion Sorted Array: \n";
	printArray(arr, n);
	cout<<endl;
	// Quick Sort
	quickSort(arr, 0, n - 1); 
	cout << "Quick Sorted Array: \n"; 
	printArray(arr, n);
	cout<<endl;
	// Merge sort
	mergeSort(arr, 0, n - 1); 
	cout << "Merge Sorted Array: \n" ; 
	printArray(arr,n);
	cout<<endl;
	// Heap sort
	heapSort(arr, n); 
	cout << "Heap Sorted Array: \n"; 
    	printArray(arr, n);
	 
	return 0; 
}
