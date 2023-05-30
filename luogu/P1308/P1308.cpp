#include <bits/stdc++.h>
using namespace std;

void LOWER(string s){
	for(int i=0;i<s.size();i++){
		if(isupper(s[i])){
			s[i]+='a'-'A';
		}
	}	
}

int main(){
	string word,s;
	getline(cin,word);
	getline(cin,s);

	LOWER(word);
	LOWER(s);

	word=' '+word+' ';
	s=' '+s+' ';

	if(s.find(word)==-1){
		cout<<-1<<endl;
	}
	else{
		int firstpos=s.find(word);
		int nextpos=s.find(word),count=0;
		while(nextpos!=-1){
			count++;
			nextpos=s.find(word,nextpos+1);
		}	
		cout<<count<<' '<<firstpos<<endl;
	}
	return 0;
}