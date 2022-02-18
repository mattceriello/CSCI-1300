#include <iostream>
#include <string>

using namespace std;

class CashRegister{
    public:
        void add_item(double price); //mutator/setter
        void clear();
        int get_number_of_items(); //accessor/getter
        double get_total_cost();
    private:
        double total;
        int numItems;
};


void CashRegister::add_item(double price){
        total+= price;
        numItems++;
    }

void CashRegister::clear(){
    total = 0;
    numItems = 0;
}

int CashRegister::get_number_of_items(){
    return numItems;
}



// CashRegister:: tells add_item that its cashregister object



int main(){
    double total;
    double price;
    int numItems;
    
    CashRegister reg1;
    reg1.clear();
    
    //display
    cout << reg1.get_number_of_items() << endl;
    
    reg1.add_item(1.95);
    
    cout << reg1.get_number_of_items() << endl;
    
    
    }
    


