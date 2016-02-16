import java.util.Random;
import java.util.ArrayList;

public class Fence {
	private final static int TEST_BED_COUNT_LIMIT = 1;
	private final static int BOARD_COUNT_LIMIT = 5;
	private final static int BOARD_HEIGHT_LIMIT = 20;
	private final static int BOARD_COUNT_UNDER_BOUND = 1;

	public static void main(String[] args) {		
		Fence fence = new Fence();
		int _boardCount = fence.getBoardCount();
		int _boardHeight = fence.getBoardHeight();
		int _boardUnderBount = fence.getUnderBound();
		
		int testBedCount = fence.getTestBedCount();
		int boardCount = fence.generateRandom(_boardCount, _boardUnderBount);
		ArrayList<?> boardHeight = fence.getBoardHeight(_boardCount, _boardHeight, _boardUnderBount);
		
		//System.out.println(boardHeight);
		
		ArrayList<Integer> result;
		
		
	}

	public int generateRandom(int randomRange, int initialVal) {
		Random random = new Random();
		int randomNum = random.nextInt(randomRange) + initialVal;

		return randomNum;
	}

	public ArrayList<?> getBoardHeight(int boardCount, int boardHeight, int boardUnderBound) {
		ArrayList<Integer> barHeights = new ArrayList<>();

		for (int i = 0; i < boardCount; i++) {
			barHeights.add(generateRandom(boardHeight, boardUnderBound));
		}

		return barHeights;
	}

	public int getTestBedCount() {
		return TEST_BED_COUNT_LIMIT;
	}

	public int getBoardCount() {
		return BOARD_COUNT_LIMIT;
	}
	
	public int getBoardHeight() {
		return BOARD_HEIGHT_LIMIT;
	}
	
	public int getUnderBound() {
		return BOARD_COUNT_UNDER_BOUND;
	}
}