#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
unordered_map<string, double> score;
double credit, total_score, total_credit;
string grade;
int main(){
	score["A+"] = 4.5;
	score["A0"] = 4.0;
	score["B+"] = 3.5;
	score["B0"] = 3.0;
	score["C+"] = 2.5;
	score["C0"] = 2.0;
	score["D+"] = 1.5;
	score["D0"] = 1.0;
	score["F"] = 0.0;
	
	for(int i=0;i<20;i++){
		string _; 
		cin>>_>>credit>>grade;
		if(grade == "P") continue;
		
		total_score += credit * score[grade];
		total_credit += credit;
	}
	cout<<total_score / total_credit;
	return 0;
}