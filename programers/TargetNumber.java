package programers;

public class TargetNumber {
  
    public static void main(String[] args) {
        int[] numbers = {1, 1, 1, 1, 1};
        int target = 3;
        Solution solution = new Solution();
        System.out.println(solution.solution(numbers, target));
    }
}

class Solution {

    private int answer = 0;
    private int target;
    private int[] numbers;

    public void go(int idx,int sum) {
        if(idx >= numbers.length) {
            if(sum == target) answer++;
            return;
        }
        go(idx+1, sum + numbers[idx]);
        go(idx+1, sum - numbers[idx]);
    }

    public int solution(int[] numbers, int target) {
        this.target = target;
        this.numbers = numbers;
        go(0,0);
        return answer;
    }
}