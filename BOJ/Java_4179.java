import java.util.*;
import java.io.*;

public class Java_4179 {

    static class Yx {
        public int y;
        public int x;

        public Yx(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
    static int R;
    static int C;    
    static char[][] mat = new char[1000][1000];
    static int[] dy = {-1,0,1,0};
    static int[] dx = {0,1,0,-1};
    static Queue<Yx> fire = new LinkedList<>();
    static Queue<Yx> jihun = new LinkedList<>();

    static void fireMove() {
        int qSize = fire.size();
        for(int i=0;i<qSize;i++) {
            int y = fire.peek().y, x= fire.peek().x;
            fire.poll();
            for(int n=0;n<4;n++) {
                int ny = y+dy[n], nx = x+dx[n];
                if(ny < 0 || nx < 0 || ny >= R || nx >= C || mat[ny][nx] == 'F' || mat[ny][nx] == '#') continue;
                mat[ny][nx] = 'F';
                fire.add(new Yx(ny, nx));
            }
        }
    }

    static boolean jihunMove() {
        int qSize = jihun.size();
        for(int i=0;i<qSize;i++) {
            int y = jihun.peek().y, x = jihun.peek().x;
            jihun.poll();
            for(int n=0;n<4;n++) {
                int ny = y+dy[n], nx = x+dx[n];
                if(ny < 0 || nx < 0 || ny >=R || nx >=C) return true;
                if(mat[ny][nx] != '.') continue;
                mat[ny][nx] = 'J';
                jihun.add(new Yx(ny, nx));
            }
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        for(int i=0;i<R;i++) {
            String input = bf.readLine();
            for(int j=0;j<input.length();j++) {
                mat[i][j] = input.charAt(j);
                if(mat[i][j] == 'J') jihun.add(new Yx(i,j));
                else if(mat[i][j] == 'F') fire.add(new Yx(i,j));
            }
        }
        int answer = 0;
        while(true) {
            answer++;
            fireMove();

            if(jihunMove()) {
                System.out.println(answer);
                break;
            }
            if(jihun.isEmpty()) {
                System.out.println("IMPOSSIBLE");
                break;
            }
        }
    }
}
