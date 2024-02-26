

#ifndef FRAM_H_
#define FRAM_H_


#include "../Include/tc.h"


typedef enum
{
    STUDENTMAN=1,
    TEACHERMAN=2,
    COURSESMAN=3,
    SAVEANDCLOSE=4,

}StuffChoise_t;

typedef enum
{
    ADDTEACHER=1,
    DELETETEACHER=2,
    UPDATETEACHER=3,
    PRINTALLTEACHER=4,
    BACKOFTEACHER=5,

}TeacherChoise_t;



void goto_xy(unsigned x, unsigned y);

void Navy_Dark_Blue_Color(void);

void print_bold(const char* str);

void reset_text_attributes(void);

void Full_Screen(void);

void White_Frame(void);

void White_Frame2(void);

void School_Fram(void);

void Login_XSchool_Print(void);

void Choice_Fram_Print(void);

void Choice_Frame_CLS(void);

void System_CLS(void);

void Screen_CLS(void);

void Team_Names_Print(void);

void Screen_CLS(void);

void Stuff_Login_Frame(void);

void Student_Option_fram(void);

void Teachers_Options_Fram(void);

void Student_Information_print(void);

void Teacher_Management_Cls(void);

StuffChoise_t Get_OPtions(void);

TeacherChoise_t Teacher_Get_Management(void);

void Print_ALL_CLS(void);


#endif
