import java.util.*;

public class WildCard {
	public String[] ex;
	public String[] problem;
	public int[] saveArr;
	ArrayList<Integer> sepTokenQuestion; // save the location of *
	ArrayList<String> sepTokenStar; // save the seperated token

	public static void main(String[] args) {
		WildCard wildcard = new WildCard();
		// wildcard.map = new HashMap<Integer, String>();
		wildcard.sepTokenQuestion = new ArrayList<Integer>();
		wildcard.sepTokenStar = new ArrayList<String>();

		wildcard.split(wildcard.ex, wildcard.sepTokenQuestion, wildcard.sepTokenStar);
		wildcard.compare(wildcard.ex, wildcard.problem, wildcard.sepTokenQuestion, wildcard.sepTokenStar,
				wildcard.saveArr);

		// System.out.println(wildcard.sepTokenQuestion);

		// System.out.println(wildcard.ex[0]);
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

		ex[0] = "h*p?p";
		// ex[1] = "*p*";

		problem[0] = "h222epop";
		problem[1] = "hepop";
		problem[2] = "nono";
	}

	public void split(String[] ex, ArrayList<Integer> sepTokenQuestion, ArrayList<String> sepTokenStar) {
		for (int i = 0; i < ex.length; i++) {
			StringTokenizer st = new StringTokenizer(ex[i], "*");
			while (st.hasMoreTokens()) {
				sepTokenStar.add(st.nextToken());
			}

			for (int j = 0; j < ex[i].length(); j++) {
				if (ex[i].charAt(j) == '?') {
					sepTokenQuestion.add(j);
				}
			}
		}
		System.out.println(sepTokenStar);
		// System.out.println(sepTokenQuestion);
	}

	public void compare(String[] ex, String[] problem, ArrayList<Integer> sepTokenQuestion,
			ArrayList<String> sepTokenStar, int[] saveArr) {
		for (int i = 0; i < problem.length; i++) {
			int result = 0;

			for (int k = 0; k < sepTokenStar.size(); k++) {
				int sentenceLoc = 0;
				String sen = sepTokenStar.get(k);

				for (int j = sentenceLoc; j < problem[i].length(); j++) {
					if (j + sen.length() <= problem[i].length()) {
						// System.out.println(problem[i].substring(j, j +
						// sen.length()));
						if (sen.equals(problem[i].substring(j, j + sen.length())) || (sen.contains("?")
								&& problem[i].substring(j, j + sen.length()).length() == sen.length())) {
							j = j + sen.length();
							result++;
							break;
						} else {

						}
					}
				}
				// System.out.println(result);
			}

			if (result == sepTokenStar.size()) {
				saveArr[i] = 1;
			} else {
				saveArr[i] = 0;
			}
		}
	}
}