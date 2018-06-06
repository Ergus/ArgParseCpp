/******************************************************
 *  Argparse header for reading command line arguments.
 *  This is a simple template to simplify the
 *  Command Line arguments reading.
 *
 *  Author: Jimmy Aguilar Mena
 *  June 6, 2018
 *
 *  This is under GPL license.
 *****************************************************/

#ifndef COMMANDLINE_HPP
#define COMMANDLINE_HPP

#include <sstream>
#include <iostream>
#include <string>
#include <list>
#include <typeinfo>

using namespace std;

class Node {
	protected:
		const string _name;

	public:
		Node(string name):
			_name(name)
		{}

		string getName() const {return _name; };
		virtual string toStream() = 0;
};

template<typename T>
class Argument;

class CommandLine {
	private:
		class Singleton {
			public:
				const int _argc;
				char **_argv;
				int _currentIndex, _mandatory, _optional;
				int _instances;

				list<Node *> _list;

				Singleton(int argc, char **argv) :
					_argc(argc), _argv(argv), _currentIndex(1),
					_mandatory(0), _optional(0), _instances(0),
					_list()
				{}

				Singleton() = delete;
		};

		static Singleton *s;

		template<typename T>
		friend class Argument;

	public:
		static void initialize(const int argc=-1, char **argv = nullptr)
		{
			if (!s)
				s = new Singleton(argc, argv);

			s->_instances++;
		}

		static void append(Node *in) { s->_list.push_back(in); }

		static void print()
		{
			for(auto i = s->_list.begin(); i != s->_list.end(); ++i)
				cout << (*i)->toStream() << endl;
		}
};

CommandLine::Singleton *CommandLine::s = nullptr;

template<typename T>
class Argument : public Node {

	public:
		Argument(string name) :
			Node(name), optional(false)
		{
			if (CommandLine::s->_optional > 0) {
				cerr << "Optional parameters after mandatory." << endl;
				abort();
			}

			const int index = CommandLine::s->_currentIndex++;
			CommandLine::s->_mandatory++;

			if (CommandLine::s->_currentIndex <=
			    CommandLine::s->_argc) {
				_internal = fromStr(CommandLine::s->_argv[index]);
			} else {
				cerr << "Missing parameter No: " << index
				     << " : " << name << " type: " << typeid(T).name()
				     << ""
				     << endl;
				abort();
			}

			CommandLine::append(this);
		}

		Argument(string name, T defvalue) :
			Node(name), optional(true)
		{
			const int index = CommandLine::s->_currentIndex++;

			if (index < CommandLine::s->_argc) {

				CommandLine::s->_optional++;

				_internal = fromStr(CommandLine::s->_argv[index]);
			} else {
				_internal = defvalue;
			}

			CommandLine::append(this);
		}

		inline operator T() const { return _internal; };

		// Generate a printable stream object
		string toStream()
		{
			string ret;

			if (optional)
				ret += " [" + _name + "]";
			else
				ret += " " + _name;

			ret += " : " + toStr(_internal);
			return ret;
		}

	private:
		T _internal;
		const bool optional;

		T fromStr(char *argument)
		{
			stringstream ss;
			T ret;

			ss << argument;
			ss >> ret;
			return ret;
		}

		string toStr(T in)
		{
			ostringstream ss;
			ss << in;
			return ss.str();
		}
};


// If you prefer to use macros (recommended)
#define DEFARG(TYPE, VAR) Argument<int> VAR(#VAR)
#define DEFARGOPT(TYPE, VAR, VALUE) Argument<int> VAR(#VAR, VALUE)

#endif //COMMANDLINE_HPP
