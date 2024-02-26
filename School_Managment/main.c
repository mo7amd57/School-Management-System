#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>

#include "main.h"



int main()
{
    School_t xschool;

    Student_t StdScaned;

    StudentStatus_t STD_status;
    StudentStatus_t STD_status2;
    StuffChoise_t stuffchoise=ZERO;
    TeacherChoise_t TeachMange=ADDTEACHER;
    TeacherStatus_t teachoption=4;
    TeacherStatus_t teachstatus=4;

    CoursesChoice_t CousreMang=COURSE_ADD;
    CoursesStatus_t Cousrestatus=COURSE_EMPTY;
    CoursesStatus_t Cousrestatus2=COURSE_EMPTY;

    StudentChoice_t stdmanag=STD_ADD;
    StudentStatus_t stdchoice=STD_NOSPACE;


    int STD_Level;
    int STD_ID;
    int SDT_Index;
    int Teach_Index;
    int Course_Index;
    int Teach_ID;
    int stdlevel=0;
    int TypeOf_Sort;
    int ApllySortOn;

    loadSchoolData(&xschool);

     //initializeSchool(&xschool);

    //  saveSchoolData(&xschool);


    int choice=0;

    Full_Screen();

    White_Frame();

    School_Fram();

    while (1)
    {

        System_CLS();

        Team_Names_Print();

        White_Frame();

        Login_XSchool_Print();

        Choice_Fram_Print();

        choice=Get_Choice();



        Choice_Frame_CLS();


        if (choice==STUDENT)
        {
            Team_Names_Print();

            Student_Login_Frame(&xschool,&STD_Level,&SDT_Index,&STD_ID);
            Screen_CLS();
            Student_Information_print();

            print_Student_data(&xschool,STD_Level,SDT_Index);

            Students_Tables_Print();

            Choice_Frame_CLS();


        }

        else if (choice==STUFF)
        {

            Stuff_Login_Frame();
            Screen_CLS();
            TeachMange=ADDTEACHER;
            CousreMang=COURSE_ADD;
            stdmanag=STD_ADD;


            while(TeachMange!=BACKOFTEACHER && CousreMang!=COURSE_BACK &&stdmanag!=STD_BACK)

            {
                printf("%s",TC_BG_NRM);

                stuffchoise=Get_OPtions();

                if (stuffchoise==STUDENTMAN)
                {


                    goto_xy(2,48);
                    for (int i=0 ; i<204; i++)
                    {
                        print_bold("");
                        printf(" ");
                    }

                    while(stdmanag!=STD_BACK)
                    {
                        Student_Option_fram();


                        stdmanag=Student_Get_Management();


                        if (stdmanag==STD_ADD)
                        {
                            Student_Add(&xschool);
                        }

                        else if (stdmanag==STD_DELETE)
                        {
                            STD_status=STD_AGAIN;
                            stdchoice=STD_OK;
                            while(STD_status==STD_AGAIN&&stdchoice!=STD_NOTF)
                            {

                                stdchoice=Student_GetID_ToDELETE(&xschool,&SDT_Index,&STD_Level);

                                if (stdchoice==STD_OK)
                                {
                                    STD_status=Student_Delete_ByIndex(&xschool,STD_Level,SDT_Index);


                                }

                            }


                        }
                        else if (stdmanag==STD_UPDATE)
                        {
                            STD_status=STD_BACK;
                            stdchoice=STD_OK;
                            while(STD_status!=STD_AGAIN&&stdchoice!=STD_NOTF)
                            {

                                stdchoice=Student_GetID_ToUpdate(&xschool,&SDT_Index,&STD_Level);

                                if (stdchoice==STD_OK)
                                {

                                    printOne_Student(&xschool,STD_Level,SDT_Index);

                                    int update_status=Student_Update_GetOption(&stdlevel);

                                    if (update_status==1) // Update information and Level
                                    {
                                        //  Student_deletedirect(&xschool,STD_Level,SDT_Index);
                                        Student_ScanInfo(&xschool,&StdScaned,SDT_Index,STD_Level);
                                        Student_addToSchooldirect(&xschool,&StdScaned,stdlevel);
                                        Student_deletedirect(&xschool,STD_Level,SDT_Index);
                                    }
                                    else if (update_status==2)  // Update information Only
                                    {
                                        // Student_deletedirect(&xschool,STD_Level,SDT_Index);
                                        Student_ScanInfo(&xschool,&StdScaned,SDT_Index,STD_Level);
                                        Student_updateInfodirect(&xschool,STD_Level,SDT_Index,&StdScaned);
                                    }
                                    else if (update_status==3)  //Update  Level  Only
                                    {
                                        Student_moveBetweenLevels(&xschool,STD_Level,stdlevel,SDT_Index);
                                    }

                                    STD_status=Back_OR_UpdteMoreStudent();

                                }
                            }


                        }

                        else if (stdmanag==STD_SORTE)
                        {
                            TypeOf_Sort=Student_Sorting_Get_Option();

                            ApllySortOn=Student_ApplySorting_OnWhat();

                            Students_Sorting_Algorithms(&xschool,TypeOf_Sort,ApllySortOn);
                        }

                        else if (stdmanag==STD_PRINT)
                        {
                            Student_Printing_Algorithms(&xschool);

                        }
                        else if (stdmanag==STD_PERFECT)
                        {
                            int PerfectIndex=Student_Perfect_IndexInLevel(&xschool,1);
                            printOne_Student2(&xschool,1,PerfectIndex);
                            PerfectIndex=Student_Perfect_IndexInLevel(&xschool,2);
                            printOne_Student2(&xschool,2,PerfectIndex);
                            PerfectIndex=Student_Perfect_IndexInLevel(&xschool,3);
                            printOne_Student2(&xschool,3,PerfectIndex);
                            PrintALL_Back();
                        }
                        else if (stdmanag==STD_CALL)
                        {
                            STD_status2=STD_AGAIN;
                            STD_status=STD_OK;
                            while(STD_status2==STD_AGAIN&&STD_status!=STD_NOTF)
                            {

                                STD_status=Student_GetID_ToCall(&xschool,&SDT_Index,&STD_Level);
                                if (STD_status==STD_OK)
                                {
                                    STD_status2=Student_Call_Function(xschool,STD_Level,SDT_Index);
                                }

                            }



                        }


                    }

                    stdmanag=6;
                    Back_Toprevious_Cls();


                }
                else if (stuffchoise==TEACHERMAN)
                {
                    while(TeachMange!=BACKOFTEACHER)
                    {


                        Teachers_Options_Fram();
                        TeachMange=Teacher_Get_Management();
                        printf("%s%s",TC_BG_NRM,TC_B_NRM);



                        if (TeachMange==ADDTEACHER)
                        {
                            Add_Teacher(&xschool);


                        }
                        else if (TeachMange==UPDATETEACHER)
                        {
                            teachstatus=TEACH_AGAIN;
                            teachoption=TEACH_OK;
                            while(teachstatus==TEACH_AGAIN&&teachoption!=TEACH_NOTF)
                            {
                                teachoption=Get_TeacherID_ToUpdate(&xschool,&Teach_Index);

                                if (teachoption==TEACH_OK)
                                {
                                    teachstatus= Update_Teacher_Data(&xschool,Teach_Index);

                                }

                            }



                        }
                        else if (TeachMange==DELETETEACHER)
                        {
                            teachstatus=TEACH_AGAIN;
                            teachoption=TEACH_OK;

                            while(teachstatus==TEACH_AGAIN&&teachoption!=TEACH_NOTF)
                            {
                                teachoption=Get_TeacherID_ToDELETE(&xschool,&Teach_Index);

                                if (teachoption==TEACH_OK)
                                {
                                    teachstatus= Delete_Teacher(&xschool,Teach_Index);


                                }

                            }

                        }
                        else if (TeachMange==PRINTALLTEACHER)
                        {

                            // White_Frame2();
                            goto_xy(2,48);
                            for (int i=0 ; i<204; i++)
                            {
                                print_bold("");
                                printf(" ");
                            }

                            print_AllTeachers(&xschool);

                            PrintALL_Back();



                        }


                    }
                    TeachMange=6;
                    //Play_Sound_click_open();

                    Back_Toprevious_Cls();





                }
                else if (stuffchoise==COURSESMAN)
                {


                    while (CousreMang!=COURSE_BACK)
                    {

                        Course_Option_fram();

                        CousreMang=Course_Get_Management();


                        if (CousreMang==COURSE_ADD)
                        {
                            Cousrestatus=Course_AddToSchool(&xschool);

                        }
                        else if (CousreMang==COURSE_DELETE)
                        {
                            Cousrestatus2=COURSE_AGAIN;
                            Cousrestatus=COURSE_OK;

                            while(Cousrestatus2==COURSE_AGAIN&&Cousrestatus!=COURSE_NOTF)
                            {
                                Cousrestatus=Course_GetID_ToDELETE(&xschool,&Course_Index);

                                if (Cousrestatus==COURSE_OK)
                                {

                                    Cousrestatus2= Course_Delete(&xschool,Course_Index);


                                }

                            }


                        }
                        else if (CousreMang==COURSE_PRINTALL)
                        {
                            goto_xy(2,48);
                            for (int i=0 ; i<204; i++)
                            {
                                print_bold("");
                                printf(" ");
                            }
                            Course_PrintAll(&xschool);
                            PrintALL_Back();

                        }
                    }
                    CousreMang=6;
                    Back_Toprevious_Cls();




                }
                else
                {

                    saveSchoolData(&xschool);

                    printf("%s%s",TC_B_NRM,TC_BG_NRM);

                    CousreMang=COURSE_BACK;
                }




            }




        }
        else  //  choice==ABOUT
        {
            Screen_CLS();
            About_Developers();

            About_Back();



        }

    }







    return 0;
}
