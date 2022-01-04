// https://google.github.io/googletest/primer.html

#include <iostream>
#include <gtest/gtest.h>

class BankAccount{
	int balance;
public:
	BankAccount(): balance(0){

	}

	explicit BankAccount(const int balance)
		: balance(balance){

	}
	int getBalance(){
		return this->balance;
	}
};

// Creating a TestSuite
TEST(AccountTest, BankAccountStartsEmpty){
	/* Arg: 
	AccountTest: TestSuite Name
	BankAccountStartsEmpty: Test Name
	*/
	BankAccount account;
	EXPECT_EQ(0, account.getBalance());
}

// Creating a Test fixture.
// For this we have to define a fixture class.
class BankAccountTest : public ::testing::Test {
protected:
	void SetUp() override {
		account = BankAccount(100);
	}

	void TearDown() override {

	}
	BankAccount account;
};

TEST_F(BankAccountTest, BankAccountFilled){
	EXPECT_EQ(100, account.getBalance());

	EXPECT_EQ(99, account.getBalance())<<"FAILURE IS EXPECTED\n";
}

int main(int argc, char** argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}