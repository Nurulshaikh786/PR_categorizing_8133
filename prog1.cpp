#include <iostream>
#include <vector>
using namespace std;

class SortingAlgorithms {
public:
    void selectionSort(vector<int> &arr, int n) {
        int min, i, j;
        for (i = 0; i < n - 1; i++) {
            min = i;
            for (j = i + 1; j < n; j++) {
                if (arr[j] < arr[min]) {
                    min = j;
                }
            }
            swap(arr[i], arr[min]);
        }
    }

    void mergeSorting(vector<int> &arr, int start, int mid, int end) {
        vector<int> temp;
        int i = start, j = mid + 1;

        while (i <= mid && j <= end) {
            if (arr[i] < arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
            }
        }
        while (i <= mid) {
            temp.push_back(arr[i++]);
        }
        while (j <= end) {
            temp.push_back(arr[j++]);
        }
        for (int k = 0; k < temp.size(); k++) {
            arr[start + k] = temp[k];
        }
    }

    void mergeSort(vector<int> &arr, int start, int end) {
        if (start >= end)
            return;
        int mid = (start + end) / 2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        mergeSorting(arr, start, mid, end);
    }

    bool sortcheck(vector<int> &arr, int n) {
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i - 1]) {
                return false;
            }
        }
        return true;
    }
};

class SearchingAlgorithms {
public:
    int linearSearch(vector<int> &arr, int element) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == element) {
                return i;
            }
        }
        return -1;
    }

    int binarySearch(vector<int> &arr, int element) {
        int left = 0, right = arr.size() - 1, found = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == element) {
                found = mid;
                break;
            } else if (arr[mid] < element) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (found != -1)
            cout << "Element found at index: " << found << endl;
        else
            cout << "Element not found." << endl;
        return found;
    }
};

class Show : public SortingAlgorithms, public SearchingAlgorithms {
public:
    void display(vector<int> &arr, int n) {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Show sort;
    int n, choice;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    do {
        cout << "\n========================================\n";
        cout << "0. Exit Program\n";
        cout << "1. Display Array\n";
        cout << "2. Selection Sort\n";
        cout << "3. Merge Sort\n";
        cout << "4. Linear Search\n";
        cout << "5. Binary Search (APPLICABLE AFTER SORTING)\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 0:
            cout << "\nSuccessfully Exited The Program!!!\n";
            break;

        case 1:
            sort.display(arr, n);
            break;

        case 2:
            sort.selectionSort(arr, n);
            cout << "Array sorted using Selection Sort.\n";
            break;

        case 3:
            sort.mergeSort(arr, 0, n - 1);
            cout << "Array sorted using Merge Sort.\n";
            break;

        case 4: {
            int element;
            cout << "Enter element to search: ";
            cin >> element;
            int index = sort.linearSearch(arr, element);
            if (index != -1)
                cout << "Element found at index: " << index << endl;
            else
                cout << "Element not found." << endl;
            break;
        }

        case 5: {
            if (sort.sortcheck(arr, n)) {
                int element;
                cout << "Enter element to search: ";
                cin >> element;
                sort.binarySearch(arr, element);
            } else {
                cout << "Array is not sorted. Please sort it first using option 2 or 3.\n";
            }
            break;
        }

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
