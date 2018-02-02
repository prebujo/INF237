import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class NestedDolls {

	public static void main(String[] args) {
		//BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		Scanner in = new Scanner(System.in);
		int T = in.nextInt(); //# of testcases
		for (int t = 0; t < T; t++) {
			int m = in.nextInt(); //#of dolls
			Doll[] wDolls = new Doll[m]; //sorted by width
			Doll[] hDolls = new Doll[m]; //sorted by height
			
			//sorting lists:
			Arrays.sort(wDolls, new Comparator<Doll>() {
				@Override
				public int compare(Doll o1, Doll o2) { return o1.w - o2.w; }
				});
			Arrays.sort(hDolls, new Comparator<Doll>() {

				@Override
				public int compare(Doll o1, Doll o2) { return o1.h - o2.h; }
			});
			
			ArrayList<Integer> progress = new ArrayList<Integer>();
			
			for (int i = 0; i < m; i++) { wDolls[i].id = i; }
			for (int j = 0; j < m; j++) { hDolls[j].ref = j; }
			
			int count = 0; //number of stacks of dolls
			int i = 0, j = 0; //i is position in wDolls, j is corresponding pos in hDolls
			Doll prev = wDolls[0];
			while(true) {
				Doll doll = wDolls[i++];
				
				if (doll.w <= prev.w) { 
					count++; 
					continue; 
				}
				if (doll.h <= prev.h) {
					count++;
					for (int l : progress) {
						if (wDolls[l].w > doll.w && wDolls[l].h > doll.h) {
							continue; //keep going, no need to 
						}
					}
					progress.add(i);
					
				}
				
				
			}
			
		}
		
		
		
	}
	
	public class Pair {
		int i, j;
		public Pair(int i, int j) {
			this.i = i;
			this.j = j;
		}
	}

	public class Doll {
		int w, h;
		int id, ref;
		public Doll(int w, int h, int id, int ref) {
			this.w = w;
			this.h = h;
			this.id = id;
			this.ref = ref;
		}
		
	}
	
}
