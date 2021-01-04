package BOJ;
import java.io.*;
import java.util.*;
public class Java_2470 {

    static int N;
    static int[] arr,ans = new int[2];
    static long mn = (long)Long.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(bf.readLine());
        arr = new int[N];
        StringTokenizer st = new StringTokenizer(bf.readLine());
        for (int i = 0; i < N; i++) arr[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(arr);
        int l = 0, r = N-1;
        while(l<r){
            long sum = (long)arr[l] + (long)arr[r];
            if(Math.abs(sum)<mn){
                mn = Math.abs(sum);
                ans[0] = arr[l];
                ans[1] = arr[r]; 
            }
            if(sum>0) r--;
            else l++;
        }
        System.out.println(ans[0] + " " + ans[1]);
    }
}
