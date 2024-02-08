#include<fstream>
#include<iostream>
using namespace std;
int n;
double per;
int choice,rollnum;
char answer;
char yesno;
struct student
{
    char fname[20];
    char sname[20];
    int rollnum;
};
void database(student s[],int n)
{
    int no_q=0;
    int stu[100];
    int db_stud_mark[100];
    stu[n]=0;
    cout<<"mark less 50% will be fail\n";
    cout<<"\n\t database quiz\n";
    cout<<"1. In which of the following formats data is stored in the database management system?\n";
    cout<<"a) Image\n";
    cout<<"b) Text\n";
    cout<<"c) Table\n";
    cout<<"d) Graph\n";
    no_q++;
    cin>>answer;
    if(answer=='c'||answer=='C')
    {
        cout<<"your answer is the correct\n";
        stu[n]++;
    }
    else
    {
        cout<<"your answer is incorrect\n";
        cout<<"c is the correct answer\n";
    }

    cout<<"2. Which of the following is not an example of DBMS? \n";
    cout<<"a) MySQL \n";
    cout<<"b) Microsoft Acess \n";
    cout<<"c) IBM DB2 \n";
    cout<<"d) Google \n";
    no_q++;
    cin>>answer;
    if(answer=='d'||answer=='D')
    {
        cout<<"your answer is the correct\n";
        stu[n]++;
    }
    else
    {
        cout<<"your answer is incorrect\n";
        cout<<"d is the correct answer\n";
    }

    cout<<"3. Which of the following is a function of the DBMS?\n";
    cout<<"a) Storing data \n";
    cout<<"b) Providing multi-users access control \n";
    cout<<"c) Data Integrity \n";
    cout<<"d) All of the above \n";
    no_q++;
    cin>>answer;
    if(answer=='d'||answer=='D')
    {
        cout<<"your answer is the correct\n";
        stu[n]++;
    }
    else
    {
        cout<<"your answer is incorrect\n";
        cout<<"d is the correct answer\n";
    }

    cout<<"4. Which of the following is known as a set of entities of the same type that share same properties, or attributes? \n";
    cout<<"a) Relation set \n";
    cout<<"b) Tuples \n";
    cout<<"c) Entity set \n";
    cout<<"d) Entity Relation model \n";
    no_q++;
    cin>>answer;
    if(answer=='c'||answer=='C')
    {
        cout<<"your answer is the correct\n";
        stu[n]++;
    }
    else
    {
        cout<<"your answer is incorrect\n";
        cout<<"c is the correct answer\n";
    }


    cout<<"5. What is information about data called? \n";
    cout<<"a) Hyper data \n";
    cout<<"b) Tera data \n";
    cout<<"c) Meta data \n";
    cout<<"d) Relations \n";
    no_q++;
    cin>>answer;
    if(answer=='c'||answer=='C')
    {
        cout<<"your answer is the correct\n";
        stu[n]++;
    }
    else
    {
        cout<<"your answer is incorrect\n";
        cout<<"c is the correct answer\n\n";
    }
    db_stud_mark[n]=stu[n];
    ofstream fout;
    double per;
    fout.open("dbresult.txt",ios::app);
    fout<<"\t\tdatabase quiz result\n";
    fout<<"name :"<<s[n].fname<<" "<<s[n].sname<<endl;
    fout<<"your mark is "<<db_stud_mark[n]<<" out of "<<no_q<<endl;
    per=(100*db_stud_mark[n])/no_q;
    fout<<"you got "<<per<<"%"<<endl;
    if(per>=50)
    {
        fout<<"status pass\n";
    }
    else
    {
        fout<<"status fail!\n";
    }
    fout.close();
    cout<<"your personal data and your database quiz result saved on dbresult file\n";
}

