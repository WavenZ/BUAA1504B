#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

template<typename T>
class Quick_sort{
public:
    static void sort(vector<T>& arr){
        if(arr.empty()) return;
        quick_sort(arr, 0, arr.size() - 1);
    }
private:
    static void quick_sort(vector<T>& arr, int start, int end){
        if(start >= end) return;
        int pos = partition(arr, start, end);
        quick_sort(arr, start, pos - 1);
        quick_sort(arr, pos + 1, end);
    }
    static int partition(vector<T>& arr, int start, int end){
        default_random_engine e;
        uniform_int_distribution<int> u(start, end);
        swap(arr[end], arr[u(e)]);
        int pivot = arr[end];
        int pos = start;
        for(int i = start; i < end; ++i){
            if(arr[i] < pivot){
                swap(arr[i], arr[pos++]);
            }
        }
        swap(arr[pos], arr[end]);
        return pos;
    }
};


int main(int argc, char* argv[]){
    vector<int> arr = {3,7,1,2,3,0,4,0,3,4,7,1,9};
    Quick_sort<int>::sort(arr);
    for(const int& a : arr)
        cout << a << " ";
    cout << endl;
    return 0;
}
