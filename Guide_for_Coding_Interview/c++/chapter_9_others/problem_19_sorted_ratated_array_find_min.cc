#include <iostream>
#include <vector>

int get_min(int arr[], int length) {
    int low = 0;
    int high = length;
    int mid = 0;
    while (low < high) {
        if (low == high - 1) {
            break;
        }

        if (arr[low] < arr[high]) {
            return arr[low];
        }

        mid = (low + high) / 2;
        if (arr[low] > arr[mid]) {
            high = mid;
            continue;
        } 

        if (arr[mid] > arr[high]) {
            low = mid;
            continue;
        }

        while (low < mid) {
            if (arr[low] == arr[mid]) {
                low++;
            } else if (arr[low] < arr[mid]) {
                return arr[low];
            } else {
                high = mid;
                break;
            }
        }
    }
    return std::min(arr[low], arr[high]);
}

int main (int argc, char* argv[]) {
    int arr[] = { 4, 5, 5, 5, 1, 2, 3 };
    std::cout<<get_min(arr, sizeof(arr)/sizeof(int))<<std::endl;
}
