#include <iostream>
#include <vector>
#include <string>

using namespace std;

int mult_grtr_than_a(int a, int b){
	int mult = b, i = 2;
	while(mult<a){
		mult = b*i;
		i++;
	}
	return mult;
}

vector<string> fullJustify(vector<string>& words, int maxWidth) {
        if(maxWidth==0 || maxWidth==1) return words;
        vector<string> ans;
        bool finished = false;
        string tmp, sp_str;
        int i = 0, j = 0, spaces = 0, sp = 0;
        while(!finished){
                tmp = ""; sp_str = "", spaces = 0, j = 0;
                int k = i;
                while(i<words.size() && j+spaces+words[i].length()<=maxWidth){
                        j += words[i].length();
                        if(j+spaces<maxWidth) spaces += 1; //space
                        i++;
                }
                spaces = maxWidth - j;
                if(i>=words.size()){
                        finished = true;
                        sp_str = " ";
                        // cout << i << "," << k << "," << spaces << "," << sp << endl;
                        for(int l=k;l<i;l++){
                                tmp += words[l];
                                if(l==i-1) break;
                                tmp += " ";
                                spaces -= 1;
                        }
                        while(spaces>0){
                                tmp += " ";
                                spaces--;
                        }
                        ans.push_back(tmp);
                } else {
                        if(i==k+1){
                                tmp += words[k];
                                while(spaces>0){
                                        tmp += " ";
                                        spaces--;
                                }
                                ans.push_back(tmp);
                                continue;
                        }
                        // sp = mult_grtr_than_a(spaces, i-k-1)/(i-k-1);
                        for(int l=k;l<i;l++){
                                tmp += words[l];
                                if(i==l+1) sp = spaces;
                                else sp = mult_grtr_than_a(spaces, i-l-1)/(i-l-1);
                                cout << i << "," << l << "," << spaces << "," << sp << "," << endl;
                                if(spaces>=sp) spaces -= sp;
                                else spaces = 0;
                                for(int m=0;m<sp;m++){
                                        tmp += " ";
                                }
                        }
                        ans.push_back(tmp);
                }
        }
        return ans;
}

int main(){
        // string arr[] = {"This", "is", "an", "example", "of", "text", "justification."};
	string arr[] = {"My","momma","always","said,","\"Life","was","like","a","box","of","chocolates.","You","never","know","what","you're","gonna","get."};
	vector<string> strs(arr, arr+sizeof(arr)/sizeof(string));
	strs = fullJustify(strs, 20);
	for(int i=0;i<strs.size();i++){
		cout << "\"" << strs[i] << "\"" << endl;
	}
	return 0;
}