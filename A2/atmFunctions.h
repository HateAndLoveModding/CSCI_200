#ifndef ATM_FUNCTIONS_H
#define ATM_FUNCTIONS_H

 /**
  * @brief Handles the main function of the ATM.
  * 
  */
void start_atm();

/**
 * @brief Displays the ATM menu to the user.
 * 
 */
void print_menu();

/**
 * @brief Gets the user's selection from the ATM menu.
 * 
 * @return char User's choice.
 */
char get_user_selection();

/**
 * @brief Prints the current balance of the ATM account.
 * 
 * @param dollars Number of dollars in the account.
 * @param cents Number of cents in the account.
 */
void print_balance(int dollars, int cents);

/**
 * @brief Prompts the user to enter an amount in dollars for a deposit or withdrawal.
 * 
 * @param isDeposit True if the transaction is a deposit, false if a withdrawal.
 * @return int The amount in dollars entered by the user, or -1 if invalid input.
 */
int get_dollars(bool isDeposit);

/**
 * @brief Prompts the user to enter an amount in cents for a deposit or withdrawal, and adjusts dollars if needed.
 * 
 * @param modDollars Reference to the variable holding the number of dollars, adjusted if cents exceed 99.
 * @param isDeposit True if the transaction is a deposit, false if a withdrawal.
 * @return int The amount in cents entered by the user, or -1 if invalid input.
 */
int get_cents(int& modDollars, bool isDeposit);

/**
 * @brief Updates the user's balance based on a deposit or withdrawal.
 * 
 * @param dollars Reference to the current dollar amount in the account.
 * @param cents Reference to the current cents amount in the account.
 * @param modDollars The dollar amount of the deposit or withdrawal.
 * @param modCents The cents amount of the deposit or withdrawal.
 * @param isDeposit True if the transaction is a deposit, false if a withdrawal.
 */
void update_balance(int& dollars, int& cents, int modDollars, int modCents, bool isDeposit);

/**
 * @brief Handles the process of depositing money into the account.
 * 
 * @param dollars Reference to the current dollar amount in the account.
 * @param cents Reference to the current cents amount in the account.
 */
void deposit_money(int& dollars, int& cents);

/**
 * @brief Handles the process of withdrawing money from the account.
 * 
 * @param dollars Reference to the current dollar amount in the account.
 * @param cents Reference to the current cents amount in the account.
 */
void withdraw_money(int& dollars, int& cents);

#endif