/******************************************************
 *  Argparse example for reading command line arguments.
 *  This is a simple template example to simplify the
 *  Command Line reading arguments. 
 *
 *  Author: Jimmy Aguilar Mena
 *  June 6, 2018
 *
 *  This is under GPL license.
 *****************************************************/

#include <CommandLine.hpp>

int main(int argc, char **argv)
{
	CommandLine::initialize(argc, argv);

	Argument<int> a("a");
	Argument<std::string> b("b");
	DEFARG(double, a2);

	Argument<int> c("c", 0);
	Argument<std::string> d("d","value_a");
	DEFARGOPT(double, c2, 3);

	CommandLine::print();

	return 0;
}
