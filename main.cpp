/***************************************************
 * Argparse example for reading command line arguments.  This is a simple
 * template to simplify the Command Line arguments reading.
 *
 * This file is part of the ArgParseCpp distribution Copyright (c) 2015 Jimmy
 * Aguilar Mena.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
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
