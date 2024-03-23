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
        cout<<endl;
        cout<<"\t\tRollNo : "<<Roll_no<<endl;
        cout<<"\t\tName : "<<Name<<endl;
        cout<<"\t\tAge : "<<Age<<endl;
    }
};
// function to capitalizing the First letter in name;
string capitalize(const string &name){
    string capital;
    bool c = true;
    for(char ch:name){
        if(c){
            capital+=toupper(c);
            c=false;
        }else{
            capital+=tolower(c);
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
    string sname;
    bool found = false;
    int choice;
    cout<<"\t\t Enter Name to Update Record : ";
    cin.ignore();
    getline(cin,sname);
    for(int i=0;i<static_cast<int>(student.size());i++){
        if(student[i].getName()==sname){
            found = true;
           
           cout<<"\t\t---Student Found -----"<<endl;
           cout<<"\t\t 1.Update Rollno "<<endl;
           cout<<"\t\t 2.Update Name "<<endl;
           cout<<"\t\t 3.Update Age "<<endl;
           cout<<"\t\t Enter your choice : ";
           cin>>choice;
           switch(choice){
            case 1:{
                int rollno;
                cout<<"Enter new roll no : ";
                cin>>rollno;
                student[i].setRoll_no(rollno);
                break;
            }
            case 2:{
                string newName,capNewName;
                do{
                cout<<"Enter new Name : ";
                cin.ignore();
                getline(cin,newName);
                if(validName(newName)){
                capNewName = capitalize (newName);
                }else{
                    cout<<"Invalid Name. Please enter valid name "<<endl;
                }
                }while(!validName(newName));
                break;
            }
            case 3:{
                int age;
                cout<<"Enter new age : ";
                cin>>age;
                student[i].setAge(age);
                break;
            }
            default:
            cout<<"\n\t\t.........Wrong Choice Entered..........."<<endl;
           }
           break;
        }
       
    }
     cout<<"\t\t Record Not Found Here"<<endl;
}



// Create Function to add new student

void addNewStudent(vector<Student> &students){
        int rollno,age;
        string name,capitalName;
        cout<<"Enter roll no : ";
        cin>>rollno;

        // if roll_no already exist then
        for(int i=0;i<static_cast<int>(students.size());i++){
            if(students[i].getRoll_no()==rollno){
                cout<<"\t\t Student with roll no = "<<rollno<<" already exists "<<endl;
                return;
            }
        }
       do{
        cout<<"Enter Name : ";
        cin.ignore();
        getline(cin,name);
   
        if(validName(name)){
            capitalName= capitalize(name);
        }else{
            cout<<"Enter valid Name "<<endl;
        }
       }while(!validName(name));
        cout<<"Enter Age : ";
        cin>>age;  
        students.push_back(Student(rollno,age,capitalName));
        cout<<"...Student Added Successfully..."<<endl;

}

void displayAllStudent(vector<Student> &student){

    if(student.empty()){
        cout<<"\t\t No student Found "<<endl;
        return;
    }else{
    const int columnWidth = 15;
    cout<<"\t\t"<<setw(columnWidth)<<left<<"Name"<<"\t\t"<<setw(columnWidth)<<left<<"Rollno"<<"\t\t"<<setw(columnWidth)<<left<<"Age"<<endl; 
    for(int i=0;i<static_cast<int>(student.size());i++){
        string s = student[i].getName();
        cout<<"\t\t"<<setw(columnWidth)<<left<<s<<"\t\t"<<setw(columnWidth)<<left<<student[i].getRoll_no()<<"\t\t"<<setw(columnWidth)<<left<<student[i].getAge()<<endl;
    }
    return;        
    }
}

void searchStudent(vector<Student> &student){
    int rollNo;
    cout<<"\t\t Enter Rollno : ";
    cin>>rollNo;
    for(int i=0;i<student.size();i++){
        if(rollNo==student[i].getRoll_no()){
            cout<<"...............Student Found..................."<<endl;
            student[i].displayStudent();
            return;
        }
    }
    return ;
}
void deleteStudent(vector<Student> &student){
        string name;
        cout<<"Enter Name to Delete :";
        cin.ignore();
        getline(cin,name);
        char c;
        for(int i=0;i<static_cast<int>(student.size());i++){
            if(student[i].getName()==name){
                cout<<"\t\t...Student Found...\t\t"<<endl;
                student[i].displayStudent();
                cout<<endl;
                cout<<"Are you sure you want to delete student : (y/n) ";
                cin>>c;
                if(c=='y'){
                    student.erase(student.begin()+i);
                    cout<<"\t\t Student Deletion Successfull..."<<endl;
                    break;
                }
                else{
                    cout<<"\t\t...Record Deletion declined ....."<<endl;
                    break;
                }
            }
        }
}

int main(){
    vector<Student> students;
    students.push_back(Student(1,2,"nitesh"));
    char choice;
   
   do{
   int op;
    system("clear");
    cout<<"\t\t.....................................\t\t"<<endl;
    cout<<"\t\t Student Management Sysetem "<<endl;
     cout<<"\t\t.....................................\t\t"<<endl;
    cout<<"\t\t 1. Add New Student "<<endl;
    cout<<"\t\t 2. Display All Students "<<endl;
    cout<<"\t\t 3. Search Student "<<endl;
    cout<<"\t\t 4. Update Student "<<endl;
    cout<<"\t\t 5. Delete Student "<<endl;
    cout<<"\t\t 6. Exit "<<endl;
    cout<<"\t\t Enter Your Choice : ";
    cin>>op;
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
case 6:
       exit(1);
default:
    cout<<"\t\t...Invalid Option...";
    break;
}
cout<<"\n\t\t Do you want to continue? (Type 'y' for YES and 'n' for NO : ) ";
cin>>choice;
}
while( choice =='y' or choice=='Y');
 
}