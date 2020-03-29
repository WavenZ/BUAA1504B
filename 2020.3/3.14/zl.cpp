#include <iostream>

using namespace std;

class Sum{
public:
    Sum(){ sum = sum + (++cnt); }
    static int getSum(){
        int temp = sum;
        cnt = sum = 0;
        return temp;
    }
private:
    static int cnt;
    static int sum;
};
int Sum::sum = 0;
int Sum::cnt = 0;
int calc_sum(int n){
    Sum* sum = new Sum[n];
    int res = Sum::getSum();
    delete[] sum;
    return res;
}
int main(int argc, char* argv[]){
    int res1 = calc_sum(10);
    int res2 = calc_sum(12);
    cout << res1 << " " << res2 <<  endl;
    return 0;
}