/*
*	AP2018 : HW1 - Question 3
*	Mohammad Mohsen Jadidi 9423029 @AUT
*/

#include <iostream>
#include <vector>
#include <cmath>

double func(double&, std::vector<double>, int);
double secant(double&, double&, double&, std::vector<double>, int);
double error(double&, double& );

int main(int argc, char* argv[])
{
	std::vector<double> coff;	// Array for store coffiecients of polynomial
	int deg{};					// Degree of polynomial
	double x1{}, x2{}, eps{};	// x1, x2 : Two initial values , eps : The minimum error value
	double root{};				// Guessed root of polynomial

	/* Obtaining coffiecients of polynomial from argv */
	for (int i = 1; i < argc; i++)
	{
		coff.push_back(std::atof(argv[i]));
	}

	/* Calculate degree of polynomial */
	deg = (coff.size() - 1);

	/* Print polynomial */
	std::cout << "f(x) = ";
	for (size_t i = 0; i < coff.size(); i++) 	// Loop for ptint f(x)
	{
		std::cout << coff[i] << "x^" << deg-i << " + ";
	}
	std::cout <<"\b\b\b\b\b\b      " << std::endl;

	/* Print Two initial values & minimum error */
	std::cout << "Enter 1st initial guess  : ";
	std::cin >> x1;
	std::cout << "Enter 2st initial guess  : ";
	std::cin >> x2;
	std::cout << "Enter epsilon  : ";
	std::cin >> eps;

	/* Call secant function & Calculate root of polynomial that between two initial values */
	root = secant(x1, x2, eps, coff, deg);

	/* Print Guessed root of polynomial*/
	std::cout << "\n==> Final answer = " << root << std::endl;

	return 0;
}

/* Function to Evalute f(x) at x*/
double func(double& x, std::vector<double> coff, int deg)
{
	double fx{};			// Value of polynomial at x
	for (int i = 0; i < deg+1 ; i++)
		fx += coff[i]*pow(x, deg-i);

	return fx;
}

/* Function that performs the secant method to Calculate root of polynomial*/
double secant(double& x1, double& x2, double& eps, std::vector<double> coff, int deg)
{
	double root;				// Variable for Guessed root
	double x_new{x2} ,x_old{x1};// x_new is xn & x_old is xn-1 in the secant formula
	double fx_new{}, fx_old{};	// fx_new is f(xn) & fx_old is f(xn-1) in the secant formula
	double err;					// Value of error that equal to (x_new - x_old) / x_old
	int level{0};				// Counter for loop

 	/* Loop  for calculate xn+1 from xn, xn-1*/
	do
	{
		std::cout << "\n********* Level " << level++ << " **********";
		std::cout << "\nx_old = " << x_old;
		std::cout << "\nx_new = " << x_new;

		fx_new = func(x_new, coff, deg);
		fx_old = func(x_old, coff, deg);

		std::cout << "\nfx_new = " << fx_new;

		/* Error Calculation */
		err = error(x_new, x_old);
		std::cout << "\nError = " << err << std::endl;

		/* Secant Formula */
		root = x_new - ( (fx_new * (x_new - x_old)) / (fx_new - fx_old) );

		x_old = x_new;
		x_new = root;

	}
	while( err > eps);

	return root;
}

/* Function to Error Calculation*/
double error(double& x1, double& x2)
{
	double e{};		// Varible for error value

	if(x2 != 0)
		e = std::abs((x1 - x2) / x2);
	else if(x1 != 0)
		e = std::abs( (x1 - x2) / x1 );
	else
		e = 0;

	return e;
}
