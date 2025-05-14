#include<iostream>
#include<vector>
#include<algorithm>  
using namespace std;

// Linear Search function
int LinearSearch(vector<int>& arr, int n, int target){
    for(int i = 0; i < n; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

// Sort the array 
void sortArr(vector<int>& arr, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "Sorted array is: ";
    for(int j = 0; j < n; j++){
        cout << arr[j] << " ";
    }
    cout << endl;
}

// Binary Search function
int BinarySearch(vector<int>& arr, int n, int target){ 
    int i = 0, j = n - 1;
    while(i <= j){
        int mid = i + (j - i) / 2; // If extream value are there
        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] > target){
            j = mid - 1;
        }else{
            i = mid + 1;
        }
    }
    return -1;
}

int main(){
    cout << "======================================" << endl;
    cout << "\t Welcome to Search Visualizer " << endl;
    cout << "======================================" << endl;

    vector<int> arr;    // Create the arr vector to store the elements
    int n, target, choice, biAns, linAns, ele;

    cout << "Enter the size of array: ";    
    cin >> n;

    for(int i = 0; i < n; i++){
        cout << "Enter element " << i + 1 << ": ";
        cin >> ele;
        arr.push_back(ele);     // Store the element in the arr
    }

    cout << "The array is: " << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Enter the target: ";
    cin >> target;

    vector<int> sortedArr;      // Declare the sorted array of the given array
    do {
        cout << "\nOperations: " << endl;
        cout << "1. Linear search\n2. Binary search\n3. Exit" << endl;
        cout << "Which operation do you want to perform: ";
        cin >> choice;

        switch(choice){
            case 1:
                // Linear Search with the original unsorted array
                linAns = LinearSearch(arr, n, target);
                if(linAns != -1){
                    cout << "Target found at position " << linAns << endl;
                }
                else{
                    cout << "Target not found" << endl;
                }
                break;

            case 2:
                // Binary search with sorted array
                sortedArr = arr;
                sortArr(sortedArr, n);  

                biAns = BinarySearch(sortedArr, n, target); 
                if(biAns != -1){
                    cout << "Target found at position " << biAns << endl;
                } else {
                    cout << "Target not found" << endl;
                }
                break;

            case 3:
                cout << "Hope you enjoy this...\nThank you" << endl;
                cout << "Exiting....." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    } while(choice != 3);

    return 0;
}
