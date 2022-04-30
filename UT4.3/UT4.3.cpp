#include "pch.h"
#include "CppUnitTest.h"
#include "../PKR4.3/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UT43
{
	TEST_CLASS(UT43)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string s1 = "s";
			fstream f1("file.txt");

			f1 << s1;


			string s2;

			fstream f2("file.txt");

			f2 >> s2;

			Assert::AreEqual(s1, s2);
		}
	};
}