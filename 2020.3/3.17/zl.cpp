#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <queue>
using namespace std;

template<typename T>
class TopK{
public:
    static vector<T> search(vector<T>& arr, unsigned k){
        if(arr.size() <= k) return vector<T>(arr.begin(), arr.end());
        quick_search(arr, 0, arr.size() - 1, k);
        return vector<T>(arr.begin(), arr.begin() + k);
    }
private:
    static void quick_search(vector<T>& arr, int start, int end, unsigned k){
        int pos = partition(arr, start, end);
        if(pos == k) return;
        else if(pos < k) quick_search(arr, pos + 1, end, k);
        else quick_search(arr, start , pos - 1, k);
    }
    static int partition(vector<T>& arr, int start, int end){
        default_random_engine e;
        uniform_int_distribution<unsigned> u(start, end);
        swap(arr[end], arr[u(e)]);
        int pivot = arr[end];
        int pos = start;
        for(int i = start; i < end; ++i){
            if(arr[i] < pivot){
                swap(arr[pos++], arr[i]);
            }
        }
        swap(arr[pos], arr[end]);
        return pos;
    }
};

int climb_stairs(int n){
    if(n <= 0) return 0;
    if(n <= 2) return n;
    int ans, ans1 = 1, ans2 = 2;
    for(int i = 3; i <= n; ++i){
        ans = ans1 + ans2;
        ans2 = ans1;
        ans1 = ans;
    }
    return ans;
}

int main(int argc, char* argv[]){
    vector<int> arr = {3, 8, 1, 0, 9, 4, 4, 2, 7, 1, 2, 5, 7, 3};
    vector<int> brr = TopK<int>::search(arr, 8);
    for(const int& b : brr)
        cout << b << " ";
    cout << endl;
    for(int i = 0; i < 10; ++i){
        cout << climb_stairs(i) << " ";
    }
    cout << endl;
    return 0;
}