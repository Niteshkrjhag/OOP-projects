#include<iostream>
#include <vector>
#include <iomanip>
#include <cctype>
#include <string>
using namespace std;

class Student{
    private:
    int Roll_no,Age;
    string Name;
    public:
    Student(int stdRoll_no,int stdAge,string stdName):Roll_no(stdRoll_no),Age(stdAge),Name(stdName){

    }
    string getName(){
        return Name;
    }
    void setAge(int a){
        Age = a;
    }
    int getAge(){
        return Age;
    }
    void setRoll_no(int b){
        Roll_no = b;
    }
    int getRoll_no(){
        return Roll_no;
    }
    void setName(string s){
        Name = s;
    }
    void displayStudent(){
        std::cout<<endl;
       std:: cout<<"\t\tRollNo : "<<Roll_no<<endl;
       std:: cout<<"\t\tName : "<<Name<<endl;
       std:: cout<<"\t\tAge : "<<Age<<endl;
    }
};
// function to capitalizing the First letter in name;
string capitalize(const string &name){
    string capital;
    bool c = true;
    for(char ch:name){
        if(c){
            capital+=toupper(ch);
            c=false;
        }else{
            capital+=tolower(ch);
        }
        if(ch==' '){
            c=true;
        }
    }
    return capital;
}

// checking whether the name that is input is valid or not;
bool validName(const string &name){
    for(char c:name){
        if(!isalpha(c)&& c!=' '){
           return false;
        }
    }
    return true;
}
// Creating a Function to Update student

void updateStudent(vector<Student> &student){
    string sname,check;
    int choice;
    std::cout<<"\t\t Enter Name to Update Record : ";
    std::cin.ignore();
    getline(std::cin,sname);
    if(validName(sname)){
        check=capitalize(sname);
    }else{
        std::cout<<".........you have entered Incorrect name format..........."<<endl;
    }
    for(int i=0;i<static_cast<int>(student.size());i++){
        if(student[i].getName()==check){
           
           std::cout<<"\t\t---Student Found -----"<<endl;
           std::cout<<"\t\t 1.Update Rollno "<<endl;
           std::cout<<"\t\t 2.Update Name "<<endl;
           std::cout<<"\t\t 3.Update Age "<<endl;
           std::cout<<"\t\t Enter your choice : ";
           std::cin>>choice;
           switch(choice){
            case 1:{
                int rollno;
                std::cout<<"Enter new roll no : ";
                std::cin>>rollno;
                student[i].setRoll_no(rollno);
                break;
            }
            case 2:{
                string newName,capNewName;
                do{
                std::cout<<"Enter new Name : ";
                std::cin.ignore();
                getline(std::cin,newName);
                
                if(validName(newName)){
                capNewName = capitalize (newName);
                student[i].setName(capNewName);
                }else{
                    std::cout<<"Invalid Name. Please enter valid name "<<endl;
                }
                }while(!validName(newName));
                break;
            }
            case 3:{
                int age;
                std::cout<<"Enter new age : ";
                std::cin>>age;
                student[i].setAge(age);
                break;
            }
            default:
            std::cout<<"\n\t\t.........Wrong Choice Entered..........."<<endl;
           }
           break;
        }
     else std::cout<<"\t\t Record Not Found Here"<<endl;  
    }
     
}
// Create Function to add new student

void addNewStudent(vector<Student> &students){
        int rollno,age;
        string name,capitalName;
        std::cout<<"Enter roll no : ";
        std::cin>>rollno;

        // if roll_no already exist then
        for(int i=0;i<static_cast<int>(students.size());i++){
            if(students[i].getRoll_no()==rollno){
                std::cout<<"\t\t Student with roll no = "<<rollno<<" already exists "<<endl;
                return;
            }
        }
       do{
        std::cout<<"Enter Name : ";
        std::cin.ignore();
        getline(std::cin,name);
   
        if(validName(name)){
            capitalName = capitalize(name);
        }else{
            std::cout<<"Enter valid Name "<<endl;
        }
       }while(!validName(name));
        std::cout<<"Enter Age : ";
        std::cin>>age;  
        students.push_back(Student(rollno,age,capitalName));
        std::cout<<"...Student Added Successfully..."<<endl;

}

