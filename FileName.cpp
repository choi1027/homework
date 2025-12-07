#include <stdio.h>      //ㅐPRINTF, scanf를 사용하기 위해서 헤더 추가
#include <stdlib.h>    // rand, srand를 사용하기 위해서 헤더 추가
#include <time.h>   // time 함수를 사용하기 위해서 헤더 추가

int main(void)      //프로그램을 실행하는 main 함수
{                   //메인함수의 시작
    int ball[3]; // 3개의 난수 저장 배열
    srand(time(NULL)); // 난수 초기화
    // 중복 없는 3자리 난수 생성
    do {  //밑에 와일문 시작전에 반복
        ball[0] = rand() % 10;    //첫번쨰 0-9랜덤숫자
        ball[1] = rand() % 10;    //두번째 0-9랜덤숫자
         ball[2] = rand() % 10;   //세번쨰 0-9랜덤숫자
    } while (ball[0] == ball[1] || ball[0] == ball[2] || ball[1] == ball[2]);  //세 숫자가 겹치면 다시만들기 반복

    //printf("baseball : %d %d %d\n", ball[0], ball[1], ball[2]); // 정답 확인용(테스트시만) 숫자야구게임 정답알려주는것

    int input[3];           //입력 숫자 저장
    int strike_count = 0;  //스트라이크 횟수 저장
    int ball_count = 0;   //볼 횟수 저장
    int out_count = 0;    //아웃 횟수 저장
    int try_count = 0;    //시도 횟수 저장

    clock_t start, end; //시간을 재기위한 함수 시작과 끝을 표시
    start = clock(); // 게임 시작 시간 기록

    while (1) {                 //게임을 홈런을 맞출때까지 1번 계속 반복함
        printf("\n숫자 3개를 입력하세요 (공백으로 구분): ");    //숫자 3개 입력을 표시
        scanf_s("%d %d %d", &input[0], &input[1], &input[2]); //숫자 3개를 기억하기

        strike_count = 0;        //스트라이크 횟수를 0으로 초기화
        ball_count = 0;         //볼 횟수를 0으로 초기화

        // strike, ball 판정
        for (int i = 0; i < 3; i++) {   //숫자랑 위치가 같으면
            if (input[i] == ball[i]) {   //스트라이크 판정
                strike_count++;   //스트라이크 횟수 증가
            }
            else if (input[i] == ball[(i + 1) % 3] || input[i] == ball[(i + 2) % 3]) {  //숫자는 같지만 위치가 다르면
                ball_count++;    //볼 횟수 증가 
            }
        }

        out_count = 3 - (strike_count + ball_count);  //아웃카운트 3개에서 볼이랑 스트 합친걸 뺌

        try_count++;            //재시도 횟수 추가

        if (strike_count == 3) {    //스트라이크가 3개가 뜨면
            end = clock(); // 게임 종료 시간 기록            
            double elapsed_sec = (double)(end - start) / CLOCKS_PER_SEC;  //이 게임에 걸린시간을 초로 표시
            printf("Home Run! %d번 만에 맞췄습니다!\n", try_count);      //d번 만에 맞췄습니다 출력 트라이 횟수도 나옴
            printf("%f 초 시간이 걸렸습니다.\n", elapsed_sec);           //f초  시간이 걸렸습니다 출력 초 시간도 나옴
            break;                                                        //프로그램 반복 종료
        }
        else {
            printf("%d Strike, %d Ball, %d Out\n", strike_count, ball_count, out_count);  //결과에 따라 스트라이 볼 아웃 출력
        }
    }
    return 0;  //프로그램 종료
}
