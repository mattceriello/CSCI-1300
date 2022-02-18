// CS1300 Spring 2019
// Author: my name
// Recitation: 123 – Favorite TA
// Cloud9 Workspace Editor Link: https://ide.c9.io/…
// Project 2

#include "Library.h"
#include "Library.cpp"


#include <iostream>
using namespace std;


//////////////////////////////////////////////////////////////////////////////////
// -- book class
//////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////
// -- user class
//////////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////////
// -- library class
//////////////////////////////////////////////////////////////////////////////////


// -- library class: constructor

// -- library class: getters/setters

// -- library class: methods (and other functions)


// printAllBooks
// cout << "Here is a list of books" << endl;

// viewRatings
// cout << username << " does not exist." << endl;
// cout << username << " has not rated any books yet." << endl;
// cout << "Here are the books that "<< name << " rated" << endl;
// cout << "Title : " << title << endl;
// cout << "Rating : " << rating << endl;
// cout << "-----" << endl;

// getRecommendations
// cout << username << " does not exist." << endl;
// cout << "Here is the list of recommendations" << endl;
// cout << title << " by " << author << endl;
// cout << "There are no recommendations for " << username <<" at present."<<endl;



/* displayMenu:
 * displays a menu with options
 * DO NOT MODIFY THIS FUNCTION
 */
void displayMenu(){
	cout << "Select a numerical option:" << endl;
	cout << "======Main Menu=====" << endl;
	cout << "1. Read book file" << endl;
	cout << "2. Read user file" << endl;
	cout << "3. Print book list" << endl;
	cout << "4. Get rating" << endl;
	cout << "5. Find number of books user rated" << endl;
	cout << "6. View ratings" << endl;
	cout << "7. Get average rating" << endl;
	cout << "8. Add a user" << endl;
	cout << "9. Checkout a book" << endl;
	cout << "10. Get recommendations" << endl;
	cout << "11. Quit" << endl;
}


