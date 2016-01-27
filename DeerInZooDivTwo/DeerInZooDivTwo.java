
public class DeerInZooDivTwo {
	private int[] numOfDeer = new int[2];
	
	public int[] getminmax(int N, int K) {
		int x, y;
		
		x = ((2*N-K)-N);
		y = (2*N - K)/2;
		
		numOfDeer[0] = x;
		numOfDeer[1] = y;
		
		for(int i = 0; i<2; i++) {
			if(numOfDeer[i] < 0) {
				numOfDeer[i] = 0;
			}
		}
		return numOfDeer;
	}
}
