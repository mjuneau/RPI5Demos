#include <stdint.h>
#include <time.h>
#include <wiringPi.h>

void btISRCallback()
{
    digitalWrite(17,digitalRead(22));
}

int main()
{
    wiringPiSetupGpio();
    pinMode(22,INPUT);
    pinMode(17,OUTPUT);
    pullUpDnControl(22,PUD_UP);
    wiringPiISR(22,INT_EDGE_BOTH,btISRCallback);
    while(1)
    {

    }
    return 0;
}





//int main()
//{
//    wiringPiSetupGpio();
//    pinMode(22,INPUT);
//    pinMode(17,OUTPUT);
//    pullUpDnControl(22,PUD_UP);
//    while(1)
//    {
//        digitalWrite(17,digitalRead(22));
//    }
//    return 0;
//}



