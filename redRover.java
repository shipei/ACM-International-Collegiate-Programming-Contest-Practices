package redRover;
import java.util.*;

public class redRover {
	public static int countTimes(String str, String macro) {
		int result = 0;
		while(str.indexOf(macro) != -1) {
			int index = str.indexOf(macro);
			result++;
			str = str.substring(index+macro.length());
		}
		return result;
	}
	
	public static int calc(String str, String macro) {
		int times = countTimes(str, macro);
		return times + macro.length() + (str.length() - times * macro.length());
	}
	
	public static int exec(String message) {
		String macro;
		int min = Integer.MAX_VALUE;	
		for(int i = 0; i<message.length(); ++i){
			for(int j = i+2; j <=message.length(); ++j) {
				macro = message.substring(i, j);
				if(countTimes(message, macro) > 1) {
					if(calc(message, macro) < min)
						min = calc(message, macro);
				}
			}
		}
		if(min == Integer.MAX_VALUE) 
			return message.length();
		return min;
	}

	public static void main(String[] args) {
	    Scanner scan = new Scanner(System.in);
	    String message = scan.nextLine();
	    System.out.println(exec(message));
	}
}
