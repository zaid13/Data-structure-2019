#include "pch.h"
TEST(TestCaseName, TestName) {
	Node_ptr<int> n1(18);

	Node_ptr<int> n2(15);

	Node_ptr<int> n3(30);


	Node_ptr<int> n5(25);

	Node_ptr<int> n6(40);




	Tree<int> b;
	b.insert(n1);

	b.insert(n2);
	b.insert(n3);

	b.insert(n5);
	b.insert(n6);
	b.inorder(&n1);

	EXPECT_EQ(1, b.FullBinaryTree(&n1));

}

TEST(TestCaseName, TestName1) {
	Node_ptr<int> n1(18);

	Node_ptr<int> n2(15);

	Node_ptr<int> n3(30);


	Node_ptr<int> n5(25);

	Node_ptr<int> n6(40);




	Tree<int> b;
	b.insert(n1);

	b.insert(n2);
	b.insert(n3);

	b.insert(n5);
	b.insert(n6);
	b.inorder(&n1);

	EXPECT_EQ(0, b.Perfect(&n1));

}

TEST(TestCaseName, TestName2) {
	Node_ptr<int> n1(18);

	Node_ptr<int> n2(15);

	Node_ptr<int> n3(30);


	Node_ptr<int> n5(25);

	Node_ptr<int> n6(40);




	Tree<int> b;
	b.insert(n1);

	b.insert(n2);
	b.insert(n3);

	b.insert(n5);
	b.insert(n6);
	b.inorder(&n1);

	EXPECT_EQ(1, b.isBalanced(&n1));

}
