

#ifndef School_H_
#define School_H_


#include "../Include/tc.h"

#define MAX_TEACHERS  20
#define MAX_COURSES   20
#define MAX_STUDENTS  50
#define MAX_CHAR      50
#define PHONENUM      15

#define TRUE   1
#define FALSE  0

typedef struct
{
    char coursename[MAX_CHAR];
    int courseID;
} Course_t;

typedef struct
{
    char name[MAX_CHAR];
    int stdId;
    char stdPhone[PHONENUM];
    int courseCount;
    int scores[10];

} Student_t;

typedef struct
{
    char name[MAX_CHAR];
    int teacherID;
    char teachPhone[PHONENUM];
} Teacher_t;

typedef struct {
    Student_t student[MAX_STUDENTS];
    int studentCount;

} Level_t;


typedef struct
{
    Level_t level1;
    Level_t level2;
    Level_t level3;

    Course_t courses[MAX_COURSES];
    int courseCount;
    Teacher_t teachers[MAX_TEACHERS];
    int teacherCount;
} School_t;

typedef enum
{
    STD_NOTF=0,
    STD_NOSPACE=0,
    STD_OK=1,
    STD_AGAIN,
}StudentStatus_t;

typedef enum
{
    TEACH_NOTF=0,
    TEACH_NOSPACE=0,
    TEACH_OK=1,
    TEACH_AGAIN=2,
}TeacherStatus_t;

typedef enum
{
    SCHOOL_EMPTY=0,
    SCHOOL_FULL=0,
    SCHOOL_OK=1,
}SchoolStatus_t;

typedef enum
{
    COURSE_EMPTY=0,
    COURSE_NOSPACE=0,
    COURSE_NOTF=0,
    COURSE_OK=1,
    COURSE_AGAIN=2,
}CoursesStatus_t;

typedef enum
{
    COURSE_ADD=1,
    COURSE_DELETE=2,
    COURSE_PRINTALL=3,
    COURSE_BACK=4,
}CoursesChoice_t;

typedef enum
{
    STD_ADD=1,
    STD_DELETE=2,
    STD_UPDATE=3,
    STD_SORTE=4,
    STD_PRINT=5,
    STD_PERFECT=6,
    STD_CALL=7,
    STD_BACK=8,
}StudentChoice_t;




int Get_Choice(void);


void String_copy (char *source ,char *copy_in);


void String_copy_TillSpace (char *source ,char *copy_in);


void initializeSchool(School_t *school);


void saveSchoolData(const School_t *school) ;


void loadSchoolData(School_t *school);



int String_to_Integer( char* str);


void Student_Login_Frame(const School_t *school,int *level, int *index,int*STD_ID);


void print_Student_data(const School_t *school, int level, int index);



/*=================================>> Teacher Functions <<============================================*/




void printTeacher(const Teacher_t *teacher) ;


void printTeacher2(const Teacher_t *teacher);


void printOne_TeacherByIndex(const School_t *school, int index);


void print_AllTeachers(const School_t *school);


TeacherStatus_t searchTeacher(const School_t *school, int teacherID, int *teacherIndex);


int Back_OR_Add_MoreTeacher(void);


void String_scan (char *string);


TeacherStatus_t Add_Teacher(School_t *school);


void Teacher_deletedirect(School_t *school, int teacherIndex);


int Back_OR_Update_MoreTeacher(void);



TeacherStatus_t Update_Teacher_Data(School_t *school,int index);


TeacherStatus_t Get_TeacherID_ToUpdate(const School_t *school, int *teacherIndex);


TeacherStatus_t Get_TeacherID_ToDELETE(const School_t *school, int *teacherIndex);


int Delete_Teacher_Confirm(void);


int Back_OR_Delete_MoreTeacher(void);


TeacherStatus_t Delete_Teacher(School_t *school, int teacherIndex);



/*==============================>> Course Function  <<========================================*/



void Course_Option_fram(void);


CoursesChoice_t Course_Get_Management(void);


int Back_OR_Add_MoreCourses(void);


CoursesStatus_t Course_AddToSchool(School_t *school);


