#include <iostream>

bool is_contains(int arr[], int length, int find_num) {
    int low = 0;
    int high = length - 1;
    int mid = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == find_num) {
            return true;
        }
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            while(low != mid && arr[low] == arr[mid]) {
                low++;
            } 
            if (low == mid){
                low = mid + 1;
                continue;
            }
        }
        
        if (arr[low] != arr[mid]) {
            if (arr[low] < arr[mid]) {
                if(find_num >= arr[low] && find_num < arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if(find_num > arr[mid] && find_num <= arr[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        } else {
            if (arr[mid] < arr[high]) {
                if(find_num > arr[mid] && find_num <= arr[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else {
                if(find_num >= arr[low] && find_num < arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
    int arr[] = { 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 1, 2, 3, 4, 5 };
    int num = 20;
    std::string str_result = is_contains(arr, sizeof(arr)/sizeof(int), num) ? "true": "false";
    std::cout<< str_result
        <<std::endl;
}
