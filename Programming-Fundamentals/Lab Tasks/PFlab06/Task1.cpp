#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
void openFiles(ifstream& inFile, ofstream& outFile);
void initialize(double& countMale, double& countFemale, double& sumMaleGPA, double& sumFemaleGPA, double& avgMaleGPA, double& avgFemaleGPA);
void sumGrades(ifstream& inFile, double& countMale, double& countFemale, double& sumMaleGPA, double&sumFemaleGPA);
void averageGrade(double countMale, double countFemale, double sumMaleGPA, double sumFemaleGPA, double& avgMaleGPA, double& avgFemaleGPA);
void printResults(ofstream& outFile, double avgMaleGPA, double avgFemaleGPA);
int main() {
	double sumMaleGPA, sumFemaleGPA, avgMaleGPA, avgFemaleGPA, countMale, countFemale;
	ifstream inFile;
	ofstream outFile;
	openFiles(inFile, outFile);
	initialize(countMale, countFemale, sumMaleGPA, sumFemaleGPA, avgMaleGPA, avgFemaleGPA);
	sumGrades(inFile, countMale, countFemale, sumMaleGPA, sumFemaleGPA);
	averageGrade(countMale, countFemale, sumMaleGPA, sumFemaleGPA, avgMaleGPA, avgFemaleGPA);
	printResults(outFile, avgMaleGPA, avgFemaleGPA);
	inFile.close();
	outFile.close();
	return 0;
}
void openFiles(ifstream& inFile, ofstream& outFile)
{
	inFile.open("GPA.txt");
	outFile.open("avgGPA.txt");
	outFile << showpoint << fixed << setprecision(2);
}
void initialize(double& countMale, double& countFemale, double& sumMaleGPA, double& sumFemaleGPA, double& avgMaleGPA, double& avgFemaleGPA)
{
	countMale = 0;
	countFemale = 0;
	sumMaleGPA = 0;
	sumFemaleGPA = 0;
	avgMaleGPA = 0;
	avgFemaleGPA = 0;
}
void sumGrades(ifstream& inFile, double& countMale, double& countFemale, double& sumMaleGPA, double&sumFemaleGPA)
{
	char gender;
	double gpa;
	inFile >> gender;
	while (!inFile.eof())
	{
		if (gender == 'm')
		{
			countMale++;
			inFile >> gpa;
			sumMaleGPA += gpa;
			inFile.ignore(5, '\n');
		}
		else if (gender == 'f')
		{
			countFemale++;
			inFile >> gpa;
			sumFemaleGPA += gpa;
			inFile.ignore(5, '\n');
		}
		inFile >> gender;
	}
}

void averageGrade(double countMale, double countFemale, double sumMaleGPA, double sumFemaleGPA, double& avgMaleGPA, double& avgFemaleGPA)
{
	avgMaleGPA = sumMaleGPA / countMale;
	avgFemaleGPA = sumFemaleGPA / countFemale;
}

void printResults(ofstream& outFile, double avgMaleGPA, double avgFemaleGPA)
{
	outFile << "GENDER GPA ANALYSIS..." << endl << endl << left << setw(15) << "AVG Male GPA:" << right << setw(7) << avgMaleGPA << endl << left << setw(15) << "AVG Female GPA:" << right << setw(7) << avgFemaleGPA;
}
