import java.util.*;

public class DynamicProgramming {
	public static boolean handleAsterisk(String subWildCard, String subFileName) {
		boolean result = true;

		for (int i = 0; i < subFileName.length(); i++) {
			if (subWildCard.substring(i, i + 1).equals(subFileName.substring(i, i + 1))
					|| subWildCard.substring(i, i + 1).equals("?")) {
				if (subWildCard.length() < subFileName.length() 
						&& i == (subWildCard.length() - 1)
						&& !subWildCard.substring(i, i + 1).equals("*")) {
						result =  handleAsterisk(subWildCard, subFileName.substring(1));
						break;
				}
				
				continue;
			} else if (subWildCard.substring(i, i + 1).equals("*")) {
				if (i == (subWildCard.length() - 1)) {
					break;
				} else if (handleAsterisk(subWildCard.substring(i + 1), subFileName.substring(i))) {
					break;
				} else {
					result = false;
					break;
				}
			} else if (subWildCard.length() < subFileName.length()) {
					result =  handleAsterisk(subWildCard, subFileName.substring(1));
					break;
				
			} else {
				result = false;
				break;
			}
		}
		return result;
	}
	
	public String cmpWildCard(String wildCard, String fileName) {
		String result = fileName;

		for (int i = 0; i < fileName.length(); i++) {
			if (wildCard.substring(i, i + 1).equals(fileName.substring(i, i + 1))
					|| wildCard.substring(i, i + 1).equals("?")) {
				continue;
			} else if (wildCard.substring(i, i + 1).equals("*")) {
				result = (handleAsterisk(wildCard.substring(i + 1), fileName.substring(i))) ? fileName : null;
				break;
			} else {
				result = null;
			}
		}
		return result;
	}

}
