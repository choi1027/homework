#include <stdio.h>   //printf,scanf를 사용하기 위해 해더 추가 
#include <stdlib.h>   //rnad ,srand를 사용하기 위해 해더 추가
#include <time.h>     // time을 사용하기 위해 해더 추가 

int main(void)
{
    int ball[3];             //정답 3개를 저장할 배열
    srand(time(NULL));   //난수 시드 초기화

    do {                            //중복없는 난수 3개 추가 
        ball[0] = rand() % 10;     //0~9의 숫자 랜덤 추가
        ball[1] = rand() % 10;     //0~9의 숫자 랜덤 추가  
        ball[2] = rand() % 10;      //0~9의 숫자 랜덤 추가 

    } while (ball[0] == ball[1] || ball[0] == ball[2] || ball[1] == ball[2]);    //생성된 숫자가 중복이면 다시 생성
    printf("baseball : %d %d\n", ball[0], ball[1], ball[2]);         // 숫자 3개 출력

    while (1)                                          //성공할때까지 반복
    {
        int input[3];
        printf("Enter the first number: ");          //첫 숫자 출력
        scanf_s("%d", &input[0]);                    //숫자 입력

        printf("Enter the second number: ");        //2번째 숫자 출력
        scanf_s("%d", &input[1]);                    //숫자 입력

        printf("Enter the third number: ");         //3번쨰 숫자 출력
        scanf_s("%d", &input[2]);                    //숫자 입력

        printf("input : %d %d %d\n", input[0], input[1], input[2]);  //숫자 3개 출력

        int strike_count = 0;         //스트라이크 초기화
        int ball_count = 0;             //볼 초기화
        int out_count = 3;             //아웃 초기화
        if (ball[0] == input[0])       // 스트라이크 카운트
        {
            strike_count = strike_count + 1;   //스트라이크 1증가
            out_count = out_count - 1;         //아웃 1감소
        }

        else if (ball[0] == input[1] || ball[0] == input[2]) {    //숫자가 있음 볼 위치는 다름
            ball_count + 1;          //볼 증가
            out_count - 1;           //볼 감소
        }
        if (ball[0] == input[1])     // 볼 카운트
        {
            ball_count = ball_count + 1;    //볼 1증가
            out_count = out_count - 1;   //볼 1감소
        }
        else if (ball[1] == input[0] || ball[1] == input[2]) {     //숫자가 같음 볼 위치는 다름
            ball_count + 1;               //볼 1증가
            out_count - 1;                //볼 1감소
        }
        if (ball[0] == input[2])     // 볼 카운트
        {
            ball_count = ball_count + 1;  //볼 1증가
            out_count = out_count - 1;    //볼 1감소
        }
        else if (ball[2] == input[0] || ball[2] == input[1]) {       //숫자가 같지만 위치 다름 볼
            ball_count + 1;          //볼 1증가
            out_count - 1;            //볼 1감소
        }

        if (ball[0] == input[0] && ball[1] == input[1] && ball[2] == input[2])   //숫자가 맞으면 홈런
        {
            printf("Home Run~\n");  //홈런 메시지 출력
            break;   // 반복 종료
        }
        else
        {
            printf("%d Strike, %d Ball, %d Out\n", strike_count, ball_count, out_count);   //스트라이크 볼 아웃 결과 출력
        }
    }

    return 0;    //프로그램 종료
}
    
