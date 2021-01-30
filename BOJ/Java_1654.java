
import java.util.*;

public class Java_1654 {
    static int K,N,mxLength;
    static int[] arr;
    static long mx;
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        K = sc.nextInt();
        N = sc.nextInt();
        arr = new int[K];
        for(int i=0;i<K;i++) {
            arr[i] = sc.nextInt();
            mxLength = Math.max(mxLength,arr[i]);
        }
        long l = 1, r = mxLength;
        while(l<=r){
            long cnt = 0;
            long mid = (l+r)/2;
            for(int i=0;i<K;i++){
                cnt += ((long)arr[i]/(long)mid);
            }
            if(cnt<N) r = mid-1;
            else {
                mx = Math.max(mx,mid);
                l = mid+1;
            }
        }
        System.out.println(mx);
    }
}
