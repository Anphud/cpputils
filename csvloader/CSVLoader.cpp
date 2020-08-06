// Simple CSV Loader
// An Phu Dupont (c) 2020

#include "CSVLoader.h"
#include <algorithm>
#include <fstream>

CSVLoader::CSVLoader(const char* path, const char separator, bool ignoreFirstRow)
{
	std::ifstream infile(path, std::ios_base::binary);
	RawData = std::vector<char>((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());

	size_t columns = 0;
	const char* current_ptr = RawData.data();
	std::vector<const char*> current_row;
	for (size_t i = 0; i < RawData.size(); ++i)
	{
		if (RawData[i] == '\r')
		{
			RawData[i] = NULL;
			continue;
		}

		if (RawData[i] == separator || RawData[i] == '\n')
		{
			if (!ignoreFirstRow)
			{
				current_row.push_back(current_ptr);
				current_ptr = RawData.data() + i + 1;
			}

			if (RawData[i] == '\n')
			{
				Data.push_back(current_row);
				current_row.clear();
				ignoreFirstRow = false;
			}

			RawData[i] = NULL;
		}
	}

	infile.close();
}

std::vector<const char*>& CSVLoader::operator[](size_t i)
{
	return Data[i];
}

size_t CSVLoader::Rows()
{
	return Data.size();
}

size_t CSVLoader::Columns()
{
	return (Data.size() > 0) ? Data.front().size() : 0;
}