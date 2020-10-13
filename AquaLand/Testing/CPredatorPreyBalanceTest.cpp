#include "pch.h"
#include "CppUnitTest.h"

#include "Aquarium.h"
#include "PredatorPreyBalance.h"
#include "FishAngler.h"
#include "FishBeta.h"
#include "FishMolly.h"
#include "FishNemo.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CPredatorPreyVisitorTest)
	{
	public:
		
		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		TEST_METHOD(TestCFishBetaConstruct)
		{
			CAquarium aquarium;
			CPredatorPreyBalance visitor;
		}


	};
}
