#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Printer.hh"
using namespace std;

Printer::Printer(string outputFileName)
{
	stream.open(outputFileName);
}

void Printer::print(int caseNum, unsigned long long num)
{
	ostringstream buf;
	buf << "Case #" << caseNum << ": " << num;
	cout << buf.str() << endl;
	stream << buf.str() << endl;
}