int main(int argc, char const *argv[]) {


	// temp variables
    string choice;
    string bookFileName;
    string userFileName;
    string userName, bookTitle;
    string strRating;
    Library mylib = Library();


    while (choice != "11") {
        displayMenu();

        // take a menu opton
        getline(cin, choice);

        // convert the `choice` to an integer
        int menuChoice = stoi(choice);

        switch (menuChoice) {

            case 1:{
                // Initialize library -- readBooks
                cout << "Enter a book file name:" << endl;
                getline(cin, bookFileName);

                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                //////////////////////////////////////////////////////////////////////////
                int numofbooks = mylib.readBooks(bookFileName);
                
                if (numofbooks == -1){
                    cout << "No books saved to the database." << endl;
                }
                else if (numofbooks == -2){
                    cout << "Database is already full. No books were added." << endl;
                }
                else if(numofbooks ==  50){
                    cout << "Database is full. Some books may have not been added." << endl;
                }
                else{
                    cout << "Total books in the database: " << numofbooks << endl;
                }
               



                cout << endl;
                break;
            }
            case 2:{
                //  Initialize user catalog -- readRatings

                cout << "Enter a user file name:" << endl;
                getline(cin, userFileName);


                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                //////////////////////////////////////////////////////////////////////////

                int numofusers = mylib.readRatings(userFileName);
                
                if(numofusers == -1){
                    cout << "No users saved to the database." << endl;
                }
                else if(numofusers == -2){
                    cout << "Database is already full. No users were added." << endl;
                }
                else if(numofusers == 100){
                    cout << "Database is full. Some users may have not been added." << endl;
                }
                else{
                    cout << "Total users in the database: " << numofusers << endl;
                }
                

                cout << endl;
                break;
            }
            case 3:{
                // Display library -- printAllBooks

                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                //////////////////////////////////////////////////////////////////////////
                if(mylib.readBooks(bookFileName) == -1 && mylib.readRatings(userFileName) == -1){
                    cout << "Database has not been fully initialized." << endl;
                }
                else{
                    mylib.printAllBooks();
                }
                


                cout << endl;
                break;
            }
            case 4:{
                //  Get a rating -- getRating

                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                //////////////////////////////////////////////////////////////////////////

                // Use the below messages and match them to the return code. Update variables as needed.
                if(mylib.readBooks(bookFileName) == -1 && mylib.readRatings(userFileName) == -1){
                    cout << "Database has not been fully initialized." << endl;
                    break;
                }

               

        		// take user name
                cout << "Enter username:" << endl;
                getline(cin, userName);

                // take book title
                cout << "Enter book title:" << endl;
                getline(cin, bookTitle);

                int rating = mylib.getRating(userName, bookTitle);
                
                if (rating == 0){
                    cout << userName << " has not rated " << bookTitle << endl;
                }
                else if(rating == -3){
                    cout << userName << " or " << bookTitle << " does not exist." << endl;
                }
                else{
                    cout << userName << " rated " << bookTitle << " with " << rating << endl;
                }
                

                cout << endl;
                break;
            }
            case 5:{
                // Get number of books the user has rated -- getCountReadBooks


                if(mylib.readBooks(bookFileName) == -1 && mylib.readRatings(userFileName) == -1){
                    cout << "Database has not been fully initialized." << endl;
                    break;
                }
                // If the database has not been initialized
                // cout << "Database has not been fully initialized." << endl;

                cout << "Enter username:" << endl;
                getline(cin, userName);
                
                int read = mylib.getCountReadBooks(userName);
                
                if (read == 0){
                    cout << userName << " has not rated any books." << endl;
                }
                else if(read == -3){
                    cout << userName << " does not exist." << endl;
                }
                else{
                    cout << userName << " rated " << read << " books." << endl;
                }
               


            	cout << endl;
                break;
            }
            case 6:{
                // View user’s ratings -- viewRatings


                if(mylib.readBooks(bookFileName) == -1 && mylib.readRatings(userFileName) == -1){
                    cout << "Database has not been fully initialized." << endl;
                    break;
                }
                // If the database has not been initialized
                // cout << "Database has not been fully initialized." << endl;

        		// take user name
                cout << "Enter username:" << endl;
                getline(cin, userName);

                mylib.viewRatings(userName);

            	cout << endl;
                break;
            }
            case 7:{
                // Calculate the average rating for the book -- calcAvgRating

                if(mylib.readBooks(bookFileName) == -1 && mylib.readRatings(userFileName) == -1){
                    cout << "Database has not been fully initialized." << endl;
                    break;
                }


                // If the database has not been initialized
                // cout << "Database has not been fully initialized." << endl;

        		// take book title
                cout << "Enter book title:" << endl;
                getline(cin, bookTitle);


                double avg = mylib.calcAvgRating(bookTitle);
                
                if (avg == -3){
                    cout << bookTitle << " does not exist." << endl;
                }
                else{
                    cout << "The average rating for " << bookTitle << " is " << avg << endl;
                }
                
            	cout << endl;
                break;
            }
            case 8:{
                // Add a user to the database -- addUser
        		// take user name
                cout << "Enter username:" << endl;
                getline(cin, userName);

                int add = mylib.addUser(userName);
                
                if (add == 1){
                    cout << "Welcome to the library " << userName << endl;
                }
                else if(add == 0){
                    cout << userName << " already exists in the database." << endl;
                }
                else if(add == -2){
                    cout << "Database is already full. " << userName << " was not added." << endl;
                }

              
            	cout << endl;
                break;
            }
            case 9:{
                // Check out the book -- checkOutBook

                if(mylib.readBooks(bookFileName) == -1 && mylib.readRatings(userFileName) == -1){
                    cout << "Database has not been fully initialized." << endl;
                    break;
                }

                // If the database has not been initialized
                // cout << "Database has not been fully initialized." << endl;

        		// take user name
                cout << "Enter username:" << endl;
                getline(cin, userName);

                // take book title
                cout << "Enter book title:" << endl;
                getline(cin, bookTitle);

                // take rating
                cout<<"Enter rating for the book:"<<endl;
                getline(cin, strRating);


                int checkout = mylib.checkOutBook(userName, bookTitle, stoi(strRating));
                
                if (checkout == 1){
                    cout << "We hope you enjoyed your book. The rating has been updated." << endl;
                }
                else if(checkout == -4){
                    cout << strRating << " is not valid." << endl; 
                }
                else if(checkout == -3){
                    cout << userName << " or " << bookTitle << " does not exist." << endl;
                }
                
            	cout << endl;
                break;
            }
            case 10:{
                // get recommendations  -- getRecommendations

                if(mylib.readBooks(bookFileName) == -1 && mylib.readRatings(userFileName) == -1){
                    cout << "Database has not been fully initialized." << endl;
                    break;
                }

                // If the database has not been initialized
                // cout << "Database has not been fully initialized." << endl;

        		// take user name
                cout << "Enter username:" << endl;
                getline(cin, userName);

                mylib.getRecommendations(userName);

            	cout << endl;
                break;
            }
            case 11:{
                // quit
                cout << "good bye!" << endl;
                break;
            }
            default:{
                cout << "invalid input" << endl;
                cout << endl;
            }
        }
    }

    return 0;
}