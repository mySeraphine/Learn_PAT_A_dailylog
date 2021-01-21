
#include<cstdlib>
#include<cstdio>

#include<string>

using namespace std;
typedef struct{                         //分数结构体 
    long long up;
    long long down;
}FEN;
long long gcd(long long a,long long b){//求最小公约数 
    return !b?a:gcd(b,a%b);
}
void yuefen(FEN *py){                   //约分成最简形式 
    long long y;
    if(py->up==0)                       //如果分子是0，令分母为1 
        py->down=1;
    else{
        y=gcd(abs(py->up),abs(py->down));//求分子分母绝对值的最大公约数，一定要绝对值之后求公约数 
        py->up/=y; py->down/=y;         //约分 
    }
}
void print_fen(FEN *pf){                //分数的打印 
    long long up=pf->up,down=pf->down;
    if(up==0){                          //如果是0，直接打0 
        putchar('0'); return;
    }
    if(up<0) putchar('(');              //如果是负数，打印括号 
    if(abs(up)>=down){                  //假分数 
        printf("%d",up/down);           //先打印整数部分 
        if(up%down)                     //如果不是整数，打印分数部分，一定要分子求绝对值 
            printf(" %d/%d",abs(up)%down,down);
    }
    else
        printf("%d/%d",up%down,down);   //真分数直接打印 
    if(up<0) putchar(')');              //负数括号配对 
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("1.txt","r",stdin);
#endif
    FEN a,b,temp;
    scanf("%lld/%lld %lld/%lld",&a.up,&a.down,&b.up,&b.down);
    yuefen(&a); yuefen(&b);

    temp.down=a.down*b.down;            //加法 
    temp.up=a.up*b.down+a.down*b.up;
    yuefen(&temp);                      //算完后要化简 
    print_fen(&a);printf(" + ");print_fen(&b);printf(" = ");print_fen(&temp);putchar('\n');

    temp.up=a.up*b.down-a.down*b.up;    //减法，只是分子需要重新计算 
    yuefen(&temp);
    print_fen(&a);printf(" - ");print_fen(&b);printf(" = ");print_fen(&temp);putchar('\n');

    temp.up=a.up*b.up;                  //乘法，只是分子需要重新计算 
    yuefen(&temp);
    print_fen(&a);printf(" * ");print_fen(&b);printf(" = ");print_fen(&temp);putchar('\n');

    if(b.up==0){                        //如果除0，特殊判定 
        print_fen(&a);printf(" / ");putchar('0');printf(" = ");printf("Inf");putchar('\n');
    }
    else{
        temp.down=a.down*b.up;          //除法运算 
        temp.up=a.up*b.down;
        if(temp.down<0){                //保证分子带正负号，分母总为正数 
            temp.down=-temp.down;
            temp.up=-temp.up;
        }
        yuefen(&temp);                  //约分并打印结果 
        print_fen(&a);printf(" / ");print_fen(&b);printf(" = ");print_fen(&temp);putchar('\n');
    }
    return 0;
}
