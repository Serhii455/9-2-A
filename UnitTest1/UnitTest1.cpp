#include "pch.h"
#include "CppUnitTest.h"
#include "../Pr/9.2_A.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int N = 3;
			Student students[N];

			students[0] = { "Smith", 1, Computer_Science, 90, 85, 95 };
			students[1] = { "Johnson", 3, Philology, 85, 88, 92 };
			students[2] = { "Whilliams", 3, Philology, 78, 90, 80 };

			Assert::AreEqual(BinSearch(students, N, "Johnson", Philology, 92), 1);
		}
	};
}
