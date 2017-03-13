#include <fstream>
#include "Solve.hh"
#include "Printer.hh"

using namespace std;


int main(int argc, char* argv[])
{
	char* fileName = argv[1];
	// open file 
	ifstream fh;
	Printer printer("output.txt");
	fh.open(fileName);
	if (!fh.is_open()) {
		return 1;
	}
	string buf;
	// get test case number.
	std::getline(fh, buf);
	int totalTestCaseNum = atoi(buf.c_str());

	// for each test case call solve
	for (int i = 1; i <= totalTestCaseNum; i++)
	{
		buf.clear();
		std::getline(fh,buf);
		Solve solver;
		solver.decryptInput(buf);
		printer.print(i, solver.convert());
	}
	fh.close();
	return 0;
}