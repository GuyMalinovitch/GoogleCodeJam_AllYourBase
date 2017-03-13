#include "Solve.hh"
#include <string>
#include <sstream>
using namespace std;


char getCharFromNum(int num) 
{
	if (num <= 9) {
		return *std::to_string(num).c_str();
	}
	else {
		std::stringstream stream;
		stream << std::hex << num;
		return *stream.str().c_str();
	}
}

char* Solve::decrypt(char letter, int locationInWord, int& counter)
{
	MyHashI ret = letterMap.find(letter);
	if (ret == letterMap.end()) {
		switch (locationInWord) {
		case 0:
			ret = letterMap.emplace(letter, getCharFromNum(1)).first;
			break;
		default:
			if (counter == 0) {
				ret = letterMap.emplace(letter, getCharFromNum(counter += 2)).first;
			} 
			else {
				counter++;
				ret = letterMap.emplace(letter, getCharFromNum(counter)).first;
			}
			break;
		}
	}
	return &ret->second;
}


void Solve::decryptInput(string line)
{
	// go over line letter by letter/
	// fill a mapping of letter to num. 
	// call translator with mapping.

	int num = -1;
	int len = line.size();
	char nullTerminate = '\0';
	string tmp;
	for (int i = 0; i < len; i++)
	{
		tmp.insert(i,decrypt(line[i], i, num));
	}
	decryptedWord.insert(0, tmp.c_str(), len);
	_base = letterMap.size();
}

unsigned long long Solve::convert()
{
	if (_base < 2) _base = 2;
	return stoll(decryptedWord, NULL, _base);
}