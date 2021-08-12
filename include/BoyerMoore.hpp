#ifndef BOYERMOORE_HPP
#define BOYERMOORE_HPP

#include <string>
#include <vector>

namespace Grep
{
	class BoyerMoore
	{
	private:
		constexpr const static unsigned int NUM_OF_CHARS = 256;
		static int badMatchTable[NUM_OF_CHARS];

		constexpr const static int calaculateMaxShift(const int &length, const int &idx) noexcept
		{
			return calcMax(1, length - idx - 1);
		}

		constexpr const static int calcMax(const int &a, const int &b) noexcept
		{
			return a > b ? a : b;
		}

		static void constructBadMatchTable(const std::string&);

	public:
		static std::vector<size_t> match(const std::string &, const std::string &);
	};
};

#endif