void displayAllStudent(vector<Student> &student){

    if(student.empty()){
        std::cout<<"\t\t No student Found "<<endl;
        return;
    }else{
    const int columnWidth = 30;
    std::cout<<"\t\t"<<setw(columnWidth)<<left<<"Name"<<"\t\t"<<setw(columnWidth)<<left<<"Rollno"<<"\t\t"<<setw(columnWidth)<<left<<"Age"<<endl; 
    for(int i=0;i<static_cast<int>(student.size());i++){
        string s = student[i].getName();
        std::cout<<"\t\t"<<setw(columnWidth)<<left<<s<<"\t\t"<<setw(columnWidth)<<left<<student[i].getRoll_no()<<"\t\t"<<setw(columnWidth)<<left<<student[i].getAge()<<"\n";
    }
    return;        
    }
}

void searchStudent(vector<Student> &student){
    int rollNo;
    std::cout<<"\t\t Enter Rollno : ";
    std::cin>>rollNo;
    for(int i=0;i<static_cast<int>(student.size());i++){
        if(rollNo==student[i].getRoll_no()){
            std::cout<<"...............Student Found..................."<<endl;
            student[i].displayStudent();
            return;
        }
    }
    return ;
}
void deleteStudent(vector<Student> &student){
        string name;
        std::cout<<"Enter Name to Delete :";
        std::cin.ignore();
        getline(std::cin,name);
        char c;
        if(validName(name)){
            name=capitalize(name);
        }else{
            std::cout<<"\t\t No record with name "<<name<<" found.\n";
        }
        for(int i=0;i<static_cast<int>(student.size());i++){
            if(student[i].getName()==name){
                std::cout<<"\t\t...Student Found...\t\t"<<endl;
                student[i].displayStudent();
                std::cout<<endl;
                std::cout<<"Are you sure you want to delete student : (y/n) ";
                std::cin>>c;
                if(c=='y'){
                    student.erase(student.begin()+i);
                    std::cout<<"\t\t Student Deletion Successfull..."<<endl;
                    break;
                }
                else{
                    std::cout<<"\t\t...Record Deletion declined ....."<<endl;
                    break;
                }
            }
        }
}

int main(){
    vector<Student> students;
    char choice;
   do{
   int op;
    system("clear");
    std::cout<<"\t\t.....................................\t\t"<<endl;
    std::cout<<"\t\t Student Management Sysetem "<<endl;
     std::cout<<"\t\t.....................................\t\t"<<endl;
    std::cout<<"\t\t 1. Add New Student "<<endl;
    std::cout<<"\t\t 2. Display All Students "<<endl;
    std::cout<<"\t\t 3. Search Student "<<endl;
    std::cout<<"\t\t 4. Update Student "<<endl;
    std::cout<<"\t\t 5. Delete Student "<<endl;
    std::cout<<"\t\t 6. Exit "<<endl;
    std::cout<<"\t\t Enter Your Choice : ";
    std::cin>>op;
            while (op < 1 || op > 6) {
            std::cout << "\t\t Invalid option. Please enter a number between 1 and 6." << endl;
            std::cout << "\t\t Enter Your Choice : ";
            std::cin >> op;
        }
switch (op)
{
case 1:
       addNewStudent(students);
    break;
case 2:{
    displayAllStudent(students);
    break;
}
case 3:{
    searchStudent(students);
    break;
}
case 4:{
    updateStudent(students);
    break;
}
case 5:
      deleteStudent(students);
      break;
case 6:
       exit(1);
default:
    std::cout<<"\t\t...Invalid Option...";
    break;
}
std::cout<<"\n\t\t Do you want to continue? (Type 'y' for YES and 'n' for NO : ) ";
std::cin>>choice;
}
while( choice =='y' or choice=='Y');
 
}