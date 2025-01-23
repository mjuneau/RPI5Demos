#include <lgpio.h>
#include <stdio.h>
#include <inttypes.h>
int h;
void btISRCallBack(int nbEvt, lgGpioAlert_p evt, void *data)
{
       int i;
       uint32_t * userdata = (uint32_t*)data;
       lgGpioWrite(h,17,evt[0].report.level);
       for (i=0; i<nbEvt; i++)
       {
          printf("u=%d t=%" PRIu64 " c=%d g=%d l=%d f=%d (%d of %d)\n",
             *userdata, evt[i].report.timestamp, evt[i].report.chip,
             evt[i].report.gpio, evt[i].report.level,
             evt[i].report.flags, i+1, nbEvt);
             userdata[0]++;
        }
}

int main(void)
{
    uint32_t tmpData = 0;
    h = lgGpiochipOpen(0);
    lgGpioClaimOutput(h,0,17,0);
    lgGpioClaimInput(h,0,22);
    lgGpioSetAlertsFunc(h, 22, btISRCallBack, &tmpData);
    lgGpioClaimAlert(h, 0, LG_BOTH_EDGES, 22, -1);
    while(1)
    {

    }
}


//int main(void)
//{
//    h = lgGpiochipOpen(0);
//    lgGpioClaimOutput(h,0,17,0);
//    lgGpioClaimInput(h,0,22);
//    while(1)
//    {
//        lgGpioWrite(h,17,lgGpioRead(h,22));
//    }
//}


//#include <lgpio.h>
//#include <stdio.h>
//#include <inttypes.h>
//int h;
//void btISRCallBack(int nbEvt, lgGpioAlert_p evt, void *data)
//{
//   int i;
//   uint32_t * userdata = (uint32_t*)data;
//   lgGpioWrite(h,17,evt[0].report.level);
//   for (i=0; i<nbEvt; i++)
//   {
//      printf("u=%d t=%" PRIu64 " c=%d g=%d l=%d f=%d (%d of %d)\n",
//         *userdata, evt[i].report.timestamp, evt[i].report.chip,
//         evt[i].report.gpio, evt[i].report.level,
//         evt[i].report.flags, i+1, nbEvt);
//         userdata[0]++;
//   }
//}

//int main(void)
//{
//    uint32_t tmpData = 0;
//    h = lgGpiochipOpen(0);
//    lgGpioClaimOutput(h,0,17,0);
//    lgGpioClaimInput(h,0,22);
//    lgGpioSetAlertsFunc(h, 22, btISRCallBack, &tmpData);
//    lgGpioClaimAlert(h, 0, LG_BOTH_EDGES, 22, -1);
//    while(1)
//    {
//        //if(lgGpioRead(h,22))
//            //lgGpioWrite(h,17,1);
//        //else
//            //lgGpioWrite(h,17,0);
//    }
//}

