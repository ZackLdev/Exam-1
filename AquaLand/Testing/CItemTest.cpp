#include "pch.h"
#include "CppUnitTest.h"
#include "Aquarium.h"
#include "Item.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	/** Mock class for testing CItem */
	class CItemMock : public CItem
	{
	public:
		CItemMock(CAquarium* aquarium) : CItem(aquarium) {}

		virtual void Draw(Gdiplus::Graphics* graphics) {}
		virtual bool HitTest(int x, int y) { return false; }

	};

	TEST_CLASS(CItemTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestNothing)
		{
			CAquarium aquarium;
			CItemMock item(&aquarium);
		}

		TEST_METHOD(TestCItemGettersSetters)
		{
			// Construct an item to test
			CAquarium aquarium;
			CItemMock item(&aquarium);

			// Test initial values
			Assert::AreEqual(0, item.GetX(), 0);
			Assert::AreEqual(0, item.GetY(), 0);

			// Test SetLocation, GetX, and GetY
			item.SetLocation(10.5, 17.2);
			Assert::AreEqual(10.5, item.GetX(), 0.0001);
			Assert::AreEqual(17.2, item.GetY(), 0.0001);

			// Test a second with with different values
			item.SetLocation(-72, -107);
			Assert::AreEqual(-72, item.GetX(), 0.0001);
			Assert::AreEqual(-107, item.GetY(), 0.0001);
		}

        TEST_METHOD(TestCItemDistance)
        {
            // Create an aquarium and two items
            CAquarium aquarium;
            shared_ptr<CItemMock> item1 = make_shared<CItemMock>(&aquarium);
            shared_ptr<CItemMock> item2 = make_shared<CItemMock>(&aquarium);

            item1->SetLocation(10.5, 17.2);
            item2->SetLocation(53.1, 107.8);
            
            Assert::AreEqual(100.1155, item1->Distance(item2), 0.0001);
        }
	};
}