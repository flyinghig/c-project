#include <iostream>
#include<conio.h>
#include<fstream>

using namespace std;


class contact{
 private:
     char firstname[100],lastname[100],email[100],address[100];
     long long phoneno;
     
 public:
    void createcontact(){
        cout<<"Enter your first name----------------"<<endl;
        cin>>firstname;
        
        cout<<"Enter your last name------------------"<<endl;
        cin>>lastname;
        
        cout<<"Enter the phoneno-------"<<endl;
        cin>>phoneno;
        
        cout<<"Enter your email address----------------"<<endl;
        cin>>email;
        
        cout<<"Enter your address details--------------"<<endl;
        cin>>address;
    }
    void contactdetails(){
        cout<<"Name---"<<firstname<<" "<<lastname<<endl;
        cout<<"Email----"<<email<<endl;
        cout<<"address-----"<<address<<endl;
        
    }
    void writeonfile(){
        char ch;
        ofstream f1;
        f1.open("CMS.dat",ios::binary | ios::app);
        do{
            createcontact();
            f1.write(reinterpret_cast<char*>(this),sizeof(*this));
            cout<<"Any other contact details to add?(Y/N)-------------"<<endl;
            cin>>ch;
        }while(ch=='Y');
        cout<<"Contacts is successfully saved and created---------------"<<endl;
        f1.close();
    }
    void readfromfile(){
        ifstream f2;
        f2.open("CMS.dat",ios::binary);
        cout<<"\n---------------------------------------------------\n";
        cout<<"List of contacts";
        cout<<"\n----------------------------------------------------\n";
        
        while(!f2.eof()){
            if(f2.read(reinterpret_cast<char*>(this),sizeof(*this))){
                contactdetails();
                cout<<"\n--------------------------------------------\n";}}
                f2.close();
                
            }
        
    void searchcontact(){
        ifstream f3;
        long long phone;
        cout<<"Enter the phone number you want to search-------------------------"<<endl;
        cin>>phone;
        f3.open("CMS.dat",ios::binary);
        
        while(!f3.eof()){
            if(f3.read(reinterpret_cast<char*>(this),sizeof(*this))){
                if(phone==phoneno){
                    contactdetails();
                    return;}
                }
            }
            cout<<"\n\n No contacts found in data";
            f3.close();
        }
        void deletefromfile(){
            long long phone;
            int flag=0;
            ofstream f4;
            ifstream f5;
            f5.open("CMS.dat",ios::binary);
            f4.open("temp.dat",ios::binary);
            
            cout<<"Enter the phone no be deleted------------------------"<<endl;
            cin>>phone;
            while(!f5.eof()){
                if(f5.read(reinterpret_cast<char*>(this),sizeof(*this))){
                    if(phoneno!=phone){
                        f4.write(reinterpret_cast<char*>(this),sizeof(*this));
                    }
                    else flag=1;
                }
            }
            f5.close();
            f4.close();
            remove("CMS.dat");
            rename("temp.dat","CMS.dat");
            
            flag==1?
            cout<<"\tContact successfully deleted---------":
            cout<<"\tContact not found-----------------";
        }
        
        void editcontact(){
            long long phone;
            fstream f6;
            cout<<"Edit contacts";
            cout<<"\n--------------------------------------\n";
            cout<<"Enter the phone no you want to edit----------------------------";
            cin>>phone;
            
            f6.open("CMS.dat",ios::binary|ios::in|ios::out);
            
            while(!f6.eof()){
                if(f6.read(reinterpret_cast<char*>(this),sizeof(*this))){
                    if(phone==phoneno){
                        cout<<"Enter new details-------------------\n";
                        createcontact();
                        
                        int pos=-1 *sizeof(*this);
                        f6.seekp(pos,ios::cur);
                        f6.write(reinterpret_cast<char*>(this),sizeof(*this));
                        cout<<endl<<endl<<"\tContact updated--------------------------------";
                        return;
                    }
                }
            }
            cout<<"\n\n no data found";
            f6.close();
        }
    
    
};
int main(){
    system("cls");
    system("Color 3F");
    
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t * Welcome to contact management system *";
    getch();
    
    while(1){
        contact c1;
        int choice;
        
        system("cls");
        system("Color 03");
        
        cout<<"\nContact management system";
        cout<<"\n\n Main menu";
        cout<<"\n-----------------------------------------------------\n";
        cout<<"Enter 1 for adding a new contact----------------\n";
        cout<<"Enter 2 for listing all the contacts-------------\n";
        cout<<"Enter 3 for searching the contact----------------\n";
        cout<<"Enter 4 for to delete an contact-------------------\n";
        cout<<"Enter 5 for to edit an contact-----------------\n";
        cout<<"Enter 0 for an exit------------------------\n";
        cout<<"\n-----------------------------------------------------\n";
        cout<<"Enter your choice********************************";
        cin>>choice;
        
        switch(choice){
            case 1:
            system("cls");
            c1.writeonfile();
            break;
            
            case 2:
            system("cls");
            c1.readfromfile();
            break;
            
            case 3:
            system("cls");
            c1.searchcontact();
            break;
            
            case 4:
            system("cls");
            c1.deletefromfile();
            break;
            
            case 5:
            system("cls");
            c1.editcontact();
            break;
            
            case 0:
            system("cls");
            cout<<"\n\n\n\n\n\t\tThank you for using CONTACT management system"<<endl;
            exit(0);
            break;
            
            default:
            continue;}
            int option;
            cout<<"\n\n......------------Enter the choice:\n(1) MAIN MENU\t\t(0) EXIT\n ";
            cin>>option;
            
            switch(option){
                case 0:
                system("cls");
            cout<<"\n\n\n\n\n\t\tThank you for using CONTACT management system"<<endl;
            exit(0);
            break;
             
             default:
             continue;}
        }
        return 0;
    
}