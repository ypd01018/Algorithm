package BOJ;

import java.io.*;
import java.util.*;

public class Java_3078 {
    
    public static class Member implements Comparable<Member>{
        String name;
        int rank;

        public Member(String name, int rank) {
            this.name = name;
            this.rank = rank;
        }

        @Override
        public int compareTo(Member member) {
            if(this.name.length() < member.name.length()) {
                return -1;
            } else if(this.name.length() > member.name.length()){
                return 1;
            } else {
                if(this.rank < member.rank) return -1;
                else return 1;
            }
        }
    }

    public static class Slice {
        int start;
        int end;

        public Slice(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }

    static int N;
    static int K;
    static Member[] members;
    static ArrayList<Slice> sliceList = new ArrayList<>(); 

    public static int binarySerach(int start, int end, int value) {
        int  l = start, r = end, ret = 0;
        while(l <= r) {
            int mid = (l+r) / 2;
            if(members[mid].rank <= value) {
                ret = mid - start;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ret;
    }

    public static long getNpair(int start, int end) {
        long nPair = 0;
        for(int i=start;i<=end;i++) {
            nPair += binarySerach(i, end, members[i].rank + K);
        }
        return nPair;
    }
    
    public static void main(String[] args) throws IOException {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        members = new Member[N];
        
        for(int i=0;i<N;i++) {
            members[i] = new Member(bf.readLine(), i);
        }

        Arrays.sort(members);
        int startTmp = 0;
        for(int startIdx=0;startIdx<members.length;startIdx++) {
            if(members[startTmp].name.length() != members[startIdx].name.length()){
                sliceList.add(new Slice(startTmp, startIdx - 1));
                startTmp = startIdx;
            }
            
            if(startIdx == members.length-1){
                sliceList.add(new Slice(startTmp, startIdx));
            }
        }
        
        Long answer = 0L;

        for(Slice slice : sliceList) {
            int start = slice.start;
            int end = slice.end;
            
            answer += getNpair(start, end);
        }

        System.out.println(answer);
    }
}