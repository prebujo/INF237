import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class NestedDolls {

	public static void main(String[] args) {
		//BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		Scanner in = new Scanner(System.in);
		int T = in.nextInt(); //# of testcases
		for (int t = 0; t < T; t++) {
			int m = in.nextInt(); //#of dolls
			Doll[] wDolls = new Doll[m]; //sorted by width

			//sorting lists:
			Arrays.sort(wDolls, new Comparator<Doll>() {
				@Override
				public int compare(Doll o1, Doll o2) { return -o1.w + o2.w; }
				});

			ArrayList<Doll> stacks = new ArrayList<Doll>(); //heap?
			int progressionIndex = 0;
			
			for (int i = 0; i < m; i++) { wDolls[i].id = i; }

			int count = 0; //number of stacks of dolls
			Doll prev = wDolls[0];
			for (int i = 0; i < m; i++) {
				Doll doll = wDolls[i];
				
				if (doll.w == prev.w) { 
					count++; 
					prev = doll;
					continue; //no need to remember this stack, cannot continue it
				}
				if (doll.h <= prev.h) { //need new stack or to continue an existing
					for (int k = 0; k < stacks.size(); k++) { //binary search?
						if (stacks.get(k).w < doll.w && stacks.get(k).h < doll.h) {
							
							
							continue;
						}
					}
					count++;
//					stacks.add(i); //remember where we left off, so we might continue this one later.
				}
			}
		}
	}
	
	private class BST {
		
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
