import java.util.Scanner;
class fib{
    public static void main(String[] args){
	Scanner in = new Scanner(System.in);
	int num = in.nextInt();
	double Phi = (1+Math.sqrt(5))/2;
	double phi = (1-Math.sqrt(5))/2;
	double fib_n = Math.pow(Phi, num) - Math.pow(phi,num);
	fib_n = fib_n/Math.sqrt(5);
	System.out.print(fib_n + "\n");
    }
}