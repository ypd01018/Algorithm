package programers;

import java.util.*;

public class Java_jewel {
    static int mn = (int) 1e9, N, gemCnt, answer[] = new int[2];

    public static int[] solution(String[] gems) {
        N = gems.length;
        HashSet<String> gemSet = new HashSet<String>();
        for (int i = 0; i < N; i++) {
            String gem_name = gems[i];
            if (!gemSet.contains(gem_name))
                gemSet.add(gem_name);
        }
        gemCnt = gemSet.size();
        gemSet.clear();
        int l = 0, r = 0, cnt = 0;
        HashMap<String, Integer> gemCheck = new HashMap<String, Integer>();
        gemCheck.put(gems[0], 1);
        cnt++;
        while (l <= r && r < N) {
            System.out.println(l + " " + r);
            System.out.println("gem cnt:"+cnt);
            if (cnt == gemCnt) {
                if (mn > r - l + 1) {
                    mn = r - l + 1;
                    answer[0] = l;
                    answer[1] = r;
                    
                }
                int targetGemCnt = gemCheck.containsKey(gems[l]) ? gemCheck.get(gems[l]) - 1 : 0;
                gemCheck.put(gems[l], targetGemCnt);
                if (gemCheck.get(gems[l]) == 0)
                    cnt--;
                l++;
            } else {
                r++;
                if (r >= N)
                    continue;
                // System.out.println(gemCheck.get(gems[r]));
                int targetGemCnt = gemCheck.containsKey(gems[r]) ? gemCheck.get(gems[l]) + 1 : 1;
                // System.out.println(targetGemCnt);
                gemCheck.put(gems[r], targetGemCnt);
                if (targetGemCnt == 1)
                    cnt++;
                gemSet.add(gems[r]);
            }
        }
        return answer;
    }

    public static void main(String[] args) {
        String[] gems = { "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };
        int answer[] = solution(gems);
        System.out.println((answer[0]+1)+" "+(answer[1]+1));
    }
}
