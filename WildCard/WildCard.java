import java.util.*;

public class WildCard {
	public String[] ex;
	public String[] problem;
	public int[] saveArr;
	//HashMap<Integer, String> map;
	ArrayList<Integer> list;
	ArrayList<String> character;

	public static void main(String[] args) {
		WildCard wildcard = new WildCard();
		//wildcard.map = new HashMap<Integer, String>();
		wildcard.list = new ArrayList<Integer>();
		wildcard.character = new ArrayList<String>();

		wildcard.split(wildcard.ex, wildcard.list, wildcard.character);
		wildcard.compare(wildcard.ex, wildcard.problem, wildcard.list, wildcard.character, wildcard.saveArr);
		
		for (int i = 0; i < wildcard.saveArr.length; i++) {
			System.out.println(wildcard.saveArr[i]);
		}
	}

	public WildCard() {
		ex = new String[1];
		problem = new String[3];
		saveArr = new int[3];

		ex[0] = "*p*";
		// ex[1] = "*p*";

		problem[0] = "hellp";
		problem[1] = "hepo";
		problem[2] = "nono";
	}

	public void split(String[] ex, ArrayList<Integer> list, ArrayList<String> character) {
		for (int i = 0; i < ex.length; i++) {
			for (int j = 0; j < ex[i].length(); j++) {
				if (ex[i].charAt(j) == '*') {
					list.add(j);
					//map.put(j, "*");
				} else if (ex[i].charAt(j) == '?') {
					// not yet
					//map.put(j, "?");
				}
			}

			StringTokenizer st = new StringTokenizer(ex[i], "*");

			while (st.hasMoreTokens()) {
				character.add(st.nextToken());
			}
		}

		System.out.println(character);
	}

	public void compare(String[] ex, String[] problem, ArrayList<Integer> list, ArrayList<String> character,
			int[] saveArr) {
		for (int i = 0; i < problem.length; i++) {
			int result = 0;

			for (int k = 0; k < character.size(); k++) {
				int sentenceLoc = 0;
				String sen = character.get(k);

				for (int j = sentenceLoc; j < problem[i].length(); j++) {
					if (j + sen.length() <= problem[i].length()) {
						 //System.out.println("j = "+j);
						 //System.out.println(problem[i].substring(j, j + sen.length()));
						if (sen.equals(problem[i].substring(j, j + sen.length()))) {
							j = j + sen.length();
							result++;
							break;
						} else {

						}
					}
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
