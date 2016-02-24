import java.util.*;

public class WildCard {
	public String[] ex;
	public String[] problem;
	public int[] saveArr;
	ArrayList<String> character;

	public static void main(String[] args) {
		WildCard wildcard = new WildCard();
		// wildcard.map = new HashMap<Integer, String>();
		wildcard.character = new ArrayList<String>();

		wildcard.split(wildcard.ex, wildcard.character);
		wildcard.compare(wildcard.ex, wildcard.problem, wildcard.character, wildcard.saveArr);

		for (int i = 0; i < wildcard.saveArr.length; i++) {
			if (wildcard.saveArr[i] == 1) {
				System.out.println(wildcard.problem[i]);
			}
		}
	}

	public WildCard() {
		ex = new String[1];
		problem = new String[3];
		saveArr = new int[3];

		ex[0] = "h*p*p";
		// ex[1] = "*p*";

		problem[0] = "hlpap";
		problem[1] = "helpop";
		problem[2] = "aaaa";
	}

	public void split(String[] ex, ArrayList<String> character) {
		for (int i = 0; i < ex.length; i++) {
			StringTokenizer st = new StringTokenizer(ex[i], "*");

			while (st.hasMoreTokens()) {
				character.add(st.nextToken());
			}
		}

		System.out.println(character);
	}

	public void compare(String[] ex, String[] problem, ArrayList<String> character, int[] saveArr) {
		for (int i = 0; i < problem.length; i++) {
			int result = 0;

			int j;
			int init = 0;
			for (int k = 0; k < character.size(); k++) {
				String sen = character.get(k);

				for (j = init; j < problem[i].length();) {
					System.out.println("k : " + k + "/ j : " + j);
					if (j + sen.length() <= problem[i].length()) {
						if (sen.equals(problem[i].substring(j, j + sen.length()))) {
							init = j + sen.length();
							result++;
							break;
						}
					}
					j++;
				}
			}

			if (result == character.size()) {
				saveArr[i] = 1;

			} else {
				saveArr[i] = 0;
			}
		}
	}
}