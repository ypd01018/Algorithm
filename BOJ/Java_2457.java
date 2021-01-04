package BOJ;

import java.util.*;
import java.io.*;

public class Java_2457 {
    static int N;
    static int[] monthDay = {31,28,31,30,31,30,31,31,30,31,30,31};
    public static class Flower implements Comparable<Flower>{
        public int start;
        public int end;

        public Flower (int start, int end){
            this.start = start;
            this.end = end;
        }

        public int compareTo(Flower flower){
            if(start < flower.start) return -1;
            else if(start == flower.start){
                if(end < flower.end) return -1;
                else return 1;
            }
            else return 1;
        }
    }

    static PriorityQueue<Flower> pq = new PriorityQueue<Flower>();

    private static int dateToInteger(int month, int day){
        int dateInt = 0;
        for(int i=0;i<month-1;i++){
            dateInt += monthDay[i];
        }
        dateInt += day;
        return dateInt;
    }
    public static void main(String args[]) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(bf.readLine());
        for(int i=0;i<N;i++){
            StringTokenizer st = new StringTokenizer(bf.readLine());
            int startMonth = Integer.parseInt(st.nextToken());
            int startDay = Integer.parseInt(st.nextToken());
            int endMonth = Integer.parseInt(st.nextToken());
            int endDay = Integer.parseInt(st.nextToken());
            int startDateInteger = dateToInteger(startMonth, startDay);
            int endDateInteger = dateToInteger(endMonth, endDay);
            if(startDateInteger >= endDateInteger) continue;
            pq.add(new Flower(startDateInteger, endDateInteger - 1));
        }
        int needMn = dateToInteger(3, 1);
        int needMx = dateToInteger(11, 30);
        int mx = dateToInteger(3, 1);
        int cnt = 0;
        boolean flag = false;
        while(true){
            if(pq.isEmpty() || pq.peek().start > needMn){
                if(!flag) break;
                flag = false;
                cnt++;
                needMn = mx+1;
                if(mx >= needMx) {
                    flag = true;
                    break;
                }
                if(pq.isEmpty()) break;
            }
            Flower flower = pq.poll();
            mx = Math.max(mx,flower.end);
            flag = true;
        }
        System.out.println(flag?cnt:0);
        
    }
}
