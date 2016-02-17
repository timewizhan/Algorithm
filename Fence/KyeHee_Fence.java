import java.util.Random;
import java.util.*;

public class Fence {
	private final static int TEST_BED_COUNT_LIMIT = 1;
	private final static int BOARD_COUNT_LIMIT = 10;
	private final static int BOARD_HEIGHT_LIMIT = 20;
	private final static int BOARD_COUNT_UNDER_BOUND = 1;

	public static void main(String[] args) {
		Fence fence = new Fence();
		int _boardCount = fence.getBoardCount();
		int _boardHeight = fence.getBoardHeight();
		int _boardUnderBound = fence.getUnderBound();

		ArrayList<Integer> boardHeight = fence.getBoardHeight(_boardCount, _boardHeight, _boardUnderBound);
		ArrayList<Integer> result = new ArrayList<Integer>();
		

		int left = 0;
		int area = 0;
		int w = 0;

		System.out.println("Input : " + boardHeight);

		for (int i = 0; i < _boardCount; i++) {
			if (i == 0) {
				left = boardHeight.get(i);
				w = 1;
			} else {
				if (left > boardHeight.get(i)) {
					area = left * w;
					result.add(area);

					left = boardHeight.get(i);
					w = 1;
				} else {
					w++;
				}
				if (i == _boardCount - 1) {
					area = left * w;
					result.add(area);
				}
			}
			//System.out.println(left + " " + w);
		}

		for (int i = _boardCount - 1; i >= 0; i--) {
			if (i == _boardCount - 1) {
				left = boardHeight.get(i);
				w = 1;
			} else {
				if (left > boardHeight.get(i)) {
					area = left * w;
					result.add(area);

					left = boardHeight.get(i);
					w = 1;
				} else {
					w++;
				}
				if (i == 0) {
					area = left * w;
					result.add(area);
				}
			}
			//System.out.println(left + " " + w);
		}

		System.out.println("Area : " + result);
		
		Collections.sort(boardHeight);
		Collections.reverse(boardHeight);
		Collections.sort(result);
		Collections.reverse(result);
		
		System.out.println("Sorted Input : " + boardHeight);
		System.out.println("Sorted Area : " + result);
		
		if(result.get(0) > boardHeight.get(0)) {
			System.out.println(result.get(0));
		} else {
			System.out.println(boardHeight.get(0));
		}
	}

	/*
	public void divide(int left, int right, ArrayList<Integer> boardHeight) {
		int mid;

		if (left < right) {
			mid = (left + right) / 2;

			divide(left, mid, boardHeight);
			divide(mid + 1, right, boardHeight);
			conquer(left, mid, right, boardHeight);
		}
	}

	public ArrayList<Integer> conquer(int left, int mid, int right, ArrayList<Integer> boardHeight) {
		ArrayList<Integer> tmp = new ArrayList<Integer>();

		while (left <= mid && mid + 1 <= right) {

		}
		return tmp;
	}
	*/
	public int generateRandom(int randomRange, int initialVal) {
		Random random = new Random();
		int randomNum = random.nextInt(randomRange) + initialVal;

		return randomNum;
	}

	public ArrayList<Integer> getBoardHeight(int boardCount, int boardHeight, int boardUnderBound) {
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