#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

void decimaltohex(long long int n, char hex4[]);	//precondition requires and int number to conver from decimal to hex
// function declaration to convert decimaltohex
// stores the hexadecimal value in a character array
long long int hextodecimal(const char hexarray1[], const char hexarray2[]);	// converts hexadecimal to decimal

void reversecharacter(char sum1[]);	// reverse the characters stored in hex4 array to output the correct sequence1

void input();	// input from keyboard or user function call


int main()	// main function
{

	input();	// function call to input
	return 0;
}

void input()
{
	char hexarray1[12] = { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };	// initializing the arrays
	char hexarray2[12] = { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };
	char hexasum[12] = { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };
	long long int decimalsum;
	char continue1;
	char input;
	do                                     // do while loop initiation

	{


		cout << "Hexadecimal adder by Vaibhav. Enter 1 or 2 " << endl;
		cout << "1. Input from key board " << endl;
		cout << "2. Input from file " << endl;
		cin >> input;

		if (input == '1')
		{
			cout << endl;
			cout << "Enter hexadecimal number of 12 or fewer digits" << endl;
			cin >> hexarray1;
			cout << "Enter hexadecimal number of 12 or fewer digits " << endl;
			cin >> hexarray2;
			decimalsum = hextodecimal(hexarray1, hexarray2);

			decimaltohex(decimalsum, hexasum);
			
			string length1 = string(hexasum);
			if (length1.length() < 13)
				cout << endl << hexarray1 << " + " << hexarray2 << " = " << hexasum;
			else
				cout << "*********Addition Overflow Error**********";

		}

		else if (input == '2')
		{
			ifstream fin;
			ofstream fout;

			char a[12], b[12];
			string filename;

			cout << "enter file name: " << endl;
			cin >> filename;

			fin.open(filename);
			if (fin.fail())
			{
				cout << "Input file opening failed " << endl;
			}
			fout.open("input-out.txt");

			fin >> a;
			fin >> b;
			cout << endl;
			cout << "The hex number1 which is read from input is : " << a << endl;
			cout << "The hex number2 which is read from input is : " << b << endl;

			decimalsum = hextodecimal(a, b);


			decimaltohex(decimalsum, hexasum);

			string length1 = string(hexasum);

			if (length1.length() < 13)
			{
				cout << hexasum << " is written into the output file";
				fout << hexasum;
			}
			else
			{
				fout << "*********Addition Overflow Error***********";
				cout << "File is written with the answer";
			}
			fin.close();
			fout.close();
		}
		else
		{
			cout << "invalid input";
		}


		cout << endl << endl << "continue  (y/n) " << endl << endl;
		cin >> continue1;
		cout << endl;

	} while (continue1 == 'y' || continue1 == 'Y');	// end loop only for y or Y



	cout << "---------------End-------------------" << endl;


}
void decimaltohex(long long int decimalsum, char hexasum[]) // converting decimal to hex
{
	long long int i = 0, modulo;
	while (decimalsum != 0)
	{
		modulo = decimalsum % 16;
		switch (modulo)
		{
		case 10:
			hexasum[i] = 'A';
			break;
		case 11:
			hexasum[i] = 'B';
			break;
		case 12:
			hexasum[i] = 'C';
			break;
		case 13:
			hexasum[i] = 'D';
			break;
		case 14:
			hexasum[i] = 'E';
			break;
		case 15:
			hexasum[i] = 'F';
			break;
		default:
			hexasum[i] = modulo + '0';
			break;
		}
		++i;
		decimalsum /= 16;
	}
	hexasum[i] = '\0';

	reversecharacter(hexasum); // function call to reverse the hexadecimal character
}

long long int hextodecimal(const char hexarray1[], const char hexarray2[])   // Function to convert hexadecimal to decimal
{
	int i, size;
	long long int dec1 = 0;
	long long int dec2 = 0;
	long long int  dec3 = 0;

	for (size = 0; hexarray1[size] != '\0'; ++size);
	for (i = 0; hexarray1[i] != '\0'; ++i, --size)
	{
		if (hexarray1[i] >= '0' && hexarray1[i] <= '9')
			dec1 += (hexarray1[i] - '0')*pow(16, size - 1);	// substracting ascII values from characters and converting to decimal
		if (hexarray1[i] >= 'A' && hexarray1[i] <= 'F')
			dec1 += (hexarray1[i] - 55)*pow(16, size - 1);
		if (hexarray1[i] >= 'a' && hexarray1[i] <= 'f')
			dec1 += (hexarray1[i] - 87)*pow(16, size - 1);
		if (hexarray1[i] >= 'g' && hexarray1[i] <= 'z' || hexarray1[i] >= 'G' && hexarray1[i] <= 'Z')
		{
			cout << endl << "Invalid input" << endl << endl;
			input();
		}
	}

	for (size = 0; hexarray2[size] != '\0'; ++size);
	for (i = 0; hexarray2[i] != '\0'; ++i, --size)
	{
		if (hexarray2[i] >= '0' && hexarray2[i] <= '9')
			dec2 += (hexarray2[i] - '0')*pow(16, size - 1);
		if (hexarray2[i] >= 'A' && hexarray2[i] <= 'F')
			dec2 += (hexarray2[i] - 55)*pow(16, size - 1);
		if (hexarray2[i] >= 'a' && hexarray2[i] <= 'f')
			dec2 += (hexarray2[i] - 87)*pow(16, size - 1);
		if (hexarray2[i] >= 'g' && hexarray2[i] <= 'z' || hexarray2[i] >= 'G' && hexarray2[i] <= 'Z')
		{
			cout << endl << "Invalid input" << endl << endl;
			input();
		}

	}


	dec3 = dec1 + dec2;	// adding it as decimal numbers
	return dec3;	//return the value

}
void reversecharacter(char sum1[])		//reverse the sum
{
	long int length = strlen(sum1);
	int temp, i, k;

	for (i = 0, k = length - 1; i < k; i++, k--)
	{
		temp = sum1[i];
		sum1[i] = sum1[k];
		sum1[k] = temp;
	}
}
