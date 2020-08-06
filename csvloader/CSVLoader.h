#pragma once
#include <vector>

class CSVLoader
{
public:
	CSVLoader(const char* path, const char separator = ',', bool ignoreFirstRow = false);

	std::vector<const char*>& operator[](size_t i);

	size_t Rows();
	size_t Columns();

	std::vector<std::vector<const char*> > Data;
	std::vector<char> RawData;
};

