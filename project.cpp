#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <string>
using namespace std; 
class Bill{
    private:
    string Item;
    int Rate, Quantity;
    public:
    Bill():Item(""),Rate(0),Quantity(0){ }

    void setItem(string item){
        Item = item;

    }
    void setRate(int rate){
        Rate = rate;
    }
    void setQuant(int quant){
        Quantity = quant;
    }

    string getItem(){
        return Item;
    }
    int getRate(){
        return Rate;
    }
    int getQuant(){
        return Quantity;
    }

};
void addItem(Bill b){
    bool close = false;
    while(!close){
        int choice;
        cout<<"\t1.Add."<<endl;
        cout<<"\t2.close."<<endl;
        cout<<"\tEnter Choice: ";
        cin>>choice;

        if(choice==1){
            system("cls");
            string item;
            int rate , quant ;

            cout<<"\tEnter item name :";
            cin>>item;
            b.setItem(item);
            
            cout<<"\tEnter rate of item :";
            cin>>rate;
            b.setRate(rate);

            cout<<"\tEnter Quantity of item :";
            cin>>quant;
            b.setQuant(quant);

            ofstream out("D:/C++/bill.txt" , ios::app);
            if(!out) {
                cout<<"\tError : File can't open!"<<endl;

            }
            else {
                cout<<"\t"<<b.getItem()<<b.getRate()<<" : " <<b.getQuant()<<endl<<endl;

            }
            out.close();
            cout<<"\tItem added successful"<<endl;
            Sleep(3000);
        }

        else if(choice == 2) {
            system("cls");
            close = true;
            cout<<"\tBack to main menu !"<<endl;
            Sleep(3000);

        }
    }
}

int main(){
    Bill b;

    bool exit = false;
    while(!exit){
        system("cls");
        int val;
        cout<<"\tWelcome Super Market Billing System"<<endl;
        cout<<"\t***********************************"<<endl;
        cout<<"\t\t1.Add Item."<<endl;
        cout<<"\t\t2.Print Bill."<<endl;
        cout<<"\t\t3.Exit."<<endl;
        cout<<"\t\tEnter Choice:";
        cin>>val;
        if(val==1){
            addItem(b);

        }
        else if(val==3){
            exit = true;
        }
    }
}