import java.util.Scanner;
public class agentJ1331{
	
	
	public static void main(String[] args){
		int i,j,k,n;
		final double PI=2*Math.acos(0.0);
		double a,b,c,ab,bc,ca,A,B,C,s,area;
		double[] left=new double[2000];
		Scanner input=new Scanner(System.in);
		n=input.nextInt();
		for(i=0;i<n;i++){
			a=input.nextDouble();
			b=input.nextDouble();
			c=input.nextDouble();
			ab=a+b;bc=b+c;ca=c+a;
			s=(ab+bc+ca)/2;
			area=Math.sqrt(s*(s-ab)*(s-bc)*(s-ca));
			A=Math.acos(((ca*ca+ab*ab)-(bc*bc))/(2*ab*ca));
			B=Math.acos((bc*bc+ab*ab-ca*ca)/(2*bc*ab));
			C=Math.acos((bc*bc+ca*ca-ab*ab)/(2*bc*ca));
			
			//areaA=A*PI*a*a/360;
			left[i]=area-(A*a*a+B*b*b+C*c*c)*0.5;
			
		}
		for(i=0;i<n;i++)System.out.printf("Case %d: %.8lf",i+1,left[i]);
	}
}