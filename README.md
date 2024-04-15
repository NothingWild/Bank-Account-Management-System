# Bank-Account-Management-System
Bank Account Management System with fast transfer

### Allows individual customers to create and manage a bank account as well as deposit, withdraw, and transfer, providing a reusable and modular bank account management system. Demonstrates object-oriented programming concepts such as Abstraction, Encapsulation, Data Hiding, and Information Hiding by using constructors and member functions.

Here's a breakdown of what the program does:

    1. User Interface: The program provides a menu-driven interface that allows users to perform various banking operations.

    2. Account Management:
        a. Opening a New Account: Users can open a new bank account by providing their full name and an initial deposit amount.
        b. Depositing into Account: Users can deposit funds into an existing account by specifying the account number and the deposit amount.
        c. Withdrawing from Account: Users can withdraw funds from an existing account by specifying the account number, the account holder's name, and the withdrawal amount.
        d. Fast Transfer: Users can perform a fast transfer of $40 from one account to another by specifying the source and destination account numbers.
        e. Printing a List of All Accounts: Users can view a formatted list of all existing accounts, including the account number, account holder's name, and balance.

    3. Error Handling: The program handles various error conditions, such as invalid menu options, incorrect account numbers, insufficient funds for withdrawals, and non-existent accounts.

    4. Data Persistence: While the program does not persist data beyond the runtime of the program (i.e., it doesn't save data to a file), it maintains account information in memory using a vector of Account objects.

    5. Clean Exit: The program allows users to terminate the program gracefully by selecting the "End transaction (Exit)" option from the menu.

Overall, the program provides a basic yet functional interface for managing bank accounts, allowing users to perform common banking operations such as opening accounts, depositing and withdrawing funds, transferring funds between accounts, and viewing account information.
