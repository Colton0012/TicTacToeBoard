/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/
// TEST(PracticeTest, is_not_simple_palindrome)
// {
//     Practice obj;
//     bool actual = obj.isPalindrome("Not a palindrome");
//     ASSERT_FALSE(actual);
// }

TEST(TicTacToeBoardTest, toggleTurnX)
{
	TicTacToeBoard obj;
	obj.toggleTurn();
	ASSERT_EQ(obj.toggleTurn(), X);
}

TEST(TicTacToeBoardTest, toggleTurnXtoO)
{
	TicTacToeBoard obj;
	ASSERT_EQ(obj.toggleTurn(), O);
}

TEST(TicTacToeBoardTest, Constructor)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	ASSERT_EQ(obj.getPiece(0,0), X);
}

TEST(TicTacToeBoardTest, Place2nd)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	obj.placePiece(0,1);
	ASSERT_EQ(obj.getPiece(0,1),O);
}

TEST(TicTacToeBoardTest, PlaceOutOfBounds)
{
	TicTacToeBoard obj;
	ASSERT_EQ(obj.placePiece(4,-1),Invalid);
}

TEST(TicTacToeBoardTest, PlaceAlreadyTaken)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	ASSERT_EQ(obj.placePiece(0,0),X);
}

TEST(TicTacToeBoardTest, GetBlank)
{
	TicTacToeBoard obj;
	ASSERT_EQ(obj.getPiece(2,2),Blank);
}

TEST(TicTacToeBoardTest, GetOutOfBounds)
{
	TicTacToeBoard obj;
	ASSERT_EQ(obj.getPiece(4,3),Invalid);
}

TEST(TicTacToeBoardTest, GetGood)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	ASSERT_EQ(obj.getPiece(0,0),X);
}

TEST(TicTacToeBoardTest, WinnerHorizontal)
{
	TicTacToeBoard obj;
	obj.placePiece(1,0);
	obj.toggleTurn();
	obj.placePiece(1,1);
	obj.toggleTurn();
	obj.placePiece(1,2);
	ASSERT_EQ(obj.getWinner(),X);
}

TEST(TicTacToeBoardTest, WinnerVerticle)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	obj.toggleTurn();
	obj.placePiece(1,0);
	obj.toggleTurn();
	obj.placePiece(2,0);
	ASSERT_EQ(obj.getWinner(),X);
}

TEST(TicTacToeBoardTest, WinnerDiagonal)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	obj.toggleTurn();
	obj.placePiece(1,1);
	obj.toggleTurn();
	obj.placePiece(2,2);
	ASSERT_EQ(obj.getWinner(),X);
}

TEST(TicTacToeBoardTest, WinnerNone)
{
	TicTacToeBoard obj;
	ASSERT_EQ(obj.getWinner(),Invalid);
}

TEST(TicTacToeBoardTest, WinnerTie)
{
	TicTacToeBoard obj;
	//x
	obj.placePiece(0,0);
	//O
	obj.placePiece(0,1);
	obj.toggleTurn();
	//O
	obj.placePiece(0,2);
	//O
	obj.toggleTurn();
	obj.placePiece(1,0);
	//x
	obj.placePiece(1,1);
	//x
	obj.toggleTurn();
	obj.placePiece(1,2);
	//x
	obj.placePiece(2,0);
	//O
	obj.placePiece(2,1);
	//O
	obj.placePiece(2,2);
	ASSERT_EQ(obj.getWinner(),Blank);
}