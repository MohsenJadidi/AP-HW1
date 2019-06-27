/*
*	AP2018 : HW1 - Question 4
*	Mohammad Mohsen Jadidi 9423029 @AUT
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

void printArray(int arr[], size_t n);

int main()
{
	std::vector<int> input_file{};	// Array for store numbers in input file
	size_t length{};				// length of  input that we read from file
	int left{}, right{};			// input[i] divide to left & right( input[i] = left+right )
	int min{},max{};				/* Store Previous left & right that store in guess_list ...
									  (min & max is minimum & maximun value in guess_list) */

	/* Read file & store in input array */
	std::ifstream in{"input.txt"};
	while (!in.eof())
	{
		int temp_input{}; 		 // Temporary varible for a value that entered by user
		in >> temp_input;
		input_file.push_back(temp_input);
	}
	input_file.pop_back();
	in.close();

	/* Define dynamic array for guessed initial list & desired list */
	length = input_file.size();
	std::cout << "/* message */"<< length << '\n';
	int* input{&input_file[0]};				// Input of functions is array type(no vector)!
	int* guess_list{new int[2*length]};		// Array for guessed initial list
	for (size_t i = 0; i < 2*length; i++)
		guess_list[i] = 0;
	int* desire_list{new int[length]};		//Array for desired list

	/* Print Input list & Guessed initial list*/
	std::cout << "Input : ";
	printArray(input, length);
	std::cout << "length of input = " << length << '\n';
	std::cout << "Guessed list : ";
	printArray(guess_list, 2*length);

	/*** The algorithm starts from here ***/
	/* Set value of min and max */
	if (input[length-1] % 2 == 0)
	{
		min = input[length-1] / 2;
		max = min;
	}
	else
	{
		min = input[length-1] / 2;
		max = min + 1;
	}

	/* Loop  on input array. For every element in ...
	   input array evalute 2 element in guessed initial array */
	for (int i = length-1; i >= 0; i--)		// I couldn't use size_t instead of int
	{
		std::cout << "\n** iteration " << length - i << " **" << std::endl;
		if(input[i] % 2 == 0)
		{
			left = input[i] / 2;
			right = left;
			if (left <= min && right >= max)
			{
				min = left;
				max = right;
				guess_list[i] = min;
				guess_list[2*length-1-i] = max;

				std::cout << ">>Guessed list : ";
				printArray(guess_list, 2*length);
			}
			else
			{	/* Change value of left & right until left less than min ...
				   & right more than max because we need ascending list */
				while(left > min || right < max)
				{
					left--;
					right++;
				}
				min = left;
				max = right;
				guess_list[i] = min;
				guess_list[2*length-1-i] = max;

				std::cout << ">>Guessed list : ";
				printArray(guess_list, 2*length);
			}

		}
		else // input[i] % 2 != 0
		{
			/* Like the previous(when input[i] is even) ...
			   only change initialize min & max */
			left = input[i] / 2;
			right = left + 1;
			if (left <= min && right >= max)
			{
				min = left;
				max = right;
				guess_list[i] = min;
				guess_list[2*length-1-i] = max;

				std::cout << ">>Guessed list : ";
				printArray(guess_list, 2*length);
			}
			else
			{
				while(left > min || right < max)
				{
					left--;
					right++;
				}
				min = left;
				max = right;
				guess_list[i] = min;
				guess_list[2*length-1-i] = max;

				std::cout << ">>Guessed list : ";
				printArray(guess_list, 2*length);
			}

			}
		}
		/* Print final guessed list */
		std::cout << "\nI guessed Initial list!!!!!!!!!!!\n\nFinal Guessed list : \n";
		printArray(guess_list, 2*length);

		/* Calculate Desired list from guessed list */
		for (size_t i = 0; i < length; i++)
		{
			desire_list[i] = guess_list[2*i] + guess_list[2*i + 1];
		}

		/* Print Desired list*/
		std::cout << "Desired list : \n";
		printArray(desire_list, length);

	return 0;
}

/* Function to print an array */
void printArray(int arr[], size_t n)
{
	for (size_t j = 0; j < n; j++)
	{
		std::cout << arr[j] << ", ";
	}
	std::cout << "\b\b " << std::endl;
}
