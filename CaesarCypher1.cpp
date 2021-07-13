#include <iostream>
#include <string>
using namespace std;
/*
					B00340010_GRLA09003_01
*/
int main()
{
	string input; //the data type of string will be used to hold the users input
	int count = 0, length, choice, key;
	//count variable will initialize the zero
	//length will be the length of the users inputs
	//Choice gives the user the option to select 'encryption' or 'decryption' and based on the selection a specific part of the code wil run

	cout << "Enter text: "; //prompts the user to input text they want to encrypt or decrypt
	getline(cin, input); //getline takes the users input and turns it into a string

	length = (int)input.length(); //sets the length of string to match the length of the inputted text including spaces

	cout << "Enter key: "; //user is prompted to input a key, which is a number to be applied to the inputted text to either encrypt or decrypt the inputted text
	cin >> key; //takes the key as input

	cout << "Enter your choice \n1. Encryption \n2. Decryption \n"; // entering '1' runs the encryption code and entering '2' runs the decryption code
	cin >> choice;

	if (choice == 1) //code to run the encryption on the inputted text
		for (count = 0; count < length; count++) //checks count is less than the length
		{
			if (isalpha(input[count])) //checks each character is part of the alphabet
			{
				input[count] = tolower(input[count]); //inputs the text in lowercase format
				for (int i = 0; i < key; i++) //checks each character in the inputted string and applies the inputted 'key' to each character
				{
					if (input[count] == 'z') //this 'if' statement is checking that if the key is going to take the encryption of the character past 'z' that the next character after 'z' will be 'a'
						input[count] = 'a';
					else                 //Else if the encryption key applied to a character will not take the new encrypted key past 'z' then the above 'if' statement will be skipped
						input[count] ++; //The key is applied to every character in the string and the key is added to the character, so the character moves forward through the alphabet
				}
			}
		}
	cout << "Encoded plaintext: " << input << endl; //displays the result of encrypting the original plaintext inputted by the user at the start of the programme

	if (choice == 2) { //code to run the decryption on the inputted text
		for (count = 0; count < length; count++) //checks count is less than the length
		{
			if (isalpha(input[count])) //checks each character is part of the alphabet
			{
				input[count] = tolower(input[count]); //inputs the text in lowercase format
				for (int i = 0; i < key; i++) //checks each character in the inputted string and applies the inputted 'key' to each character
				{
					if (input[count] == 'a') //this 'if' statement is checking that if the key is going to take the decryption of the character past 'a' that the next character after 'a' will be 'z'
						input[count] = 'z';
					else                 //Else if the decryption key applied to a character will not take the new decrypted key past 'a' then the above 'if' statement will be skipped
						input[count] --; //This time the key is counting backwards from the inputted characters in the string
				}
			}
		}
		cout << "Decoded cyphertext: " << input << endl; //displays the result of decrypting the original cyphertext inputted by the user at the start of the programme
	}
}
//References used to help in the development and execution of the above code:
//https://www.youtube.com/watch?v=_EQ6TJs_TEk
//https://www.tutorialspoint.com/cplusplus-program-to-implement-caesar-cypher



