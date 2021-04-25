#include<iostream>

using namespace std;
long long X,Y;
int main() {
    cin >> X >> Y;
    long long Z = (Y*100)/X;
    long long l=0, r=1'000'000'000;

    if(Z>=99) {
        cout << -1;
        return 0;
    }

    long long add;

    while(l<=r) {
        add = (l+r)/2;
        
        long long current_X = X + add;
        long long current_Y = Y + add;

        long long current_Z = (100*current_Y) / current_X;
        
        if(current_Z > Z) r = add-1;
        else add = l = add + 1;
    }

    cout << add;
}