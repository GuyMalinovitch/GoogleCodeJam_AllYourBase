#pragma once
#ifndef __SOLVE_HH
#define __SOLVE_HH

#include <unordered_map>
#include <string>
typedef std::unordered_map<char, char> MyHash;
typedef std::unordered_map<char, char>::iterator MyHashI;

class Solve
{
public:
	Solve() {}
	virtual ~Solve() {}
	void decryptInput(std::string line);
	unsigned long long convert();
private:
	char* decrypt(char letter,int locationInWord, int& counter);
private:
	int _base;
	MyHash letterMap;
	std::string decryptedWord;
};

#endif // __SOLVE_HH