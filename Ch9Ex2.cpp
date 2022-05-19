#include<string>
#include<iostream>
#include<fstream>

using namespace std;

struct studentType	
{
	string studentFName;
	string studentLName;
	int testScore;
	char grade;
};

studentType studentRecords[20]; //Initializes array

void getStudentData(); //global functions
void HighestTest();
void beststudent();

int main() 
{
    getStudentData();
    HighestTest();
    beststudent();
	
	return 0;
}
void getStudentData()
{
	ifstream infile ("Ch9Ex2InData.txt");
	ofstream outfile ("StudentData.txt");
	
	outfile << "Students, Score, and Grade" << endl;
	
	for(int x=0; x < 20; x++) //writes student to file, adds score, assigns grade
	{
		infile >> studentRecords[x].studentFName 
			   >> studentRecords[x].studentLName
			   >> studentRecords[x].testScore;
		
		if (studentRecords[x].testScore >= 90)
			studentRecords[x].grade = 'A';
		else if (studentRecords[x].testScore >= 80)
			studentRecords[x].grade = 'B';
		else if (studentRecords[x].testScore >= 70)
			studentRecords[x].grade = 'C';
		else if (studentRecords[x].testScore >= 60)
			studentRecords[x].grade = 'D';
		else
			studentRecords[x].grade = 'F';		
		
		outfile << left << studentRecords[x].studentLName << ", "
				<< studentRecords[x].studentFName 
				<< " Score : " << studentRecords[x].testScore
				<< " Grade : " << studentRecords[x].grade << endl;
	}
	infile.close();
	outfile.close();
}

void HighestTest()
{
	
	ifstream infile ("Ch9Ex2InData.txt");
	ofstream outfile ("HiScore.txt");
	
int hitest = 0;
int index = 0;
 
for(int x = 0; x < 20; x++) //scans each student and returns highest grade
	{
		if (studentRecords[x].testScore > hitest)
		{
			index = x;
			hitest = studentRecords[x].testScore;
		}
	}
	outfile << "The highest score in the class is a : " << studentRecords[index].testScore << endl;
	
	infile.close();
	outfile.close();
}

void beststudent() //similar to previous function but returns the student
{
	ifstream infile ("Ch9Ex2InData.txt");
	ofstream outfile ("BestStudents.txt");
	int hitest = 0;	
	int index = 0;
	int x;

	for(x=0; x < 20; x++){
		if (studentRecords[x].testScore > hitest)
		{
			index = x;
			hitest = studentRecords[x].testScore;
		}
    }

outfile << "The student(s) with the highest score(s) of " << studentRecords[index].testScore << ": " << endl;

for(x = 0; x < 20; x++){ //writes student to file
	if(studentRecords[x].testScore == studentRecords[index].testScore) 
		outfile << studentRecords[x].studentLName
				<< ", " << studentRecords[x].studentFName << endl;
    }
    infile.close();
    outfile.close();
}