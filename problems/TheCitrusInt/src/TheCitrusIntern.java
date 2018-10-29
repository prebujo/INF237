import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;

public class TheCitrusIntern {

    //using public tables for In, OutDown and OutUp
    public static long[] In = new long[100000];
    public static long[] OutU = new long[100000];
    public static long[] OutD = new long[100000];

    public static void main(String args[]) throws Exception {
        BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(buff.readLine());
        List<Integer> ch[] = new LinkedList[N];
        //initialising child lists
        for (int i = 0; i<N; i++){
            ch[i] = new LinkedList<>();
        }

        //marked table to find root
        boolean[] marked = new boolean[N];
        //weigth table
        long[] w = new long[N];

        //taking input of each person in organisation
        for (int i = 0; i<N;i++){
            String[] inp = buff.readLine().split(" ");
            w[i] = Integer.parseInt(inp[0]);
            int U = Integer.parseInt(inp[1]);
            for (int j = 0; j<U;j++){
                int input = Integer.parseInt(inp[j+2]);
                ch[i].add(input);
                marked[input] = true;
            }
        }

        //finding root
        int root = 0;
        for (int i = 0; i<N; i++){
            if (!marked[i])
                root = i;
        }

        //running recursive Bribe function from root
        dfsBribe(root, ch, w);
        //printing minimum of root being bribed and not
        System.out.println(Math.min(In[root],OutD[root]));

    }

    private static void dfsBribe(int n, List<Integer>[] ch, long[] w) { //O(N) running time
        //base case: if on a leaf, calculate
        if (ch[n].size() == 0){
            In[n] = w[n];
            OutD[n] = Long.MAX_VALUE;
            OutU[n] = 0;
        }
        //recurrance case: non.leaf, do dfs for all subordinates then calculate In, OutUp & OutDown.
        else{
            for (int c:ch[n])
                dfsBribe(c, ch, w); //running once for each child thereby O(N)
            In[n] = w[n];
            for (int c:ch[n]){ //O(N) running time
                In[n] += OutU[c];
                OutU[n] += Math.min(In[c], OutD[c]);
                OutD[n] += Math.min(In[c], OutD[c]);
            }
            OutD[n] += delta(n, ch); //add delta for no in Children
        }

    }

    private static long delta(int n, List<Integer>[] ch){ //O(N) running time
        long t = Long.MAX_VALUE;
        //return cost of the child with the smallest difference between In and Out.
        for (int c:ch[n]){
            long diff = In[c] - OutD[c];
            long t1 = Math.max(diff, 0);
            t = Math.min(t1,t);
        }
        return t;
    }
}