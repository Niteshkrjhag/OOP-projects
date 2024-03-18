#include<iostream>
#include<string>
#include<vector>
using namespace std;

class User{
    private:
    string name;
    string password;
    string email_add;
    string full_name;
    string date_of_birth;
    string address;
    string phone_num;
    public:
    User(string name,string pass,string email_add,string full_name,string dob,
    string address,string phone_num):name(name),password(pass),email_add(email_add),full_name(full_name),
    date_of_birth(dob),address(address),phone_num(phone_num){

    }
    string getName(){
        return name;
    }
    string getPassword(){
        return password;
    }
    void getDetail(){
        cout<<"\t\t Name : "<<name<<endl;
        cout<<"\t\t Password : "<<password<<endl;
        cout<<"\t\t Email Address : "<<email_add<<endl;
        cout<<"\t\t Full Name : "<<full_name<<endl;
        cout<<"\t\t Date Of Birth : "<<date_of_birth<<endl;
        cout<<"\t\t Address : "<<address<<endl;
        cout<<"\t\t Phone No : "<<phone_num<<endl;
    }
};

class UserManager{
    private:
    vector <User> user; // create object of vector 
    public:
    void RegisterUser(){
        string username,password,email_add,full_name,date_of_birth,address,phone_numb;
        cout<<"Enter User Name: ";
        cin.ignore();
        getline(cin,username);
        cout<<"Enter password: ";
        cin>>password;
        cout<<"Enter your email address : ";
        cin>>email_add;
        cout<<"Enter your full name : ";
        cin.ignore();
        getline(cin,full_name);
        cout<<"Enter your date_of_birth  in dd/mm/yyyy format : ";
        getline(cin,date_of_birth);
        cout<<"Enter your address : ";
        
        getline(cin,address);
        cout<<"Enter your Phone Number : ";
        cin>>phone_numb;
        User newUser(username,password,email_add,full_name,date_of_birth,address,phone_numb);
        user.push_back(newUser);
        cout<<"\t\t User Register Successfull......"<<endl<<endl;
    }
    bool LoginUser(){
             string name,pass;
            cout<<"\t\t Enter User : ";
            cin.ignore();
            getline(cin,name);
            cout<<"\t\t Enter Password : ";
            cin>>pass;
       for(int i=0;i<user.size();i++){
        if(name==user[i].getName() && pass==user[i].getPassword()){
            cout<<"\n\t\t ......Login Successful!!!!......"<<endl<<endl;
            return true;
        }
       }
       cout<<"n\t\t Invalid user name or password "<<endl;
       return false;
    }
    void showUserList(){
        cout<<"\t\t first Login Yourself......... :"<<endl;
        bool t = LoginUser();
        if(t){
            cout<<"\t\t List of User are as follow "<<endl;
            for(int i=0;i<user.size();i++){
                cout<<"\n\t\t\t"<<i+1<<"."<<user[i].getName();
            }
            cout<<endl<<endl;
        }else{
            cout<<"\t\t first register yourself to see the user list "<<endl;
        }
        
    }
    void searchUser(string username){ 
        int count =0,t;
          for(int i=0;i<user.size();i++){
            if(user[i].getName()==username){
                count++; 
               t=i;  
            }
          }
          if(count){
            char c;
           cout<<"\t\t User found : "<<username ;
           cout<<"\n\t\t Do you want user detail : yes(y) or No(n) : ";
           cin>>c;
           if(c=='y'){
             string pass;
             cout<<"\t\tEnter password for confirmation : ";
             cin>>pass;
             cout<<endl;
             if(pass==user[t].getPassword()){
                user[t].getDetail();
             }else{
                cout<<"\n\t\t Wrong Password. Try again later!!...";
             }
           }

          }else{
            cout<<"\t\tThere is no user with name "<<username<<endl;
          }

    }
    bool deleteUser(string username){
       
        for(int i=0;i<user.size();i++){
            if(user[i].getName()==username){
                string pass;
                cout<<"\t\tUser Found. Enter password to confirm delete. ";
                  cin>>pass;
                  cout<<endl;
                if(user[i].getPassword()==pass){

                    user.erase(user.begin()+i);
                    cout<<"\t\t User record is deleted "<<endl;
                    return true;
                    
                }else{
                    cout<<"\t\t Incorrect password "<<endl;
                    return false;
                }
            }
        }  
        cout<<"\n\t\tuser not found. "<<endl;
        return false;
    }
};

int main(){
    UserManager usermanage;
    char choice;
    do{
        system("clearf");
     int op;
    cout<<"\n\n\t\t1. Register User "<<endl;
    cout<<"\t\t2. Login "<<endl;
    cout<<"\t\t3. Show User List "<<endl;
    cout<<"\t\t4. Search User "<<endl;
    cout<<"\t\t5. Delete User "<<endl;
    cout<<"\t\t6. Exit "<<endl;
    cout<<"\t\t Enter Your Choice : ";
    cin>>op;
    switch(op){
        case 1:{
          usermanage.RegisterUser();
        break;          
        }
        case 2:{
            usermanage.LoginUser();
            break;
        }
        case 3:{
            usermanage.showUserList();
            break;
        }
        case 4:{
            string name;
            cout<<"\n\t\tEnter user name you want to search for : ";
            cin>>name;
            usermanage.searchUser(name);
            break;
        }
        case 5:{
            string username;
            cout<<" \n\t\t Enter the username you want to delete : ";
            cin>>username;
            usermanage.deleteUser(username);
            break;
        }
        case 6:{
         exit(1);
        }

    } 
    cout<<"Do you still want to continue? ['Y' or 'y' for Yes/ 'N' or 'n' for No]"<<endl;
    cin>>choice;    
    }
    while(choice == 'y'|| choice=='Y');

}