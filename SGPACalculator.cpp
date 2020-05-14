#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;

#define MAX_SIZE 100
#define PASSING_CRITERIA 0.5

class subject {
	
	public : 
		int maxCredits;
		int grade;
		int earnedCredits;
		
	public :	
	subject(){
		maxCredits = 0;
		earnedCredits = 0;
		grade = 0;
	}
};

class Student : public subject {
	private : 
		int numberOfSubjects;
		subject arrayOfSubjects[MAX_SIZE];
		int totalCredits;
		int earnedCredits;
		double SGPA;
		
	public : 
		Student(){
			numberOfSubjects = 0;
			totalCredits = 0;
			earnedCredits = 0;
		}
		
		void init();
		double calculateSGPA();
		int getTotalCredits();
		int getEarnedCredits();
		bool determinePassFail();
};

void Student :: init(){
	cout << "\nEnter number of subjects : ";
	cin >> numberOfSubjects;
	Student();
}

double Student :: calculateSGPA(){
	
	int totalMarks = 0;
	int total = 0;
	
	for(int i = 0; i < numberOfSubjects ; i++){
		cout << "\nEnter maximum credits for subject : ";
		cin >> arrayOfSubjects[i].maxCredits;
		
		cout << "\nEnter earned credits for subject : ";
		cin >> arrayOfSubjects[i].earnedCredits;
		
		
		while(arrayOfSubjects[i].grade < 1 || arrayOfSubjects[i].grade > 10) {
			cout << "\nEnter earned grade (1-10) for subject : ";
			cin >> arrayOfSubjects[i].grade;
		}	
	
		
	}
	
	totalCredits = getTotalCredits();
	
	for(int i = 0; i < numberOfSubjects; i++){
		totalMarks += arrayOfSubjects[i].grade * arrayOfSubjects[i].maxCredits ;
		total += arrayOfSubjects[i].maxCredits * 10;
	}
	
	SGPA = (float(totalMarks)/float(total))*10;
	return SGPA;
	
}

int Student :: getTotalCredits(){
	int totalCredits = 0;
	for(int i =0; i < numberOfSubjects ; i++){
		totalCredits += arrayOfSubjects[i].maxCredits;
	}
	return totalCredits;
}

int Student :: getEarnedCredits(){
	int earnedCredits = 0;
	for(int i =0; i < numberOfSubjects ; i++){
		earnedCredits += arrayOfSubjects[i].earnedCredits;
	}
	return earnedCredits;
}

bool Student :: determinePassFail(){
	totalCredits = getTotalCredits();
	earnedCredits = getEarnedCredits();
	
	float creditRatio = float(earnedCredits)/float(totalCredits);
	
	if(creditRatio < 0.5 || SGPA < 4){
		return false;
	}
	else return true;
}

int main(){
	
	Student oneRandomStudent;
	
	oneRandomStudent.init();
	double oneRandomStudentSGPA = oneRandomStudent.calculateSGPA();
	cout << "\nYour SGPA is " << setprecision(2) << oneRandomStudentSGPA;
	bool passingStatus = oneRandomStudent.determinePassFail();
	if(passingStatus) cout << "\nPass!";
	else cout << "\nFail!";
	return 0;
}

/* 

Enter number of subjects : 2

Enter maximum credits for subject : 4

Enter earned credits for subject : 3

Enter earned grade (1-10) for subject : 7

Enter maximum credits for subject : 4

Enter earned credits for subject : 4

Enter earned grade (1-10) for subject : 9

Your SGPA is 8
Pass!

*/






















