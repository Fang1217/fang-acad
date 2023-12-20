import java.util.*;

class TokenExample {
    public static void main(String args[]) {
        String s = "This%is!the$way#the@world%ends";
        String delimiters = "!%$#@";
        StringTokenizer st = new StringTokenizer(s, delimiters);

        //Call the countToken() function.
        int numberOfTokens = st.countTokens();
        //Print the total number of tokens.
        System.out.println("Number of tokens: " + numberOfTokens);

        for (int i = 0; i < numberOfTokens; i++) //Replace while to for.
            System.out.println(st.nextToken());
    }
}