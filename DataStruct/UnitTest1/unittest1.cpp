#include "stdafx.h"
#include "CppUnitTest.h"
#include "../DataStruct/LinearL.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(LinkListTest)
		{
			LinkList head = InitLinkList();
			PrintLinkList(head);
			InsertLinkList(head, 11, 1);
			InsertLinkList(head, 12, 2);
			InsertLinkList(head, 13, 3);
			InsertLinkList(head, 14, 4);
			InsertLinkList(head, 15, 5);
			PrintLinkList(head);

			InsertLinkList(head, 23, 3);
			PrintLinkList(head);
			InsertLinkList(head, 17, 7);
			PrintLinkList(head);
			Assert::AreEqual(LocateLinkList(head, 23), 3);
			Assert::AreEqual(LengthLinkList(head), 7);
			DeleteLinkList(head, 5);
			Assert::AreEqual(LengthLinkList(head), 6);
		}

	};
}