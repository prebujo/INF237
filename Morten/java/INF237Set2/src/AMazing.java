import java.io.BufferedReader;
import java.io.InputStreamReader;

public class AMazing {

	private boolean[][] marked = new boolean[210][210];
	private Direction[] allDir = Direction.values();
	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String[] args) throws Exception {
		AMazing amazing = new AMazing();
		amazing.run();
	}
	
	public void run() throws Exception {
		Position pos = new Position(105, 105);
		marked[pos.x][pos.y] = true;
		//loop for first 
		for (Direction dir : allDir) {
			dfs(dir, pos.go(dir));
		}
		
		//if dfs doesn't find exit:
		System.out.println("no way out");
	}
	

	/**
	 * 
	 * @param dir 	direction we want to go
	 * @param pos	position we end up on
	 * @throws Exception
	 */
	private void dfs(Direction dir, Position pos) throws Exception {
		if (marked[pos.x][pos.y]) {
			return;	//return before moving
		}
		
		//make the move:
		System.out.println(dir.string()); 
		System.out.flush();

		//go to next or exit:
		switch (in.readLine()) {
		case "wall": 
			return;
		case "ok":
			//call recursive only here
			marked[pos.x][pos.y] = true;
			for (Direction d : allDir) {
				dfs(d, pos.go(d));
			};
			//go back:
			System.out.println(dir.opposite().string());
			System.out.flush();
			in.readLine();
			return;
		case "solved": System.exit(0);
		case "wrong": System.exit(0);
		}
	}
	
	public enum Direction {
		LEFT, UP, RIGHT, DOWN;
		
		public Direction opposite() {
			switch (this) {
			case LEFT: return Direction.RIGHT;
			case RIGHT: return Direction.LEFT;
			case UP: return Direction.DOWN;
			case DOWN: return Direction.UP;
			default: return Direction.UP; //Acutally error!
			}
		}
		
		public String string() {
			return this.toString().toLowerCase();
		}
	}
	public class Position {
		public final int x;
		public final int y;
		
		public Position(int x, int y) {
			this.x = x; this.y = y;
		}
		public Position go(Direction dir) {
			switch (dir) {
			case LEFT: return new Position(x - 1, y);
			case RIGHT: return new Position(x + 1, y);
			case DOWN: return new Position(x, y + 1);
			case UP: return new Position(x, y - 1);
			default: return new Position(0,0); //error
			}
		}
		@Override
		public String toString() {
			return "(" + x + ", " + y + ")";
		}

	}
}
