
public class test {
	public enum Direction {
		START, LEFT, RIGHT, UP, DOWN;
		
		public Direction opposite(Direction dir) {
			switch (dir) {
			case LEFT: return Direction.RIGHT;
			case RIGHT: return Direction.LEFT;
			case UP: return Direction.DOWN;
			case DOWN: return Direction.UP;
			default: return Direction.START; //error
			}
		}

		
	}
/*
	public static void main(String[] args) throws Exception {
		int x = 100;
		int y = 100;
		AMazing amazing = new AMazing();
		Position pos = amazing.new Position(100, 100);
		
		//loop for first 
		for (Direction dir : amazing.dirs) {
			//go there:
			System.out.println(dir.string());
			System.out.flush();
			amazing.marked[x][y] = true;
			
			//go to next or exit:
			switch (amazing.in.readLine()) {
			case "wall": break;
			case "ok": 
				for (Direction d : amazing.dirs) {
					amazing.dfs(d, pos.go(d) ); //dir will be origin 
				};
				break;
			case "solved": System.exit(0);
			case "wrong": System.exit(1);

			//go back:
			System.out.println(dir.opposite().string());
			amazing.in.readLine();
			}
			
		}
		System.out.println("no way out");
	}*/
}
