#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <conio.h>




void Play_Sound_Back(void)
{
     PlaySound(TEXT("Sound/Spin.wav"),NULL,SND_ASYNC);
}



void Stop_Sound(void)
{
    PlaySound(NULL, NULL, SND_PURGE);
}




void Play_Sound_click_open(void)
{
     PlaySound(TEXT("Sound/click_open.wav"),NULL,SND_ASYNC);
}






void Play_Sound_Correct(void)
{
     PlaySound(TEXT("Sound/Correct.wav"),NULL,SND_ASYNC);
}



void Play_Sound_Slid(void)
{
     PlaySound(TEXT("Sound/Slid.wav"),NULL,SND_ASYNC);
}


void Play_Sound_Fault(void)
{
     PlaySound(TEXT("Sound/Fault.wav"),NULL,SND_ASYNC);
}


void Play_Sound_telephone(void)
{
     PlaySound(TEXT("Sound/telephonemerg.wav"),NULL,SND_ASYNC);
}


void Play_Sound_Leve_Palestina(void)
{
     PlaySound(TEXT("Sound/Leve_Palestina.wav"),NULL,SND_ASYNC);
}


void Play_Sound_noanswer(void)
{
     PlaySound(TEXT("Sound/noanswer.wav"),NULL,SND_ASYNC);
}



