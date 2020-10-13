#include "pch.h"
#include "CppUnitTest.h"

#include "Plant.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
    TEST_CLASS(PlantsTest)
    {
    public:

        TEST_METHOD_INITIALIZE(methodName)
        {
            extern wchar_t g_dir[];
            ::SetCurrentDirectory(g_dir);
        }
        
        TEST_METHOD(TestPlantBenign)
        {
            CPlant benignPlant(L"benign", L"This plant gets along with everybody.");

            std::wstring descr = benignPlant.DisplayDescription();
            Assert::IsTrue(L"benign: This plant gets along with everybody." == descr);

            std::wstring incomps = benignPlant.DisplayIncompatible();
            Assert::IsTrue(L"" == incomps);
        }


        TEST_METHOD(TestPlantWIncompatable)
        {
            CPlant aPlant(L"mixed", L"This plant gets along with some.");
            aPlant.AddIncompatibleFish(L"OneFish");
            aPlant.AddIncompatibleFish(L"TwoFish");
            aPlant.AddIncompatibleFish(L"RedFish");
            aPlant.AddIncompatibleFish(L"BlueFish");

            std::wstring descr = aPlant.DisplayDescription();
            Assert::IsTrue(L"mixed: This plant gets along with some." == descr);

            std::wstring incomps = aPlant.DisplayIncompatible();
            Assert::IsTrue(L"OneFish TwoFish RedFish BlueFish " == incomps);
        }

    };
}