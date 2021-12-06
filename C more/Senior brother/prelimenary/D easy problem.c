#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

bool isPrime(int n);
int main(void)
{


	long long test,t=0,number[2000],lower,tem,i,tprime=0,j;


	scanf("%lld",&test);
	for(i=0;i<test;i++)     scanf("%lld", &number[i]);

	for(i=0;i<test;i++){


        lower = number[i];
        while(lower>0){
            while (!isPrime(lower)) {
                int twos=0,digits=0,val,lst;
                val=lower;
                while(val>0){
                    val=val/10;
                    digits++;
                }
                while(lower%10!=5 &&lower%10!=3 && lower%10!=7 && lower>0){
                    if(lower%10==2)twos++;
                    lst=lower;
                    lower=lower/10;
                    t++;
                }
                if(twos==digits && twos>0) t--;
                if(lower%10==7 && lower!=0)lower=(lower/10)*10+5;
                else if(lower%10==5 && lower!=0)lower=(lower/10)*10+3;
                else if(lower%10==3&& lower!=0)lower=(lower/10)*10+2;
                else if(lower==0 && lst>7)lower=7,t--;
                else if(lower==0 && lst>5)lower=5,t--;
                else if(lower==0 && lst>3)lower=3,t--;
                else if(lower==0 && lst>2)lower=2,t--;
                else if(lower==0) t--;
                while(t>0){
                        lower=lower*10+7;
                        t--;
                }

            }
            tem=lower;
            while(tem>0){
                if((tem%10)!=2 && (tem%10)!=3 && (tem%10)!=5 && (tem%10)!=7)break;
                tem=tem/10;
            }
            if(tem==0)break;
            else lower-=1;
        }
        printf("Case %lld: %lld\n",i+1,lower);


	}






return 0;
}
///the algorithm is copied from https:
///www.reddit.com/r/dailyprogrammer/comments/6s70oh/2017087_challenge_326_easy_nearest_prime_numbers/
bool isPrime(int n)
{
	if (n == 1) {
		return false;
	} else if (n < 4) {
		return true;
	} else if (n % 2 == 0) {
		return false;
	} else if (n < 9) {
		return true;
	} else if (n % 3 == 0) {
		return false;
	} else {
		int r = floor(sqrt(n));
		int f = 5;
		while (f <= r) {
			if (n % f == 0) {
				return false;
			} else if (n % (f + 2) == 0) {
				return false;
			}
			f += 6;
		}
		return true;
	}
}

