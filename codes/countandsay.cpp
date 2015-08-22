#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string nextSequence(string sequence, int n){
	if(n<=0) return sequence;
	stringstream ans("");
	int i = 0, count = 0;
	int previous = sequence[0]-'0';
	while(i<sequence.length()){
		int num = sequence[i]-'0';
		if(num==previous) count++;
		else {
			ans << count << previous;
			count = 1;
		}
		previous = num;
		i++;
	}
	ans << count << previous;
	return nextSequence(ans.str(), n-1);
}

string countAndSay(int n){
        return nextSequence("1", n-1);
}

int main(){
	cout << countAndSay(16) << endl;
	return 0;
}