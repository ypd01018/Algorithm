#include<iostream>

using namespace std;

int N;
int d[110][110];

int main() {
    
    cin >> N;

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> d[i][j];
            if(!d[i][j]) d[i][j] = 1e9;
        }
    }

    for(int k=0;k<N;k++) {
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++) {
                if(d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            int a = (d[i][j] == 1e9) ? 0 : 1;
            cout << a << ' ';
        }
        cout << endl;
    }

}