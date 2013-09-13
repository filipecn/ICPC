import java.io.*;
import java.util.*;
import java.math.*;
class Main
{
    static int primes[] = new int[1010];
    static int pc = 0;
    
    static boolean prime(int num)
    {
        int lim = (int) Math.sqrt(num);
        for (int i = 2; i <= lim; ++i)
            if (num%i == 0) return false;
        return true;
    }
    
    static boolean good(int num)
    {
        for (int i = 0; i < pc; ++i)
            if (num % primes[i] == 0) return false;
        return true;
    }
    
    public static void main(String args[])
    {
        BigInteger num = BigInteger.valueOf(1);
        for (int i = 2; i < 8001; ++i)
        {
            if (prime(i) == false) continue;
            primes[pc++] = i;
            num = num.multiply(BigInteger.valueOf(i));
        }
        //System.out.println(num.toString().length());
        //String str = String.format("%,d", num);
        int x = 0;
        for (int i = 8001;;++i)
        {
            if (good(i) == false || good(i+2) == false) continue;
            //System.out.println(i);
            x = i;
            break;
        }
        
        Scanner sc = new Scanner(System.in);
        String res = num.toString();
        // problema \/
        while (true)
        {
            int n = sc.nextInt();
            sc.nextInt();
            if (n == 0) break;
            
            System.out.print(res);
            int left = n-res.length()-4;
            String aux = "";
            while (left-- > 0) aux = aux.concat("0");
            System.out.print(aux);
            System.out.println(x);
        }
        
    }
}

