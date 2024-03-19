#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_OOP_1.8/Lab.cpp"
#include "../Lab_OOP_1.8/Fraction.h"
#include "../Lab_OOP_1.8/Fraction.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLAB18
{
	TEST_CLASS(UnitTestLAB18)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Fraction frac1;
			frac1.setWhole(Fraction::DigitString("987"));
			frac1.setFrac(65);

			Fraction frac2;
			frac2.setWhole(Fraction::DigitString("654"));
			frac2.setFrac(32);

			Fraction result = frac1 - frac2;

			Assert::AreEqual("333", result.getWhole().getDigits().c_str());
			Assert::IsTrue(33);

		}
	};
}
