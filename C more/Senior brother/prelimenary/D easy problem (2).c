
            if(lower%10==7 && lower!=0)lower=(lower/10)*10+5;
            else if(lower%10==5 && lower!=0)lower=(lower/10)*10+3;
            else if(lower%10==3&& lower!=0)lower=(lower/10)*10+2;
            else if(lower==0 && lst>7)lower=7,t--;
            else if(lower==0 && lst>5)lower=5,t--;
            else if(lower==0 && lst>3)lower=3,t--;
            else if(lower==0 && lst>2)lower=2,t--;
            else if(lower==0) t--;
