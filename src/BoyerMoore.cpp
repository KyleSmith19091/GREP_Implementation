#include "../include/BoyerMoore.hpp"

int Grep::BoyerMoore::badMatchTable[NUM_OF_CHARS];

void Grep::BoyerMoore::constructBadMatchTable(const std::string &pattern)
{
	int patternLength = pattern.length();
	for (int i = 0; i < patternLength; i++)
	{
    	badMatchTable[static_cast<int>(pattern[i])] = calaculateMaxShift(patternLength, i);
	}
}

std::vector<size_t> Grep::BoyerMoore::match(const std::string& pattern, const std::string& text)
{
    constructBadMatchTable(pattern);

	size_t textLength = text.length();
	size_t patternLength = pattern.length();
	size_t skips = 0;

	std::vector<size_t> matchedIndices;

	for (int i = 0; i <= textLength - patternLength; i += skips)
	{
		skips = 0;

		for (int j = patternLength - 1; j >= 0; j--)
		{
			if (pattern[j] != text[i + j])
			{
				if (badMatchTable[static_cast<int>(text[i + j])])
				{
					skips = badMatchTable[static_cast<int>(text[i + j])];
					break;
				}
				else
				{
					skips = patternLength;
					break;
				}
			}
		}

		if (skips == 0)
		{ // Found a match
			matchedIndices.push_back(i++);
		}
	}

	return matchedIndices;
}
