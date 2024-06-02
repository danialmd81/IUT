#include<iostream>
#include<algorithm>
#include"Teacher.h"
#include"Student.h"

using namespace std;

int main()
{
    list<Student> s_list;
    list<Teacher> t_list;
    list<Lessons> l_list;
    string input;
    while (1)
    {
        cout<<"choose teacher or student or lesson to make a list for it."<<endl
        <<"1_Teacher"<<endl<<"2_student"<<endl<<"3_lessons"<<endl<<"#_end"<<endl;
        cin>>input;
//##############################################################################
        if(input=="1")
        {
            while (1)
            {
                cout<<"teacher:"<<endl
                <<"1_add"<<endl<<"2_delete"<<endl<<"3_show all"<<endl
                <<"4_search"<<endl<<"5_soft delete"<<endl<<"@_return"<<endl;
                cin>>input;
                if(input=="1")
                {
                    Teacher add;
                    t_list.push_back(add);
                    cout<<"teacher is added.\n";
                }
                if(input=="2")
                {
                    if(t_list.size()!=0)
                    {
                        int number;
                        cout<<"Teacher_number:";
                        cin>>number;
                        Teacher *del=nullptr;
                        for (auto &i : t_list)
                        {
                            if(i.get_Teacher_number() == number)
                            {
                                del = &i;
                            }
                        }
                        if(del!=nullptr)
                        {
                            t_list.remove(*del);
                            cout<<"teacher is removed\n";
                        }
                        else
                        {
                            cout<<"there is no thecher with this teacher_number."<<endl;
                        }
                    }
                    else
                    {
                        cout<<"there is no teacher to delete it.\n";
                    }
                }
                if(input=="3")
                {
                    if(t_list.size()!=0)
                    {
                        for (auto &i : t_list)
                        {
                            if(!i.get_soft_delete())
                            {
                                i.show();
                            }
                        }
                    }
                    else
                    {
                        cout<<"there is no teacher to show it.\n";
                    }
                }
                if(input=="4")
                {
                    if(t_list.size()!=0)
                    {
                        int number;
                        cout<<"Teacher_number:";
                        cin>>number;
                        Teacher *finded;
                        for (auto &i : t_list)
                        {
                            if(i.get_Teacher_number() == number)
                            {
                                finded = new Teacher{i};
                            }
                        }
                        if(!finded->get_soft_delete())
                        {
                            finded->show();
                        }
                        else
                        cout<<"there is no thecher with this teacher_number."<<endl;
                    }
                    else
                    {
                        cout<<"there is no teacher to serach for it.\n";
                    }
                }
                if(input=="5")
                {
                    if(t_list.size()!=0)
                    {
                        int number;
                        cout<<"Teacher_number:";
                        cin>>number;
                        Teacher *finded=nullptr;
                        for (auto &i : t_list)
                        {
                            if(i.get_Teacher_number() == number)
                            {
                                finded = &i;
                            }
                        }
                        if(finded!=nullptr)
                        {
                            finded->remove();
                        }
                        else
                        {
                            cout<<"there is no thecher with this teacher_number."<<endl;
                        }
                    }
                    else
                    {
                        cout<<"there is no teacher to serach for it.\n";
                    }
                }
                if(input=="@")
                {
                    break;
                }
            }
        }
//##################################################################################
        if(input=="2")
        {
            while (1)
            {
                cout<<"students:"<<endl
                <<"1_add"<<endl<<"2_delete"<<endl<<"3_show all"<<endl
                <<"4_search"<<endl<<"5_soft delete"<<endl<<"@_return"<<endl;
                cin>>input;
                if(input=="1")
                {
                    Student add;
                    s_list.push_back(add);
                    cout<<"student is added.\n";
                }
                if(input=="2")
                {
                    if(s_list.size()!=0)
                    {
                        int number;
                        cout<<"Student_number:";
                        cin>>number;
                        Student *del=nullptr;
                        for (auto &i : s_list)
                        {
                            if(i.get_Student_number() == number)
                            {
                                del = &i;
                            }
                        }
                        if(del!=nullptr)
                        {
                            s_list.remove(*del);
                            cout<<"student is removed\n";
                        }
                        else
                        {
                            cout<<"there is no student with this student_number."<<endl;
                        }
                    }
                    else
                    {
                        cout<<"there is no student to delete it.\n";
                    }
                }
                if(input=="3")
                {
                    if(s_list.size()!=0)
                    {
                        for (auto &i : s_list)
                        {
                            if(!i.get_soft_delete())
                            i.show();
                        }
                    }
                    else
                    {
                        cout<<"there is no student to show it.\n";
                    }
                }
                if(input=="4")
                {
                    if(s_list.size()!=0)
                    {
                        int number;
                        cout<<"Student_number:";
                        cin>>number;
                        Student *finded;
                        for (auto &i : s_list)
                        {
                            if(i.get_Student_number() == number)
                            {
                                finded = new Student{i};
                            }
                        }
                        if(!finded->get_soft_delete())
                        finded->show();
                        else
                        cout<<"there is no student with this student_number."<<endl;
                    }
                    else
                    {
                        cout<<"there is no student to serach for it.\n";
                    }
                }
                if(input=="5")
                {
                    if(t_list.size()!=0)
                    {
                        int number;
                        cout<<"Student_number:";
                        cin>>number;
                        Student *finded=nullptr;
                        for (auto &i : s_list)
                        {
                            if(i.get_Student_number() == number)
                            {
                                finded = &i;
                            }
                        }
                        if(finded!=nullptr)
                        {
                            finded->remove();
                        }
                        else
                        {
                            cout<<"there is no student with this teacher_number."<<endl;
                        }
                    }
                    else
                    {
                        cout<<"there is no student to soft delet it for it.\n";
                    }
                }
                if(input=="@")
                {
                    break;
                }
            }
        }
//################################################################################
        if(input=="3")
        {
            while (1)
            {
                cout<<"lessons:"<<endl
                <<"1_add"<<endl<<"2_delete"<<endl<<"3_show all"<<endl
                <<"4_search"<<endl<<"@_return"<<endl;
                cin>>input;
                if(input=="1")
                {
                    Lessons add;
                    l_list.push_back(add);
                    cout<<"lesson is added.\n";
                }
                if(input=="2")
                {
                    if(l_list.size()!=0)
                    {
                        int number;
                        cout<<"Lesson_number:";
                        cin>>number;
                        Lessons *del=nullptr;
                        for (auto &i : l_list)
                        {
                            if(i.get_number() == number)
                            {
                                del = &i;
                            }
                        }
                        if(del!=nullptr)
                        {
                            l_list.remove(*del);
                            cout<<"lesson is removed\n";
                        }
                        else
                        {
                            cout<<"there is no lesson with this teacher_number."<<endl;
                        }
                    }
                    else
                    {
                        cout<<"there is no lesson to delete it.\n";
                    }
                }
                if(input=="3")
                {
                    if(l_list.size()!=0)
                    {
                            for (auto &i : l_list)
                        {
                            i.show_lessons();
                        }
                    }
                    else
                    {
                        cout<<"there is no lesson to show it.\n";
                    }
                }
                if(input=="4")
                {
                    if(l_list.size()!=0)
                    {
                        int number;
                        cout<<"lesson_number:";
                        cin>>number;
                        Lessons *finded;
                        for (auto &i : l_list)
                        {
                            if(i.get_number() == number)
                            {
                                finded = new Lessons{i};
                            }
                        }
                        finded->show_lessons();
                    }
                    else
                    {
                        cout<<"there is no lesson to serach for it.\n";
                    }
                }
                if(input=="@")
                {
                    break;
                }
            }
        }
//############################################################################
        if(input=="#")
        {
            break;
        }
    }

}