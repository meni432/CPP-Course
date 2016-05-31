#include "MyLinkedList.hpp"
#include "gtest/gtest.h"
#include <string>
using namespace std;

// remark: all testers rely on parameterless constructor, operator== or/and operator!=, size

TEST(MyLinkedList, emptyListTesters) {

	MyLinkedList mylist;
	MyLinkedList mylist2;
	EXPECT_EQ(0, mylist.size());
	EXPECT_EQ(0, mylist2.size());
	EXPECT_EQ(mylist, mylist2);

}

TEST(MyLinkedList, addIsInListArrCtorTesters) {

	MyLinkedList mylist;
	string firstKey= "aa";
	double firstVal= 1.5;
	string secondKey = "bb";
	double secondVal = 2.2;

	mylist.add(firstKey, firstVal);

	EXPECT_EQ(1, mylist.size());

	EXPECT_TRUE(mylist.isInList(firstKey, firstVal));
	EXPECT_FALSE(mylist.isInList(firstKey, secondVal));
	EXPECT_FALSE(mylist.isInList(secondKey, firstVal));
	EXPECT_FALSE(mylist.isInList(secondKey, secondVal));

	string keysArr[]= {firstKey};
	double valsArr[]= {firstVal};
	MyLinkedList mylist2( keysArr, valsArr, 1);
	EXPECT_EQ(mylist2, mylist);

	mylist.add(secondKey, secondVal);
	EXPECT_TRUE(mylist.isInList(firstKey, firstVal));
	EXPECT_TRUE(mylist.isInList(secondKey, secondVal));
	EXPECT_FALSE(mylist2.isInList(secondKey, secondVal));
	EXPECT_NE(mylist2, mylist);

}


// check copy constructor
TEST(MyLinkedList, copyConstructorTester) {
	string firstKey= "aa";
	double firstVal= 1.5;
	string secondKey = "bb";
	double secondVal = 2.2;

	string keysArr[]= {firstKey, secondKey};
	double valsArr[]= {firstVal, secondVal};

	MyLinkedList mylist(keysArr, valsArr, 2);

	MyLinkedList myCopyList(mylist);

	EXPECT_TRUE(mylist == myCopyList);

}

// MyLinkedList& operator=(const MyLinkedList& other);
// check '=' operator
TEST(MyLinkedList, operatorEqualTesters) {
	string firstKey= "aa";
	double firstVal= 1.5;
	string secondKey = "bb";
	double secondVal = 2.2;

	string keysArr[]= {firstKey, secondKey};
	double valsArr[]= {firstVal, secondVal};

	MyLinkedList mylist(keysArr, valsArr, 2);

	EXPECT_TRUE(mylist.isInList(firstKey, firstVal));
	EXPECT_TRUE(mylist.isInList(secondKey, secondVal));

	MyLinkedList mylist2;

	mylist2 = mylist;

	EXPECT_TRUE(mylist2.isInList(firstKey, firstVal));
	EXPECT_TRUE(mylist2.isInList(secondKey, secondVal));

}

// size_t remove(string str);
// check remove function
TEST(MyLinkedList, removeTesters) {
	MyLinkedList mylist;

	// check empty key delete (when it contain, and when it dosen't)
	string emptyKey = "";
	double emptyVal = 0;

	EXPECT_EQ(0, mylist.remove(emptyKey));
	mylist.add(emptyKey,emptyVal);
	EXPECT_EQ(1, mylist.remove(""));

	EXPECT_EQ(0, mylist.size());

	// check single and multiplay Values delete
	string firstKey= "aa";
	double firstVal= 1.5;
	string secondKey = "bb";
	double secondVal = 2.2;
	double thirdVal = 3.3;

	// add multiplay val on same key
	mylist.add(firstKey, firstVal);
	mylist.add(secondKey, secondVal);
	mylist.add(secondKey, thirdVal);

	EXPECT_EQ(3, mylist.size());

	// check single (key, val)
	EXPECT_EQ(1, mylist.remove(firstKey));
	EXPECT_EQ(2, mylist.size());
	EXPECT_FALSE(mylist.isInList(firstKey, firstVal));

	// check multiplay delete (key, val1) (key, val2)
	EXPECT_EQ(2, mylist.remove(secondKey));
	EXPECT_EQ(0, mylist.size());
	EXPECT_FALSE(mylist.isInList(secondKey, secondVal));
	EXPECT_FALSE(mylist.isInList(secondKey, thirdVal));
}

// double sumList() const;
// check sum list function
TEST(MyLinkedList, sumListTesters) {
	string firstKey= "aa";
	double firstVal= 1;
	string secondKey = "bb";
	double secondVal = 2;
	string thirdKey = "cc";
	double thirdVal = 3;


	string keysArr[]= {firstKey, secondKey, thirdKey};
	double valsArr[]= {firstVal, secondVal, thirdVal};

	MyLinkedList mylist(keysArr, valsArr, 3);

	EXPECT_EQ(6, mylist.sumList());

	// real sum test
	mylist.add("dd", -3.5);

	EXPECT_EQ(2.5, mylist.sumList());

	// negative sum test
	mylist.add("ee", -3.5);

	EXPECT_EQ(-1, mylist.sumList());

}

// bool operator==(const MyLinkedList& other) const;
// bool operator!=(const MyLinkedList& other) const;
// check operator test
TEST(MyLinkedList, OperatorTesters) {

	string firstKey= "aa";
	double firstVal= 1.5;
	string secondKey = "bb";
	double secondVal = 2.2;
	double thirdVal = 3.3;

	string keysArr[]= {firstKey, secondKey};
	double valsArr[]= {firstVal, secondVal};

	// naive test, same initialize
	MyLinkedList mylist1(keysArr, valsArr, 2);
	MyLinkedList mylist2(keysArr, valsArr, 2);

	EXPECT_TRUE(mylist1 == mylist2);
	EXPECT_FALSE(mylist1 != mylist2);

	EXPECT_EQ(1, mylist1.remove(firstKey));

	EXPECT_FALSE(mylist1 == mylist2);
	EXPECT_TRUE(mylist1 != mylist2);

	// check order equals (currently not in order)
	mylist1.add(firstKey, firstVal);

	EXPECT_FALSE(mylist1 == mylist2);
	EXPECT_TRUE(mylist1 != mylist2);

	// check after change (currently in order, only one value)
	EXPECT_EQ(1, mylist1.remove(secondKey));
	EXPECT_EQ(1, mylist2.remove(secondKey));

	EXPECT_TRUE(mylist1 == mylist2);
	EXPECT_FALSE(mylist1 != mylist2);

	// check multiplay val on key equals
	mylist1.add(firstKey, thirdVal);

	EXPECT_FALSE(mylist1 == mylist2);
	EXPECT_TRUE(mylist1 != mylist2);

}


TEST(MyLinkedList, privateTest1) {
	// to test private methods of MyLinkedList here, you'll need
	// to add to the MyLinkedList this line:
	//  FRIEND_TEST(MyLinkedList, privateTest1);
	// This is not a requirement (you can get 100 without it)
}

// add more tests here!
