/* 프로그래머스 챌린지  | 주차 요금 계산하기 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int notouttime[10000];

int* solution(int fees[], size_t fees_len, const char* records[], size_t records_len) {

    int carouttime[10000] = {0, };
    int carintime[10000] = {0, };

    for(int k = 0; k < 10000; ++k)
    {
        carintime[k] = -1;
        carouttime[k] = -42;
    }
    
    int numbers = 0;
    char *flag;
    int cnt = 0;
    int time;
    int outtime;
    int endtime = (23 * 60) + 59;

    int i = 0;
    while (i < records_len)
    {
        time = atoi(&records[i][0]) * 60 + atoi(&records[i][3]);
        printf("time atoi: %d\n ", time);
        numbers = atoi(&records[i][6]);
        printf("numb :%d\n", numbers);
        if (records[i][11] == 'I')
        {
            if (carintime[numbers] == -1)
                cnt++;
            carintime[numbers] = time;
            printf("cnt : %d\n", cnt);
            printf("car in time : %d\n", carintime[numbers]);
        }
        else if (records[i][11] == 'O')
        {
            outtime = time - carintime[numbers];
            printf("outtime : %d\n", outtime);
            // notouttime[numbers] = outtime;
            notouttime[numbers] = outtime;
            carouttime[numbers] = outtime;
            carintime[numbers] = -42;
        }
        i++;
    }
    for (int j=0; j<10000; j++)
    {
        if (carintime[j] != -1 && carintime[j] != -42)
        {
            
            // carouttime[j] += endtime - carintime[j];
            notouttime[j] += endtime - carintime[j];
            // printf("index:%d\n", carouttime[j]);
        }
    }     
    
    int* ans = (int*)calloc(cnt, sizeof(int));

    int j = 0;
    int fee = 0;

    for(int i=0; i<10000; i++)
    {
        if (notouttime[i] != -42)
        {
            fee = fees[1];
            if (notouttime[i] > fees[0])
            {
                if ((notouttime[i] - fees[0]) % fees[2] == 0)
                    fee += ((notouttime[i] - fees[0]) / fees[2]) * fees[3];
                else
                    fee += ((notouttime[i] - fees[0]) / fees[2] + 1) * fees[3];
                ans[j++] = fee;
                fee = 0;
            }
            else
                ans[j++] = fee;
        }
    }
    return ans;
}

int  main()
{
    int fees1[4] = {180, 5000, 10, 600};
    const char *record[] = {"05:34 6961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"};
    int fees_len = 4;
    int record_len = 9;

    int *ans = solution(fees1, fees_len, record, record_len);
    int i = 0;
    while(i < 3)
    {  
        printf("ans {%d} : [%d]\n", i, ans[i]);
        i++;
    }

}




