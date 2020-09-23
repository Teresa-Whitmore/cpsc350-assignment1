//============================================================================
// Name        : Assignment1.cpp
// Author      : Teresa Whitmore
// Date  	   : September 22ns, 2022 (NOTE: Using 1 "late day")
// Description : Assignment 1 for CPSC 350
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

int main() {

	cout.setf(ios::fixed);
	cout.setf (ios::showpoint);


	string input;
	string output = "C:\\Users\\Disne\\Desktop\\College\\DataStructures\\Assignments\\TestFiles\\teresawhitmore.out"; //Assigns file name to output variable.
	string sourceContent; //Declares string variable for storing source content from input file.

	string promptYN = "Y";

	int bigram;

	int countChar = 0;
	double countLines = 0;
	int countSum = 0;
	int countPairs = 0;
	double countMean = 0;
	double countCharSqd = 0;
	double var = 0;
	double stdDev = 0;

	double countA = 0;
	double countC = 0;
	double countT = 0;
	double countG = 0;
	double probA = 0;
	double probC = 0;
	double probT = 0;
	double probG = 0;

	double countAA = 0;
	double countAC = 0;
	double countAT = 0;
	double countAG = 0;
	double countCA = 0;
	double countCC = 0;
	double countCT = 0;
	double countCG = 0;
	double countTA = 0;
	double countTC = 0;
	double countTT = 0;
	double countTG = 0;
	double countGA = 0;
	double countGC = 0;
	double countGT = 0;
	double countGG = 0;

	cout << "Enter file path and name: "; //Prompts user for input file path and name.

	getline(cin, input); //Reads and assigns user entry to "input" variable.

	ifstream fileInput(input); //Opens input file.
	ofstream fileOutput(output, ios_base::out | ios_base::app); //Creates and/or opens file for output, with specification to start at the end of the file (append).

	while(getline(fileInput, sourceContent)) //Loop to read each line of the file to the end.
		{

		for (int i = 0; i <= sourceContent.length(); ++i)
			{
			countChar = i;

			if (sourceContent[i] == 'A')
				countA += 1;
			else if (sourceContent[i] == 'C')
				countC += 1;
			else if (sourceContent[i] == 'T')
				countT += 1;
			else if (sourceContent[i] == 'G')
				countG += 1;
			}

		bigram = sourceContent.find("AA", 0);

		while (bigram != string::npos)
			{
				bigram = sourceContent.find("AA", bigram + 1);
				countAA++;
			}

		bigram = sourceContent.find("AC", 0);

		while (bigram != string::npos)
			{
				bigram = sourceContent.find("AC", bigram + 1);
				countAC++;
			}

		bigram = sourceContent.find("AT", 0);

		while (bigram != string::npos)
			{
				bigram = sourceContent.find("AT", bigram + 1);
				countAT++;
			}

		bigram = sourceContent.find("AG", 0);

		while (bigram != string::npos)
			{
				bigram = sourceContent.find("AG", bigram + 1);
				countAG++;
			}

		bigram = sourceContent.find("CA", 0);

		while (bigram != string::npos)
			{
				bigram = sourceContent.find("CA", bigram + 1);
				countCA++;
			}

		bigram = sourceContent.find("CC", 0);

		while (bigram != string::npos)
			{
				bigram = sourceContent.find("CC", bigram + 1);
				countCC++;
			}

		bigram = sourceContent.find("CT", 0);

		while (bigram != string::npos)
			{
				bigram = sourceContent.find("CT", bigram + 1);
				countCT++;
			}

		bigram = sourceContent.find("CG", 0);

		while (bigram != string::npos)
			{
				bigram = sourceContent.find("CG", bigram + 1);
				countCG++;
			}

		bigram = sourceContent.find("TA", 0);

		while (bigram != string::npos)
			{
				bigram = sourceContent.find("TA", bigram + 1);
				countTA++;
			}

		bigram = sourceContent.find("TC", 0);

		while (bigram != string::npos)
			{
				bigram = sourceContent.find("TC", bigram + 1);
				countTC++;
			}

		bigram = sourceContent.find("TT", 0);

		while (bigram != string::npos)
			{
				bigram = sourceContent.find("TT", bigram + 1);
				countTT++;
			}

		bigram = sourceContent.find("TG", 0);

		while (bigram != string::npos)
			{
				bigram = sourceContent.find("TG", bigram + 1);
				countTG++;
			}

		bigram = sourceContent.find("GA", 0);

		while (bigram != string::npos)
			{
				bigram = sourceContent.find("GA", bigram + 1);
				countGA++;
			}

		bigram = sourceContent.find("GC", 0);

		while (bigram != string::npos)
			{
				bigram = sourceContent.find("GC", bigram + 1);
				countGC++;
			}

		bigram = sourceContent.find("GT", 0);

		while (bigram != string::npos)
			{
				bigram = sourceContent.find("GT", bigram + 1);
				countGT++;
			}

		bigram = sourceContent.find("GG", 0);

		while (bigram != string::npos)
			{
				bigram = sourceContent.find("GG", bigram + 1);
				countGG++;
			}

		countLines += 1;
		countSum += countChar; // Calculates and assigns total sum of lines
		countCharSqd += pow(countChar, 2);
		//cout << sourceContent << endl; // Displays source content to user.
		//fileOutput << sourceContent << endl; // Appends results to file.
		countMean = countSum / countLines;
		var = (countCharSqd - (countSum * countSum) /(countLines))/ (countLines -1);
		countPairs = countSum / 2;

		}

	probA = countA / countSum;
	probC = countC / countSum;
	probT = countT / countSum;
	probG = countG / countSum;

	stdDev = sqrt(var);

	cout << endl;


	fileOutput << "Name: Teresa Whitmore \t ID: 2381847 \t Assignment 1 \t Date: 09/22/2020 (using 1 late day)" << endl;
	fileOutput << endl;
	fileOutput << "The Sum of the length of the DNA strings is: " << countSum << endl;
	fileOutput.precision(1);
	fileOutput << "The Mean of the length of the DNA strings is: " << countMean << endl;
	fileOutput.precision(2);
	fileOutput << "The Variance of the length of the DNA strings is: " << var << endl;
	fileOutput.precision(2);
	fileOutput << "The Standard Deviation of the length of the DNA strings is: " << stdDev << endl;
	fileOutput << "Here is the relative probability of each nucleotide:" <<  endl;
	fileOutput << endl;
	fileOutput  << "A:\t" << probA << endl;
	fileOutput  << "C:\t" << probC << endl;
	fileOutput  << "T:\t" << probT << endl;
	fileOutput  << "G:\t" << probG << endl;
	fileOutput << endl;
	fileOutput.precision(4);
	fileOutput << "Here is the relative probability of each nucleotide bigram:" <<  endl;
	fileOutput << "AA:\t" << countAA/countPairs << endl;
	fileOutput << "AC:\t" << countAC/countPairs << endl;
	fileOutput << "AT:\t" << countAT/countPairs << endl;
	fileOutput << "AG:\t" << countAG/countPairs << endl;
	fileOutput << "CA:\t" << countCA/countPairs << endl;
	fileOutput << "CC:\t" << countCC/countPairs << endl;
	fileOutput << "CT:\t" << countCT/countPairs << endl;
	fileOutput << "CG:\t" << countCG/countPairs << endl;
	fileOutput << "TA:\t" << countTA/countPairs << endl;
	fileOutput << "TC:\t" << countTC/countPairs << endl;
	fileOutput << "TT:\t" << countTT/countPairs << endl;
	fileOutput << "TG:\t" << countTG/countPairs << endl;
	fileOutput << "GA:\t" << countGA/countPairs << endl;
	fileOutput << "GC:\t" << countGC/countPairs << endl;
	fileOutput << "GT:\t" << countGT/countPairs << endl;
	fileOutput << "GG:\t" << countGG/countPairs << endl;
	fileOutput << endl;

		while (promptYN == "Y")
		{
			for (int j = 0; j <= 999; ++j)
			{
				double a;
				double b;
				double C;
				double D;

				int randNum;
				char randLetter;

				a = rand() * (1.0 / RAND_MAX);
				b = rand() * (1.0 / RAND_MAX);

				C = sqrt(-2 * log(a)) * cos((2*3.14159)*b);

				D = (stdDev * C) + countMean;

				for (int k = 0; k < D; ++k)
				{
					randNum = rand() % 4;

					if (randNum == 0)
						randLetter = 'A';
					if (randNum == 1)
						randLetter = 'C';
					if (randNum == 2)
						randLetter = 'T';
					if (randNum == 3)
						randLetter = 'G';

					fileOutput << randLetter;
				}

				fileOutput << endl;
				//fileOutput.close(); //Closes the output file.
			}

			cout << "Would you like to generate another 1,000 bigrams? (Y or N): ";
			cin >> promptYN;
		}

		fileInput.close(); //Closes the input file.
		fileOutput.close(); //Closes the output file.
	return 0; //Exits the program.
}
