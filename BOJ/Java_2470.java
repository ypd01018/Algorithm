package BOJ;

import java.util.*;

public class Java_2470 {
    static int N;
    static int[] arr, ans;
    static long mn=Long.MAX_VALUE;
    public static void input(){
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        arr = new int[N];
        ans = new int[3];
        for (int i = 0; i < N; i++) arr[i] = sc.nextInt();
    }
    public static void solve(){
        Arrays.sort(arr);
        for(int i=0;i<N;i++){
            for(int j=i+2;j<N;j++){
                long sum = (long) arr[i] + (long) arr[j];
                int l = i+1, r = j-1;
                while(l<=r){
                    int mid = (l+r)/2;
                    long threeSum = sum + (long)arr[mid];
                    if(Math.abs(threeSum)<mn){
                        mn = Math.abs(threeSum);
                        ans[0] = arr[i];
                        ans[1] = arr[mid];
                        ans[2] = arr[j];
                    }
                    if(threeSum < 0) l = mid+1;
                    else if(threeSum > 0) r = mid-1;
                    else break;
                }
            }
        }
    }
    public static void print(){
        for(int i=0;i<3;i++) System.out.print(ans[i]+" ");
    }
    public static void main(String[] args) {
        input();
        solve();
        print();
    }
}
