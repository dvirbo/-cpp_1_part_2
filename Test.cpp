/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 *
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <dvir borochov>
 *
 * Date: 2021-02
 */

// #define CHECK_THROWS DOCTEST_CHECK_THROWS CHECK
// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "mat.hpp"
#include <algorithm>
#include <string>
#include <iostream>

using namespace ariel;
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 * check_validity
 */
string nospaces(string input)
{
	erase(input, ' ');
	erase(input, '\t');
	erase(input, '\n');
	erase(input, '\r');
	return input;
}

string cval(int col, int row, char a, char b)
{
    string ans = "Good input";

    if (col % 2 == 0 || row % 2 == 0)
    {
        return "Mat size is always odd";
    }

    if (col < 0)
    {
        return "column num is negetive-must be positive";
    }

    if (row < 0){
        return "row num is negetive-must be positive";
    }
    return ans;
}
string check_input(int col, int row, char a, char b){
	string ans = cval(col, row, a, b);
	if(ans == "Good input"){
		return "Good input";
	}
	return ans;
}

TEST_CASE("Good input - Comparison")
{

	CHECK(nospaces(mat(9, 7, '@', '-'))=="@@@@@@@@@@-------@@-@@@@@-@@-@---@-@@-@@@@@-@@-------@@@@@@@@@@");
	CHECK(nospaces(mat(3, 5, '@', '-')) == "@@@@-@@-@@-@@@@");
	CHECK(nospaces(mat(13, 5, '@', '-')) == "@@@@@@@@@@@@@@-----------@@-@@@@@@@@@-@@-----------@@@@@@@@@@@@@@");
	CHECK(nospaces(mat(1, 1, '@', '-')) == "@");
	CHECK(nospaces(mat(3, 3, '@', '-')) == "@@@@-@@@@");
	CHECK(nospaces(mat(3, 3, '*', '-')) == "****-****");
	CHECK(nospaces(mat(3, 3, '!', '-')) == "!!!!-!!!!");



}

TEST_CASE("Bad input and the error that they have")
{
	CHECK_THROWS(mat(10, 5, '$', '%')); // "Mat size is always odd"
	CHECK_THROWS(mat(3, 6, '$', '%'));	// "Mat size is always odd"
	CHECK_THROWS(mat(3, -5, '@', '-')); // "row num is negetive-must be positive"
	CHECK_THROWS(mat(-3, 5, '@', '-')); // "column num is negetive-must be positive"
	CHECK_THROWS(mat(0, 5, '@', '-'));	// "Mat size is always odd"
	CHECK_THROWS(mat(3, 0, '@', '-'));	// "Mat size is always odd"
}


TEST_CASE("compare false message")
{
	string a = "Mat size is always odd";
	string c = "column num is negetive-must be positive";
	string d = "row num is negetive-must be positive";

		CHECK_EQ(a,check_input(10, 5, '$', '%'));
		CHECK_EQ(a,check_input(2, 5, '$', '%'));
		CHECK_EQ(a,check_input(10, 5, '$', '%'));
		CHECK_EQ(a,check_input(3, 2, '$', '%'));
		CHECK_EQ(c,check_input(-1, 5, '$', '%'));
		CHECK_EQ(d,check_input(3, -5, '$', '%'));
		CHECK_NE(a,check_input(3, 5, '@', '-'));
	
}



