#include <iostream>

using namespace std;

int romanToInt(string s){
        
        int ans = 0;
        int i = s.length()-1;
        int unit = 0, ten = 0, hundred = 0, thou = 0;;
        //Calculate unit's place
        if(i>=0 && s[i]=='X'){
        	if(i>=0 && s[i-1]=='I'){
        		unit = 9;
	        	i-=2;
        	} else {
        		unit = 0;
        	}
        } else if(s[i]=='I'){
        	while(i>=0 && s[i]=='I'){
        		unit += 1;
        		i--;
        	}
        	if(i>=0 && s[i]=='V'){
        		unit += 5;
        		i--;
        	}
        } else if(s[i]=='V'){
        	i--;
        	if(i>=0 && s[i]=='I'){
        		unit = 4;
        		i--;
        	} else {
        		unit = 5;
        	}
        }
        //Calculate ten's place
        if(i>=0 && s[i]=='C'){
        	if(i>=0 && s[i-1]=='X'){
        		ten = 9;
	        	i-=2;
        	} else {
        		ten = 0;
        	}
        } else if(s[i]=='X'){
        	while(i>=0 && s[i]=='X'){
        		ten++;
        		i--;
        	}
        	if(i>=0 && s[i]=='L'){
        		ten += 5;
        		i--;
        	}
        } else if(s[i]=='L'){
        	i--;
        	if(i>=0 && s[i]=='X'){
        		ten = 4;
        		i--;
        	} else {
        		ten = 5;
        	}
        }

        //Calculate hundred's place
        if(i>=0 && s[i]=='M'){
        	if(i>=0 && s[i-1]=='C'){
        		hundred = 9;
	        	i-=2;
        	} else {
        		hundred = 0;
        	}
        } else if(s[i]=='C'){
        	while(i>=0 && s[i]=='C'){
        		hundred += 1;
        		i--;
        	}
        	if(i>=0 && s[i]=='D'){
        		hundred += 5;
        		i--;
        	}
        } else if(s[i]=='D'){
        	i--;
        	if(i>=0 && s[i]=='C'){
        		hundred = 4;
        		i--;
        	} else {
        		hundred = 5;
        	}
        }

        while(i>=0 && s[i]=='M'){
        	thou++;
        	i--;
        }

        ans = thou*1000+hundred*100+ten*10+unit;
        return ans;
}

int main(){
	cout << romanToInt("MMCCCXCIX") << endl;
	return 1;
}