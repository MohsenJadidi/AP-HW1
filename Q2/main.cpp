/*
*	AP2018 : HW1 - Question 2
*	Mohammad Mohsen Jadidi 9423029 @AUT
*/

#include <iostream>
#include <fstream>
#include <string>

void bruteforce(std::string, std::string, std::string, const size_t&);
char uppercase(char&);

int main()
{
	std::string name{};			// String for store name
	std::string year{};			// String for store year
	std::string code{""};		// String for code of name & year
	size_t length_name{};		// Length of name

	/* Getting name from user */
	std::cout << "Enter name : ";
	std::cin >> name;
	length_name = name.size();

	/* Getting year from user */
	std::cout << "Enter year : ";
	std::cin >> year;

	/* Generate or empty the dictionary.txt */
	std::ofstream of{"dictionary.txt"};

	/* Call bruteforce function & Generate & print(in console & file) codes
	   that created from name and year */
	std::cout << "** Start Bruteforce method **" << '\n';
	bruteforce(name, year, code, length_name);
	std::cout << "** Finish Bruteforce method **" << '\n';
	std::cout << "\n>> This codes printed in dictionary.txt" << '\n';

	return 0;
}

/* Function to Bruteforce method - Generate code that created
   from name string and year string & print in console & text file */
void bruteforce(std::string str1, std::string str2, std::string code,
	 			const size_t& code_desired_length)
{
	if( code.size() == code_desired_length)	// if length of code equal to...
	{										// length of name code creation is done
		/* Print codes in console */
		std::cout << "Code : " << code + str2 <<'\n';
		std::cout << "Code : " << str2 + code <<'\n';

		/* Print codes in text file */
		std::ofstream of{};
		of.open("dictionary.txt", std::ofstream::app);
		of << code + str2 <<'\n';
		of << str2 + code <<'\n';
		of.close();
	}
	else  // until length of name less than length of name the algorithm  is running
	{
		/* 1) lower letters - Call bruteforce function with substring*/
		bruteforce(str1.substr(1, code_desired_length), str2, code+str1[0], code_desired_length);

		/* 2) uppercase letters - Call bruteforce function with substring*/
		bruteforce(str1.substr(1, code_desired_length), str2, code +
				   uppercase(str1[0]), code_desired_length);

	}

}

char uppercase(char& ch)
{
	/* 32 is difference between ascii code of 'A' and 'a'*/
	return static_cast<char>(ch-32);
}
