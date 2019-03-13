import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
	    Scanner in = new Scanner(System.in);
	    int t = in.nextInt();
	    while(t > 0)
	    {
	        String s = in.next();
	        char d = in.next().charAt(0);
	        char ss[] = new char[s.length()];
	        int c = 0;
	        int i = 0;
	        for(int j = 0; j < s.length(); j++)
	        {
	            if(s.charAt(j) > d) c++;
	            else
	            {
	                ss[i] = s.charAt(j);
	                i++;
	            }
	        }
	        s = "";
	        for(int j = i-1; j >= 0; j--)
	        {
	            s = s + ss[j];
	        }
	        String ans = "";
	        i = s.length() - 1;
	        while(i >= 0)
	        {
	            int x = i;
	            char temp = s.charAt(i);
	            for(int j = i; j >= 0; j--)
	            {
	                if(s.charAt(j) < temp)
	                {
	                    temp = s.charAt(j);
	                    x = j;
	                }
	            }
	            while(x < i)
	            {
	                c++;
	                i--;
	            }
	            ans = ans + s.charAt(i);
	            i--;
	        }
	        while(c > 0)
	        {
	            ans = ans + d;
	            c--;
	        }
	        System.out.println(ans);
	        t--;
	    }
	}
}
