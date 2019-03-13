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
	        int n = in.nextInt();
	        long a;
	        int neg = 0,pos = 0;
	        for(int i = 0; i < n; i++)
	        {
	            a = in.nextLong();
	            if(a < 0) neg++;
	            else pos++;
	        }
	        if(neg == n) System.out.println(neg + " " + neg);
	        else if(pos == n) System.out.println(pos + " " + pos);
	        else System.out.println(pos + " " + neg);
	        t-=1;
	    }
	}
}
