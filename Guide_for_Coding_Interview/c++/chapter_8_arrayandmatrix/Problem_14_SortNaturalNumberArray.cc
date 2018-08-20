#include <iostream>
#include <vector>

using namespace std;

void sort1_natural_number(vector<unsigned int> &arr) {
   unsigned int tmp = 0;
   unsigned int next = 0;
   size_t  arr_size = arr.size();
   for (size_t i = 0; i <  arr_size; i++) {
       tmp = arr[i];
       while (arr[i] != i + 1) {
           next = arr[tmp - 1];
           arr[tmp - 1] = tmp;
           tmp = next;
       }
   }
}

void sort2_natural_number(vector<unsigned int> &arr) {
    unsigned int tmp = 0;
    size_t arr_size = arr.size();
    for (size_t i = 0; i < arr_size; i++) {
        tmp = arr[i];
        while (arr[i] != i + 1) {
            tmp = arr[arr[i] - 1];
            arr[arr[i] - 1] = arr[i];
            arr[i] = tmp;
        }
    }
}

void print_array(vector<unsigned int>& arr) {
    size_t arr_size = arr.size();
    for (size_t i = 0; i < arr_size; i++) {
        cout<<arr[i]<<",";
    }
    cout<<endl;
}
int main(int argc, char* argv[]) {
    unsigned int a[9] = {8, 2, 1, 6, 9, 3, 7, 5, 4};
    vector<unsigned int> arr1(a, a+9);

    cout<<"Input:"<<endl;
    print_array(arr1);

    sort1_natural_number(arr1);
    cout<<"Method1 Output:"<<endl;
    print_array(arr1);

    vector<unsigned int> arr2(a, a+9);
    sort2_natural_number(arr2);
    cout<<"Method2 Output:"<<endl;
    print_array(arr2);

    return 0;
}
