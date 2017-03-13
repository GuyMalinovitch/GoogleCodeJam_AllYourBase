#pragma once
#ifndef __PRINTER_HH
#define __PRINTER_HH

class Printer
{
public:
	Printer(std::string outputFileName);
	virtual ~Printer() { stream.close(); }
	void print(int caseNum, unsigned long long num);
private:
	std::ofstream stream;
};

#endif // __PRINTER_HH