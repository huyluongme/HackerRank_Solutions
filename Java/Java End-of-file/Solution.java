import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner scan = new Scanner(System.in);
        String str = new String();
        int n = 1;
        do{
            str = scan.nextLine();
            System.out.println((n++) + " " + str);
        }while (scan.hasNext());
        scan.close();
    }
}