void addCourseToAllStudents(School_t *school, int courseScore);


void DeleteCourseToAllStudents(School_t *school);


CoursesStatus_t Course_Search(const School_t *school, int courseID,int *courseIndex);


void Course_PrintOne(const School_t *school, int index);


void Course_PrintOne2(const School_t *school, int index);


void Course_Print2(const Course_t *Course);


//void Course_Print(const Course_t *Course);


int Delete_Course_Confirm(void);


int Back_OR_Delete_MoreCourses(void);


CoursesStatus_t Course_Delete(School_t *school, int courseIndex);


CoursesStatus_t Course_GetID_ToDELETE(const School_t *school, int *courseIndex);


void Course_PrintAll(const School_t *school);



/*===============================>> Student Functions <<=====================================*/



StudentStatus_t SearchStudent_InSchool_ByID(const School_t *school, int studentID, int *level, int *index);


StudentChoice_t Student_Get_Management(void);


int Student_Get_Level(void);


int Back_OR_Add_MoreStudent(void);


StudentStatus_t Student_Add(School_t *school);


StudentStatus_t Student_GetID_ToDELETE(const School_t *school, int *studentIndex,int *plevel);


int Delete_Student_Confirm(void);


int Back_OR_Delete_MoreStudent(void);


StudentStatus_t Student_Delete_ByIndex(School_t *school, int level, int index);


StudentStatus_t Student_GetID_ToUpdate(const School_t *school, int *studentIndex,int *plevel);


int Student_Get_Level2(void);


int Student_Update_GetOption(int *level);


int Back_OR_UpdteMoreStudent(void);


StudentStatus_t Student_addToSchooldirect(School_t *school, const Student_t *newStudent,int level);


void Student_ScanInfo(const School_t *school,Student_t *student,int index,int level);


StudentStatus_t Student_updateInfodirect(School_t *school, int level, int index, const Student_t *newStudent);


StudentStatus_t Student_deletedirect(School_t *school, int level, int index);


StudentStatus_t Student_moveBetweenLevels(School_t *school, int fromLevel, int toLevel, int studentIndex);


int Student_Sorting_Get_Option(void);


int Student_ApplySorting_OnWhat(void);


int compare_StudentNames(const void *a, const void *b);


void sortStudentsByName(Level_t *level);


void Students_Sorting_Byname_InLevel(School_t *school, int level);


int compare_StudentIds(const void *a, const void *b);


void sortStudentsById(Level_t *level);


void Students_Sorting_ByID_Inlevel(School_t *school, int level);


int calculateSumOfScores(const Student_t *student);


int compareStudentSumOfScores(const void *a, const void *b);


void sortStudentsBySumOfScores(Level_t *level);


void Student_Sorting_BySumOfScoresInLevel(School_t *school, int level);


void Loading_Bar(void);


void Students_Sorting_Algorithms(School_t *school,int type_sort,int apply_on);


int Student_Printing_GetOPtion(void);


void printOne_Student(const School_t *school, int level, int index);


void printAll_StudentsInLevel(const School_t *school, int level);


void printAll_StudentsInLevel2(const School_t *school, int level);


void PrintAll_StudentInschool(const School_t *xschool);


void Student_Printing_Algorithms(const School_t *school);


void PrintALL_Back(void);


void printOne_Student2(const School_t *school, int level, int index);


int Student_Perfect_IndexInLevel(const School_t *school, int level);


int Student_IdFoundInSchool(const School_t *school, int studentId);


int Teacher_IdFound(const School_t *school, int teacherId);


int Course_IdFound(const School_t *school, int courseId);


int Back_OR_CallingStudent(void);


void createLoadingAnimation(int duration, int interval);


void Calling_Info_print(const School_t *school, int level, int index);


StudentStatus_t Student_GetID_ToCall(const School_t *school, int *studentIndex,int *plevel);


int Student_NotAnswer_GetOption();


//StudentStatus_t Student_Call_Function(const School_t *school, int level, int index);


void About_Developers(void);


void About_Back(void);




















#endif // School_H_
