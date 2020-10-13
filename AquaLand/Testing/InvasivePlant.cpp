#include "pch.h"
#include "CppUnitTest.h"
#include "InvasivePlant.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(InvasivePlant)
	{
	public:
		
		TEST_METHOD(TestNothing)
		{
			// This is an empty test just to ensure the system is working
		}

		TEST_METHOD(TestInvasive)
		{
			

			CInvasivePlant aInv(L"mixed", L"This plant gets along with some.");

			std::wstring descr = aInv.DisplayDescription();
			Assert::IsTrue(L"mixed: This plant gets along with some. [invasive]" == descr);

			std::wstring incomps = aInv.DisplayIncompatible();
			Assert::IsTrue(L"All" == incomps);

		}

	};
}