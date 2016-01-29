import java.util.*;

public class AirlinerSeats {
	public String[] mostAisleSeats(int width, int seats) {
		String[] arr = new String[width];
		String[] arrResult01 = new String[1];
		String[] arrResult02 = new String[2];
		arrResult01[0] = "";
		arrResult02[0] = "";
		arrResult02[1] = "";

		int numOfDots = width - seats;
		int numOfSeats = seats;
		int dotFlag = 0, SFlag = 0, revFlag = 0;

		if(seats == 0) {
			for(int i = (width - 1); i>-1; i--) {
				arr[i] = ".";
			}
			return arr;
		} else {
			arr[width-1] = "S";
			SFlag = 1;
			numOfSeats -= 1;

			for(int i  = (width -2); i>-1; i--) {
				if((numOfSeats>0) && (((SFlag==0) && (numOfSeats>=1)) 
								|| (SFlag==1 && i<(width-2)) 
								|| numOfDots<1)) {
					arr[i] = "S";
					SFlag += 1;
					numOfSeats -= 1;
				} else {
					arr[i] = ".";
					SFlag = 0;
					numOfDots -= 1;
				}
			}
		}

		if(SFlag>2) {
			List<String> list = Arrays.asList(arr);
			Collections.reverse(list);
			arr = list.toArray(new String[list.size()]);

			if(width<51) {
				for(int i=0; i<width; i++) {
					arrResult01[0] += arr[i]; 
				}
				return arrResult01;
			} else {
				if(width<100) {
					for(int i=0; i<50; i++) {
						arrResult02[0] += arr[i]; 
					}
					for(int j=50; j<width; j++) {
						arrResult02[1] += arr[j];
					}
					return arrResult02;
				} else {
					for(int i=0; i<50; i++) {
						arrResult02[0] += arr[i];
						arrResult02[1] += arr[(width-1)-49+i]; 
					}
					return arrResult02;
				}

			}

		} else {
			if(width<51) {
				for(int i=0; i<width; i++) {
					arrResult01[0] += arr[i]; 
				}
				return arrResult01;
			} else {
				if(width<100) {
					for(int i=0; i<50; i++) {
						arrResult02[0] += arr[i]; 
					}
					for(int j=50; j<width; j++) {
						arrResult02[1] += arr[j];
					}
					return arrResult02;
				} else {
					for(int i=0; i<50; i++) {
						arrResult02[0] += arr[i];
						arrResult02[1] += arr[(width-1)-49+i]; 
					}
					return arrResult02;
				}

			}
		}
	} 

}

/*
public class AirlinerSeats {

	public int checkAisleSeats(int numOfSeats, int numOfDots) {
		if(Math.ceil(numOfSeats/2) < numOfDots) {
			return 1;
		} else {
			return 0;
		}
	}

	public String allocateSeats(int posNum, int numOfDots) {
		double seqNum;
		seqNum = (posNum + 2) / 3;
		int coveredPos = numOfDots * 2 + numOfDots - 1;

		if(posNum < coveredPos ) {
			return "S"; 
		} else {
			if(seqNum == Math.ceil(seqNum)) {
				return "S";
			} else {
				return ".";
			}
		}
	}

	public String[] mostAisleSeats(int width, int seats) {
		String[] arrResult01 = new String[1];
		String[] arrResult02 = new String[2];
		arrResult01[0] = "";
		arrResult02[0] = "";
		arrResult02[1] = "";

		int numOfDots = width - seats;
		int numOfSeats = seats;
		int aisleSeats = checkAisleSeats(numOfSeats, numOfDots);

		String returnCase = "";
		if(width < 51) {
			returnCase = "less";
		} else {
			returnCase = "more";
		}

		if(seats == 0) {
			switch(returnCase) {
				case "less" :
					for(int i = 0; i < width; i++) {
						arrResult01[0] += ".";
					}
					return arrResult01;
					break;
				case "more" :
					for(int i = 0; i<50; i++) {
						arrResult02[0] += ".";
						if(i < (width-51)) {
							arrResult02[0] += ".";	
						}	
					}
					return arrResult02;
					break;
			}
			// The number of seats > 0
		} else {
			switch(returnCase) {
				case "less" :
					if(aisleSeats == 1) {
						for(int i = 0; i < width; i++) {
							arrResult01[0] += allocateSeats(i, numOfDots); 
						}
					} else {
						for(int i = (width - 1); i > -1; i--) {
							arrResult01[0] += allocateSeats(i, numOfDots);
						}
					}
			}
		}
	}
}
*/

/*
	
 */


