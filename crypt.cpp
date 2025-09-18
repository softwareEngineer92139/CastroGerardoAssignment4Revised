/* ---------------------------------------------------------------------------
** I attest that this following code represents our own work and is subject to
** the plagiarism policy found in the course syllabus.
**
** Class: 	CSC 242
** Assignment: 	Lesson #4
** File: 	cypher.cpp
** Description: This project is about practicing file input and output and
** reverse alphabet with a keyword combined for encryption. P8.2 from the book.
**
** Collaborators: 	Gerardo Castro, Clint Woods, Shanique Battle, Jeremy Sherman
** Date: 	08/08/2025
** -------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
	// filestream variables
	ifstream inFile;
	ofstream outFile;

	// starting index for command line arguments
	int i = 0;

	// command line arguments
	string arg = argv[i];		// program name
	string arg2 = argv[i + 1];	// -e for encryption
	string arg3 = argv[i + 2];	// keyword with -k in front
	string arg4 = argv[i + 3];	// input file name
	string arg5 = argv[i + 4];	// output file name

	// setup reverse alphabet and keyword
	int m = 2;					// starting index for keyword
	string reverseAlphabet = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
	string keyword = arg3.substr(m);
	keyword.append(reverseAlphabet);

	// Remove duplicates from keyword
	string result;
	for (char c : keyword)
	{
		if (result.find(c) == string::npos)
		{
			result += c;
		}
	}

	// Open input and output files
	inFile.open(arg4);
	if (inFile.fail())
	{
		cout << "Error opening input file" << endl;
		return 1;
	}
	outFile.open(arg5);
	if (outFile.fail())
	{
		cout << "Error opening output file" << endl;
		return 1;
	}

	// Encryption process
	char ch;
	while (inFile.get(ch))
	{
		switch (ch)
		{
		case 'A':ch = result[0]; break;
		case 'B':ch = result[1]; break;
		case 'C':ch = result[2]; break;
		case 'D':ch = result[3]; break;
		case 'E':ch = result[4]; break;
		case 'F':ch = result[5]; break;
		case 'G':ch = result[6]; break;
		case 'H':ch = result[7]; break;
		case 'I':ch = result[8]; break;
		case 'J':ch = result[9]; break;
		case 'K':ch = result[10]; break;
		case 'L':ch = result[11]; break;
		case 'M':ch = result[12]; break;
		case 'N':ch = result[13]; break;
		case 'O':ch = result[14]; break;
		case 'P':ch = result[15]; break;
		case 'Q':ch = result[16]; break;
		case 'R':ch = result[17]; break;
		case 'S':ch = result[18]; break;
		case 'T':ch = result[19]; break;
		case 'U':ch = result[20]; break;
		case 'V':ch = result[21]; break;
		case 'W':ch = result[22]; break;
		case 'X':ch = result[23]; break;
		case 'Y':ch = result[24]; break;
		case 'Z':ch = result[25]; break;
		default: ch = '#'; break;
		}
		outFile.put(ch);
	}

	// Display the key used for encryption
	cout << "Regular Alphabet: ABCDEFGHIJKLMNOPQRSTUVWXYZ" << endl;
	cout << "Reference cypher: " << result << endl;
	cout << "End of Program" << endl;
	return 0;
}