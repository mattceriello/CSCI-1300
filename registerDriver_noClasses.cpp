#include <iostream>
#include <iomanip>

using namespace std;

// Solution without using classes
/**
   Displays the item count and total price of a cash register.
   @param reg the cash register to display
*/
void display(double tot, int items)
{
   cout << items << " $" << fixed << setprecision(2)
      << tot << endl;
}
double clearTotal()
{
   double tot = 0;
   return tot;
}
int clearItems()
{
   return 0;
}
double addItem(double tot, double prix)
{
   return (tot + prix);
}

int main()
{
   double total;  //Declare variables
   double price;
   int numItems;

   // start at 0 = clear all
   total = clearTotal();
   numItems = clearItems();
   // display
   display(total, numItems);

   // add item = we need to modify total, numItems
   price = 1.95;
   numItems++;
   total = addItem(total, price);

   // display
   display(total, numItems);

   // add item = we need to modify total, numItems
   price = 2.95;
   numItems++;
   total = addItem(total, price);

   // display
   display(total, numItems);

   // add item = we need to modify total, numItems
   price = 5.95;
   numItems++;
   total = addItem(total, price);

   // display
   display(total, numItems);

   // start at 0 = clear all
   total = clearTotal();
   numItems = clearItems();
   // display
   display(total, numItems);

   return 0;
}

