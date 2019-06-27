 /*
*	AP2018 : HW1 - Question 1
*	Mohammad Mohsen Jadidi 9423029 @AUT
*/

#include <iostream>
#include <vector>

void bubbleSort(int arr[], size_t n);
void printArray(int arr[], size_t n);
bool warning(const size_t& n);

int main()
{
	std::vector<int> input{};  /* Array for getting data(bank money) from user
							    This array should be arranged */
	bool flag{true};		   // Flag for detect error in input
	int min_loan_fund{};	   // The minimum amount to be borrowed from fund

	/* Loop for get input from user */
	while (true)
	{
		int temp_input{}; 		 // Temporary varible for a value that entered by user
		std::cout << "Enter a value (0 to end) : ";
		std::cin >> temp_input;

		/* if user enter 0 , getting input is end */
		if (temp_input == 0)
			break;

		input.push_back(temp_input);
	}

	size_t length{input.size()};
	int* arr{&input[0]};	// Input of functions is array type(no vector)!

	/* Check Errors */
	flag = warning(length);
	if (flag == false)
		return 0;

	/* Print Initial array*/
	std::cout << "\nInitial array : ";
	printArray(arr, length);

	/* Call bubbleSort function to sort initial array */
    bubbleSort(arr, length);

	/* Print sorted array */
    std::cout << "Sorted array  : ";
    printArray(arr, length);

	/* Calculate minimum loan fund */
    for (size_t i = 0; i < length; i = i+2)
    {
    	min_loan_fund += arr[i+1] - arr[i];
    }

	/* Print Minimum loan fund */
    std::cout << "\nMinimum loan fund = " << min_loan_fund << std::endl;

    return 0;
}

/* Implement bubble sort */
void bubbleSort(int arr[], size_t n)
{
	int temp{};		// Temporary varible for exchange two element in the array


    if (n == 1)	/* If size of list equal to one the bubbleSort algorithm is end */
        return;

    /* the largest element is moved to
       end after ever itearation   */
    for (size_t i = 0; i < n-1; i++)
        if (arr[i] > arr[i+1])
        {
        	temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }

    /* recursive remaining array */
    bubbleSort(arr, n-1);
}

/* Function to print an array */
void printArray(int arr[], size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		std::cout << arr[i] << ", ";
	}
	std::cout << "\b\b " << std::endl;
}

/* Function to check errors */
bool warning(const size_t& n)
{
	if (n == 0)	//Input not entered
	{
		std::cout << ">> Warning : I don't have any input" << std::endl;
		return false;
	}

	if (n % 2 == 1)	// Number of Input is odd
	{
		std::cout << ">> Warning : Number of input is odd" << std::endl;
		return false;
	}

	return true;
}
