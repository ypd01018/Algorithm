package BOJ;

import java.io.*;
import java.util.*;

public class Java_1967 {
    
    static class NextNode {
        public int nextNodeNum;
        public int dis;
        public NextNode(int nextNodeNum,int dis) {
            this.nextNodeNum = nextNodeNum;
            this.dis = dis;
        }
    }

    static int N;
    static ArrayList<NextNode>[] list = new ArrayList[10001];
    static int totalMx;

    public static int dfs(int node) {

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int mx = 0;

        for(NextNode nextnode : list[node]) {
            int nextNodeNum = nextnode.nextNodeNum;
            int dis = nextnode.dis;
            pq.add(-1*(dis+dfs(nextNodeNum)));
        }
        int[] value = new int[2];
        for(int i=0;i<2 && !pq.isEmpty();i++) value[i] = -1*pq.poll();
        totalMx = Math.max(totalMx, value[0] + value[1]);
        return value[0];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(bf.readLine());
        for(int i=0;i<=N;i++) list[i] = new ArrayList<>();

        for(int i=0; i<N-1 ;i++) {
            StringTokenizer st = new StringTokenizer(bf.readLine());
            int parent = Integer.parseInt(st.nextToken());
            int child = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());

            list[parent].add(new NextNode(child, d));
        }
        dfs(1);

        System.out.println(totalMx);

    }
}
