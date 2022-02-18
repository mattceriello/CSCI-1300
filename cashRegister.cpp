#include <iostream>
#include <string>

using namespace std;

class CashRegister{
    public:
        void add_item(double price); //mutator/setter
        void clear();
        void add_items(int quant, double price);
        int get_count(); //accessor/getter
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

int CashRegister::get_count(){
    return numItems;
}

void CashRegister::add_items(int quant, double price){
    for (int i = 0; i < quant; i++){
        add_item(price);
    }    
}

double CashRegister::get_total_cost(){
    return total;
}

void display(CashRegister reg){
    cout<<reg.get_count();
    
}

// CashRegister:: tells add_item that its cashregister object



int main(){
    //double total;
    //double price;
    //int numItems;
    
    CashRegister reg1;
    //reg1.clear();
    
    //display
    cout << reg1.get_count() << endl;
    
    reg1.add_item(1.95);
    
    cout << reg1.get_count() << endl;
    
    
    }
    