void is(student s[],int n)
{
    int no_q=0;
    int stu[100];
    int is_stud_mark[100];
    stu[n]=0;
    cout<<"mark less 50% will be fail\n";
    cout<<"\n\t IS quiz\n";
    cout<<"1.computer is a combination of\n";
    cout<<"A,Hardware and Software\n";
    cout<<"B,CPU and Monitor\n";
    cout<<"C,I/O Devices\n";
    cout<<"D,all of the above\n";
    no_q++;
    cin>>answer;
    if(answer=='a'||answer=='A')
    {
        cout<<"your answer is the correct\n";
        stu[n]++;
    }
    else
    {
        cout<<"your answer is incorrect\n";
        cout<<"A is the correct answer\n";
    }
    cout<< "2.the process of giving instructions to the computer is \n";
    cout<<"A,Input\n";
    cout<<"B,Input and Output\n";
    cout<<"C,CPU\n";
    cout<<"D,Output\n";
    no_q++;
    cin>>answer;
    if(answer=='A'||answer=='a')
    {
        cout<<"your answer is the correct\n";
        stu[n]++;
    }
    else
    {
        cout<<"your answer is incorrect\n";
        cout<<"A is the correct answer\n";
    }
    cout<<"3. which of the followings are input devices\n";
    cout<<"A,monitor \n";
    cout<<"B,speaker\n";
    cout<<"C,keyboard \n";
    cout<<"D,printer\n";
    no_q++;
    cin>>answer;
    if(answer=='c'||answer=='C')
    {
        cout<<"your answer is the correct\n";
        stu[n]++;
    }
    else
    {
        cout<<"your answer is incorrect\n";
        cout<<"C is the correct answer\n";
    }
    cout<<"4. which of the followings are output devices\n";
    cout<<"A,microphone \n";
    cout<<"B,web cam\n";
    cout<<"C,touch pad\n";
    cout<<"D,plotters \n";
    no_q++;
    cin>>answer;
    if(answer=='d'||answer=='D')
    {
        cout<<"your answer is the correct\n";
        stu[n]++;
    }
    else
    {
        cout<<"your answer is incorrect\n";
        cout<<"D is the correct answer\n";
    }
    cout<<"5. which of the following is true?\n";
    cout<<"A,application software provide platform for system software.\n";
    cout<<"B,system software designed to manage the computer itself. \n";
    cout<<"C,linux is one example of application software. \n";
    cout<<"D,system software if designed for a specific purpose.\n";
    no_q++;
    cin>>answer;
    if(answer=='b'||answer=='B')
    {
        cout<<"your answer is the correct\n";
        stu[n]++;
    }
    else
    {
        cout<<"your answer is incorrect\n";
        cout<<"B is the correct answer\n\n";
    }
    is_stud_mark[n]=stu[n];
    ofstream fout;
    double per;
    fout.open("isresult.txt",ios::app);
    fout<<"\t\tInformatoin System quiz result\n";
    fout<<"name :"<<s[n].fname<<" "<<s[n].sname<<endl;
    fout<<"your mark is "<<is_stud_mark[n]<<" out of "<<no_q<<endl;
    per=(100*is_stud_mark[n])/no_q;
    fout<<"you got "<<per<<"%"<<endl;
    if(per>=50)
    {
        fout<<"status pass\n";
    }
    else
    {
        fout<<"status fail!\n";
    }
    fout.close();
    cout<<"your personal data and your IS quiz result saved on isresult file\n";
}
void cpp(student s[],int n)
{
    int no_q=0;
    int stud[100];
    int cpp_stud_mark[100];
    stud[n]=0;
    cout<<"mark less 50% will be fail\n";
    cout<<"\t\tc++ questions \n";
    cout<<"1.which of the following is high level programming language?\n";
    cout<<"A, C++\n";
    cout<<"B, JAVA\n";
    cout<<"C, PYTHON \n";
    cout<<"D, all are correct\n";
    no_q++;
    cin>>answer;
    if(answer=='d'||answer=='D')
    {
        cout<<"your answer is the correct answer\n";
        stud[n]++;
    }
    else
    {
        cout<<"your answer is incorrect\n";
        cout<<"d is the correct answer\n";
    }
    cout<<"2.which of the following is insertion operator?\n";
    cout<<"A, >>\n";
    cout<<"B, <<\n";
    cout<<"C, %\n";
    cout<<"D, &\n";
    no_q++;
    cin>>answer;
    if(answer=='b'||answer=='B')
    {
        cout<<"your answer is the correct answer\n";
        stud[n]++;
    }
    else
    {
        cout<<"your answer is incorrect\n";
        cout<<"b is the correct answer\n";
    }
    cout<<"3.which of the following is extraction operator?\n";
    cout<<"A, >>\n";
    cout<<"B, <<\n";
    cout<<"C, %\n";
    cout<<"D, &\n";
    no_q++;
    cin>>answer;
    if(answer=='a'||answer=='A')
    {
        cout<<"your answer is the correct answer\n";
        stud[n]++;
    }
    else
    {
        cout<<"your answer is incorrect\n";
        cout<<"a is the correct answer\n";
    }
    cout<<"4.from the following loops which one is post test loop?\n";
    cout<<"A, do....while\n";
    cout<<"B, for\n";
    cout<<"C, while \n";
    cout<<"D, none\n";
    no_q++;
    cin>>answer;
    if(answer=='a'||answer=='A')
    {
        cout<<"your answer is the correct answer\n";
        stud[n]++;
    }
    else
    {
        cout<<"your answer is incorrect\n";
        cout<<"a is the correct answer\n";
    }
    cout<<"5.which one of the following correct variable naming?\n";
    cout<<"A, &sum3\n";
    cout<<"B, 65ring\n";
    cout<<"C, variance26\n";
    cout<<"D, %percent\n";
    no_q++;
    cin>>answer;
    if(answer=='c'||answer=='C')
    {
        cout<<"your answer is the correct answer\n";
        stud[n]++;
    }
    else
    {
        cout<<"your answer is incorrect\n";
        cout<<"c is the correct answer\n";
    }
    cout<<"6.from the following loops which one is pre test loop?\n";
    cout<<"A, do....while\n";
    cout<<"B, for\n";
    cout<<"C, while \n";
    cout<<"D, B and C\n";
    no_q++;
    cin>>answer;
    if(answer=='d'||answer=='D')
    {
        cout<<"your answer is the correct answer\n";
        stud[n]++;
    }
    else
    {
        cout<<"your answer is incorrect\n";
        cout<<"d is the correct answer\n\n";
    }
    cpp_stud_mark[n]=stud[n];
    ofstream fout;
    double per;
    fout.open("c++result.txt",ios::app);
    fout<<"\t\tc++ quiz result\n";
    fout<<"name :"<<s[n].fname<<" "<<s[n].sname<<endl;
    fout<<"your mark is "<<cpp_stud_mark[n]<<" out of "<<no_q<<endl;
    per=(100*cpp_stud_mark[n])/no_q;
    fout<<"you got "<<per<<"%"<<endl;
    if(per>=50)
    {
        fout<<"status pass\n";
    }
    else
    {
        fout<<"status fail!\n";
    }
    fout.close();
    cout<<"your personal data and your c++ quiz result saved on c++result\n";
}


int main()
{
    student s[100];
    do
    {
        cout<<"\n....................................\n";
        cout<<"\n\t      Quiz System \n\n";
        cout<<"....................................\n";
        cout<<"Enter Your roll number : ";
        cin>>rollnum;
        n=rollnum-1;
        s[n].rollnum=rollnum;
        cout<<"Enter Your first Name : ";
        cin>>s[n].fname;
        cout<<"Enter Your second Name : ";
        cin>>s[n].sname;
        cout<<"\nselect option which subject do you want to take\n";
        cout<<"\t  1. c++ quiz\n";
        cout<<"\t  2. IS quiz\n";
        cout<<"\t  3. database quiz\n";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cpp(s,n);
            break;
        case 2:
            is(s,n);
            break;
        case 3:
            database(s,n);
            break;
        default:
            cout<<"wrong choice try again!\n";
            break;
        }
        cout<<"\n\npress y to continue or any other key to terminate \n";
        cin>>yesno;
    }
    while(yesno=='y'||yesno=='Y');
    return 0;
}

