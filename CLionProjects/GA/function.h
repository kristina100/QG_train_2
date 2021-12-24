//
// Created by HUAWEI on 2021-11-08.
//

#ifndef GA_FUNCTION_H
#define GA_FUNCTION_H
/*
Benchmark functions:
1---  unconstrained functions
50--  constrained functions
101-  rotated functions
*/

const double PI = 3.1415926535897932384626;


//unconstrained functions------------------------------------------------------------
double f1(SOLU *c)
{
    countEval++;
    //F1
    int i;
    double temp = 0;

    for (i = 0; i < nvars; i++)
        temp += c->x[i]*c->x[i];

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f2(SOLU *c)
{
    countEval++;
    //F2
    int i;

    double temp=0,temp1=1.0;
    for (i = 0 ; i < nvars; i++) {
        temp+=fabs(c->x[i]);
        temp1*=fabs(c->x[i]);
    }
    temp+=temp1;

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f3(SOLU *c)
{
    countEval++;
    //F3
    int i,j;
    double temp=0.0,temp1;

    for (i = 0; i < nvars; i++) {
        temp1=0.0;
        for(j=0;j<=i;j++) {
            temp1+=c->x[j];
        }
        temp1*=temp1;
        temp+=temp1;
    }

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f4(SOLU *c)
{
    countEval++;
    //F4
    int i;
    double temp = 0.0;

    for(i=0;i<nvars;i++) {
        if(temp<fabs(c->x[i])) temp=fabs(c->x[i]);
    }

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }
    return temp;
}

double f5(SOLU *c)
{
    countEval++;
    //F5
    int i,j=nvars-1;
    double temp=0.0;

    for(i=0;i<j;i++) {
        temp+=100*pow((c->x[i+1]-c->x[i]*c->x[i]),2)+pow((c->x[i]-1),2);
    }

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f6(SOLU *c)
{
    countEval++;
    //F6
    int i;
    double temp = 0.0;

    for(i=0;i<nvars;i++) {
        temp+=((int)(c->x[i]+0.5))*((int)(c->x[i]+0.5));
    }

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f7(SOLU *c)
{
    countEval++;
    //F7
    int i;
    double temp = 0.0;

    for(i=0;i<nvars;i++) {
        temp+=(i+1)*pow(c->x[i],4);
    }

    temp+=rand()/(double)RAND_MAX;

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f8(SOLU *c)
{
    countEval++;
    //F8
    int i;
    double temp=0.0;

    for (i = 0; i < nvars; i++)	{
        temp -= c->x[i]*sin(sqrt(fabs(c->x[i])));
    }
    //temp += 418.9829*nvars;

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f9(SOLU *c)
{
    countEval++;
    //F9
    int i;
    double temp=0.0;
    for (i = 0; i < nvars; i++) {
        temp+=(c->x[i]*c->x[i]-10*cos(2*PI*c->x[i])+10);
    }

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f10(SOLU *c)
{
    countEval++;
    //F10
    int i;
    double temp=0.0, t1=0.0, t2=0.0;

    for(i=0;i<nvars;i++) {
        t1+= c->x[i]*c->x[i];
        t2+= cos(2*PI*c->x[i]);
    }
    temp= -20*exp(-0.2*sqrt(t1/nvars)) -exp(t2/nvars) + 20 + exp(1);

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f11(SOLU *c)
{
    countEval++;
    //F11
    int i;
    double temp=0.0;
    double t1=0.0,t2=1.0;

    for(i=0;i<nvars;i++) t1+=c->x[i]*c->x[i];
    for(i=0;i<nvars;i++) t2*=cos(c->x[i]/sqrt(i+1));

    temp+=1/4000.0*t1-t2+1;

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

//F12
double U(double x,double a,double k,double m) {
    if(x>a)return k*pow((x-a),m);
    else if(x>=-a&&x<=a)return 0;
    else return k*pow((-x-a),m);
}

double Y(double x) {
    return 1+1/4.0*(x+1);
}

double f12(SOLU *c)
{
    countEval++;
    int i,j;
    double temp=0.0, t=0.0;

    for(i=0;i<nvars;i++) {
        t+=U(c->x[i],10,100,4);
    }
    double t2=0.0;
    j=nvars-1;
    for(i=0;i<j;i++) {
        t2+=pow(Y(c->x[i])-1,2)*(1+10*pow((sin(PI*Y(c->x[i+1]))),2));
    }
    temp+=PI/(double)nvars*(10*pow(sin(PI*Y(c->x[0])),2)+t2+pow(Y(c->x[nvars-1])-1,2))+t;

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f13(SOLU *c)
{
    countEval++;
    int i,j;
    double temp,temp1=0.0,temp2=0.0;

    j=nvars-1;
    for(i=0;i<j;i++) {
        temp1+=(c->x[i]-1)*(c->x[i]-1)*(1+sin(3*PI*c->x[i+1])*sin(3*PI*c->x[i+1]));
    }

    for(i=0;i<nvars;i++) {
        temp2+=U(c->x[i],5,100,4);
    }
    temp=sin(3*PI*c->x[0])*sin(3*PI*c->x[0]);
    temp+=temp1;
    temp+=(c->x[nvars-1]-1)*(c->x[nvars-1]-1)*(1+sin(2*PI*c->x[nvars-1])*sin(2*PI*c->x[nvars-1]));
    temp*=0.1;
    temp+=temp2;

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

//F14    2 dimensions
int a1[2][25] = {
        {	-32,-16,0,16,32,
                -32,-16,0,16,32,
                -32,-16,0,16,32,
                -32,-16,0,16,32,
                -32,-16,0,16,32
        },
        {
             -32,-32,-32,-32,-32,
                -16,-16,-16,-16,-16,
                0,0,0,0,0,
                16,16,16,16,16,
                32,32,32,32,32
        }
};

double f14(SOLU *c)
{
    countEval++;
    int i,j;
    double temp=0, temp1;
    for(j=0;j<25;j++) {
        temp1=j+1;

        for(i=0;i<2;i++) {
            temp1+=pow((c->x[i]-a1[i][j]),6);
        }

        temp1=1.0/temp1;
        temp+=temp1;
    }
    temp+=1.0/500;
    temp=1.0/temp;

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}


double a_kow[11] =
        {0.1957, 0.1947, 0.1735, 0.1600, 0.0844, 0.0627, 0.0456, 0.0342, 0.0323, 0.0235, 0.0246 };

double b_kow[11] =
        {4, 2, 1, 0.5, 0.25, double(1.0/6.0), 0.125, 0.1, double(1.0/12.0), double(1.0/14.0), 0.0625};

double f15(SOLU *c)
{
    countEval++;
    //f15   4 dimensions
    int i;
    double temp=0.0;

    for(i=0; i<11; i++) {
        temp+=pow((a_kow[i]-((c->x[0]*(b_kow[i]*b_kow[i]+b_kow[i]*c->x[1]))
                             /(b_kow[i]*b_kow[i]+b_kow[i]*c->x[2]+c->x[3]))) ,2);
    }

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f16(SOLU *c)
{
    countEval++;
    //F16    2 dimensions
    double temp;

    temp=4*c->x[0]*c->x[0]-2.1*pow(c->x[0],4)+1/3.0*pow(c->x[0],6)+
         c->x[0]*c->x[1]-4*c->x[1]*c->x[1]+4*pow(c->x[1],4);

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f17(SOLU *c)
{
    countEval++;
    //F17    2 dimensions
    double temp;

    temp=pow((c->x[1]-5.1/(4*PI*PI)*c->x[0]*c->x[0]+5/PI*c->x[0]-6),2)+
         10*(1-1/(8*PI))*cos(c->x[0])+10;

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double a_shekel[10][4] = {
        4,4,4,4,
        1,1,1,1,
        8,8,8,8,
        6,6,6,6,
        3,7,3,7,
        2,9,2,9,
        5,5,3,3,
        8,1,8,1,
        6,2,6,2,
        7,3.6,7,3.6
};

double c_shekel[] = {
        0.1,0.2,0.2,0.4,0.4,0.6,0.3,0.7,0.5,0.5
};

double f18(SOLU *c)
{
    countEval++;
    //F18    4 dimensions
    int i;
    double temp=0.0;
    double X[5][4];

    for(i=0;i<5;i++) {
        X[i][0]=c->x[0];
        X[i][1]=c->x[1];
        X[i][2]=c->x[2];
        X[i][3]=c->x[3];
    }
    for(i=0;i<5;i++) {
        X[i][0]-=a_shekel[i][0];
        X[i][1]-=a_shekel[i][1];
        X[i][2]-=a_shekel[i][2];
        X[i][3]-=a_shekel[i][3];
    }

    for(i=0;i<5;i++) {
        temp+=1.0/(X[i][0]*X[i][0]+X[i][1]*X[i][1]+X[i][2]*X[i][2]+X[i][3]*X[i][3]+c_shekel[i]);
    }
    temp=-temp;

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f19(SOLU *c)
{
    countEval++;
    //F19    4 dimensions
    int i;
    double temp=0.0;
    double X[7][4];

    for(i=0;i<7;i++) {
        X[i][0]=c->x[0];
        X[i][1]=c->x[1];
        X[i][2]=c->x[2];
        X[i][3]=c->x[3];
    }
    for(i=0;i<7;i++) {
        X[i][0]-=a_shekel[i][0];
        X[i][1]-=a_shekel[i][1];
        X[i][2]-=a_shekel[i][2];
        X[i][3]-=a_shekel[i][3];
    }

    for(i=0;i<7;i++) {
        temp+=1.0/(X[i][0]*X[i][0]+X[i][1]*X[i][1]+X[i][2]*X[i][2]+X[i][3]*X[i][3]+c_shekel[i]);
    }
    temp=-temp;

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f20(SOLU *c)
{
    countEval++;
    //F20    4 dimensions
    int i;
    double temp=0.0;
    double X[10][4];

    for(i=0;i<10;i++) {
        X[i][0]=c->x[0];
        X[i][1]=c->x[1];
        X[i][2]=c->x[2];
        X[i][3]=c->x[3];
    }
    for(i=0;i<10;i++) {
        X[i][0]-=a_shekel[i][0];
        X[i][1]-=a_shekel[i][1];
        X[i][2]-=a_shekel[i][2];
        X[i][3]-=a_shekel[i][3];
    }

    for(i=0;i<10;i++) {
        temp+=1.0/(X[i][0]*X[i][0]+X[i][1]*X[i][1]+X[i][2]*X[i][2]+X[i][3]*X[i][3]+c_shekel[i]);
    }
    temp=-temp;

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f21(SOLU *c)
{
    countEval++;
    //ogaF7    100 dimensions
    int i;
    double temp,tmax=0.0;
    for(i=0;i<nvars;i++) {
        tmax+=sin(c->x[i])*pow(sin(i*c->x[i]*c->x[i]/(double)PI),20);
    }
    temp=-tmax;

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f22(SOLU *c)
{
    countEval++;
    //ogaF9    100 dimensions
    int i;
    double temp,tmax=0.0;

    for(i=0;i<nvars;i++) {
        tmax+=pow(c->x[i],4)-16*c->x[i]*c->x[i]+5*c->x[i];
    }
    temp=tmax/nvars;

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f23(SOLU *c)   // 2 dimensions
{
    countEval++;
    int i;
    double s=0.0, t=0.0;
    double temp;

    for(i=1;i<=5;i++) {
        s+= i*cos((i+1)*c->x[0] +i);
        t+= i*cos((i+1)*c->x[1] +i);
    }
    temp = s*t;

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f24(SOLU *c)   //  4 dimensions
{
    countEval++;
    double s=0.0, t=0.0;
    double temp;

    temp = 100*pow(c->x[1]-c->x[0]*c->x[0],2) +pow(1-c->x[0],2) + 90*pow(c->x[3]-c->x[2]*c->x[2],2)
           + pow(1-c->x[2],2) + 10.1*(pow(c->x[1]-1,2) +pow(c->x[3]-1,2))
           + 19.8*(c->x[1]-1)*(c->x[3]-1);

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f25(SOLU *c)
{
    countEval++;
    //ogaF8    100 dimensions
    int i,j,r1,r2;
    double temp1,temp2,temp;
    double r3[NVARS];

    for(i=0;i<nvars;i++) r3[i]=(rand()/(double)RAND_MAX*2.0-1)*PI;

    temp = 0.0;
    for(i=0;i<nvars;i++) {
        temp1 = 0.0;
        temp2 = 0.0;
        for(j=0;j<nvars;j++) {
            r1 = rand()%201-100;
            r2 = rand()%201-100;
            temp1 += r1*sin(r3[j]) + r2*cos(r3[j]);
            temp2 += r1*sin(c->x[j]) + r2*cos(c->x[j]);
        }
        temp += pow(temp1-temp2,2);
    }

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}
//=============================================================================
//constrained problems---------------------------------------------------------
double f50(SOLU *c)  //nvars=13
{
    countEval++;
    //Test case 1
    int i;
    double temp=0.0;

    temp = c->x[0]+c->x[1]+c->x[2]+c->x[3];

    temp = temp - c->x[0]*c->x[0] -c->x[1]*c->x[1] -c->x[2]*c->x[2] -c->x[3]*c->x[3];

    for(i=4;i<13;i++) {
        temp -= c->x[i];
    }

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}
double H50(SOLU *c) {
    double t,s=0.0;

    t = 2*c->x[0] +2*c->x[1] +c->x[9] +c->x[10];
    if(t>10) s += t-10;

    t = 2*c->x[0] +2*c->x[2] +c->x[9] +c->x[11];
    if(t>10) s += t-10;

    t = 2*c->x[1] +2*c->x[2] +c->x[10] +c->x[11];
    if(t>10) s += t-10;

    t = -8*c->x[0] + c->x[9];
    if(t>0) s += t;

    t = -8*c->x[1] + c->x[10];
    if(t>0) s += t;

    t = -8*c->x[2] + c->x[11];
    if(t>0) s += t;

    t = -2*c->x[3] - c->x[4] + c->x[9];
    if(t>0) s += t;

    t = -2*c->x[5] - c->x[6] + c->x[10];
    if(t>0) s += t;

    t = -2*c->x[7] - c->x[8] + c->x[11];
    if(t>0) s += t;

    if(s>0) s*=30;

    return s;
}

double f51(SOLU *c)  //nvars=8
{
    countEval++;
    //Test case 2
    double temp=0.0;

    temp = c->x[0]+c->x[1]+c->x[2];

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}
double H51(SOLU *c) {
    double t,s=0.0;

    t = 1-0.0025*(c->x[3]+c->x[5]);
    if(t<0) s+=-t;

    t = 1-0.0025*(c->x[4]+c->x[6]-c->x[3]);
    if(t<0) s+=-t;

    t = 1 - 0.01*(c->x[7]-c->x[4]);
    if(t<0) s+=-t;

    t = c->x[0]*c->x[5] -833.33252*c->x[3] -100*c->x[0] +83333.333;
    if(t<0) s+=-t;

    t = c->x[1]*c->x[6] -1250*c->x[4] -c->x[1]*c->x[3] +1250*c->x[3];
    if(t<0) s+=-t;

    t = c->x[2]*c->x[7] -1250000 -c->x[2]*c->x[4] +2500*c->x[4];
    if(t<0) s+=-t;

    if(s>0) s *= 50000;

    return s;
}

double f52(SOLU *c)  //nvars=7
{
    countEval++;
    //Test case 3
    double temp=0.0;

    temp = pow(c->x[0]-10,2) + 5*pow(c->x[1]-12,2) +pow(c->x[2],4) +3*pow(c->x[3]-11,2) +10*pow(c->x[4],6) +7*pow(c->x[5],2) +pow(c->x[6],4) -4*c->x[5]*c->x[6] -10*c->x[5] -8*c->x[6];

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}
double H52(SOLU *c) {
    double t,s=0.0;

    t = 127 -2*pow(c->x[0],2) -3*pow(c->x[1],4) -c->x[2] -4*pow(c->x[3],2) -5*c->x[4];
    if(t<0) s+=-t;

    t = 282 -7*c->x[0] -3*c->x[1] -10*pow(c->x[2],2) -c->x[3] +c->x[4];
    if(t<0) s+=-t;

    t = 196 -23*c->x[0] -pow(c->x[1],2) -6*pow(c->x[5],2) +8*c->x[6];
    if(t<0) s+=-t;

    t = -4*pow(c->x[0],2) -pow(c->x[1],2) +3*c->x[0]*c->x[1] -2*pow(c->x[2],2) -5*c->x[5] +11*c->x[6];
    if(t<0) s+=-t;

    if(s!=0) s*=1.5;

    return s;
}

double f54(SOLU *c)  //nvars=10
{
    countEval++;
    //Test case 5
    double temp=0.0;

    temp = c->x[0]*c->x[0] +c->x[1]*c->x[1] +c->x[0]*c->x[1] -14*c->x[0] -16*c->x[1] +(c->x[2]-10)*(c->x[2]-10)
           +4*(c->x[3]-5)*(c->x[3]-5) +(c->x[4]-3)*(c->x[4]-3) +2*(c->x[5]-1)*(c->x[5]-1) +5*c->x[6]*c->x[6] +
           7*(c->x[7]-11)*(c->x[7]-11) +2*(c->x[8]-10)*(c->x[8]-10) +(c->x[9]-7)*(c->x[9]-7) +45;

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}
double H54(SOLU *c) {
    double t,s=0.0;

    t = 105 -4*c->x[0] -5*c->x[1] +3*c->x[6] -9*c->x[7];
    if(t<0) s+=-t;

    t = -10*c->x[0] +8*c->x[1] +17*c->x[6] -2*c->x[7];
    if(t<0) s+=-t;

    t = 8*c->x[0] -2*c->x[1] -5*c->x[8] +2*c->x[9] +12;
    if(t<0) s+=-t;

    t = -3*(c->x[0]-2)*(c->x[0]-2) - 4*pow(c->x[1]-3,2) -2*pow(c->x[2],2) +7*c->x[3] +120;
    if(t<0) s+=-t;

    t = -5*c->x[0]*c->x[0] -8*c->x[1] -pow(c->x[2]-6,2) +2*c->x[3] +40;
    if(t<0) s+=-t;

    t = -c->x[0]*c->x[0] -2*pow(c->x[1]-2,2) +2*c->x[0]*c->x[1] -14*c->x[4] +6*c->x[5];
    if(t<0) s+=-t;

    t = -0.5*pow(c->x[0]-8,2) -2*pow(c->x[1]-4,2) -3*c->x[4]*c->x[4] +c->x[5] +30;
    if(t<0) s+=-t;

    t = 3*c->x[0] -6*c->x[1] -12*pow(c->x[8]-8,2) +7*c->x[9];
    if(t<0) s+=-t;

    if(s!=0) s*=10;

    return s;
}

double f55(SOLU *c)  //nvars=3
{
    countEval++;
    //Test case 6
    double temp=0.0;

    temp = (100-pow(c->x[0]-5,2) -pow(c->x[1]-5,2) -pow(c->x[2]-5,2))/100;

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}
double H55(SOLU *c) {
    double t,s=0.0;
    int pp[5]={1,3,5,7,9};
    int qq[5]={1,3,5,7,9};
    int rr[5]={1,3,5,7,9};
    int i,j,k;

    for(i=0;i<5;i++) {
        for(j=0;j<5;j++) {
            for(k=0;k<5;k++) {
                t = pow(c->x[0]-pp[i],2) +pow(c->x[1]-qq[j],2) +pow(c->x[2]-rr[k],2);
                if(t>0.25) s+=t;
            }
        }
    }

    s *=10;

    return s;
}

//================================================================================
//rotated functions-----------------------------------------------------------------
double ME[100][100];
double MTurn[100][100];
double MResult[100][100];
double y[NVARS];

//create a single rotation matrix
void MRot(int i,int j) {
    int k,m;
    for(k=0;k<nvars;k++) {
        for(m=0;m<nvars;m++) MTurn[k][m] = ME[k][m];
    }

    //draw a random angle
    double alpha = (rand()/(double)RAND_MAX - 0.5) * PI * 0.5;

    MTurn[j][j] = MTurn[i][i] = cos(alpha);
    MTurn[i][j] = MTurn[j][i] = sin(alpha);
    MTurn[j][i] = -MTurn[j][i];
}

void MulMatrix() {
    int i,j,k;
    double** m = new double*[nvars];
    for(i=0;i<nvars;i++)
        m[i] = new double[nvars];

    for(i=0;i<nvars;i++) {
        for(j=0;j<nvars;j++) m[i][j] = 0;
    }

    for(i=0;i<nvars;i++) {
        for(j=0;j<nvars;j++) {
            for(k=0;k<nvars;k++) m[i][j] += MResult[i][k]*MTurn[k][j];
        }
    }

    for(i=0;i<nvars;i++) {
        for(j=0;j<nvars;j++) MResult[i][j] = m[i][j];
    }
    delete []m;
}

void createMatrix() {
    int i,j;

    for(i=0;i<nvars;i++) {
        for(j=0;j<nvars;j++) ME[i][j] = MResult[i][j] = 0;
        MResult[i][i] = ME[i][i] = 1;

    }

    for(i=1;i<nvars;i++) {
        MRot(0,i);		//use MTurn[][], create a single rotation matrix
        MulMatrix();	//use MResult[][] <- MRsult[][]*MTurn[][]
    }

    for(i=1;i<(nvars-1);i++) {
        MRot(i,nvars-1);
        MulMatrix();
    }

    //for(i=0;i<nvars;i++) {
    //	for(j=0;j<nvars;j++) printf("%g ",MResult[i][j]);
    //	printf("\n");
    //}
}

double f101(SOLU *c)
{
    countEval++;
    //F1
    int i,j;
    double temp = 0;

    for(i=0;i<nvars;i++) {
        y[i] = 0;
        for(j=0;j<nvars;j++) y[i] += MResult[i][j]*c->x[j];
    }

    for (i = 0; i < nvars; i++) temp+=y[i]*y[i];

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f102(SOLU *c)
{
    countEval++;
    //F2
    int i,j;
    double temp = 0,temp1=1.0;

    for(i=0;i<nvars;i++) {
        y[i] = 0;
        for(j=0;j<nvars;j++) y[i] += MResult[i][j]*c->x[j];
    }

    for (i = 0 ; i < nvars; i++) {
        temp+=fabs(y[i]);
        temp1*=fabs(y[i]);
    }
    temp+=temp1;

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f103(SOLU *c)
{
    countEval++;
    //F3
    int i,j;
    double temp = 0,temp1=1.0;

    for(i=0;i<nvars;i++) {
        y[i] = 0;
        for(j=0;j<nvars;j++) y[i] += MResult[i][j]*c->x[j];
    }

    for (i = 0; i < nvars; i++) {
        temp1=0.0;
        for(j=0;j<=i;j++) {
            temp1+=y[j];
        }
        temp1*=temp1;
        temp+=temp1;
    }

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f104(SOLU *c)
{
    countEval++;
    //F4
    int i,j;
    double temp = 0;

    for(i=0;i<nvars;i++) {
        y[i] = 0;
        for(j=0;j<nvars;j++) y[i] += MResult[i][j]*c->x[j];
    }

    for(i=0;i<nvars;i++) {
        if(temp<fabs(y[i])) temp=fabs(y[i]);
    }

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f105(SOLU *c)
{
    countEval++;
    //F5
    int i,j;
    double temp = 0;

    for(i=0;i<nvars;i++) {
        y[i] = 0;
        for(j=0;j<nvars;j++) y[i] += MResult[i][j]*c->x[j];
    }

    for(i=0;i<nvars-1;i++) {
        temp+=100*pow((y[i+1]-y[i]*y[i]),2)+pow((y[i]-1),2);
    }

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f106(SOLU *c)
{
    countEval++;
    //F6
    int i,j;
    double temp = 0;

    for(i=0;i<nvars;i++) {
        y[i] = 0;
        for(j=0;j<nvars;j++) y[i] += MResult[i][j]*c->x[j];
    }

    for(i=0;i<nvars;i++) {
        temp+=((int)(y[i]+0.5))*((int)(y[i]+0.5));
    }

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f107(SOLU *c)
{
    countEval++;
    //F7
    int i,j;
    double temp = 0;

    for(i=0;i<nvars;i++) {
        y[i] = 0;
        for(j=0;j<nvars;j++) y[i] += MResult[i][j]*c->x[j];
    }

    for(i=0;i<nvars;i++) {
        temp+=(i+1)*pow(y[i],4);
    }

    temp+=rand()/(double)RAND_MAX;

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f108(SOLU *c)
{
    countEval++;
    //F8
    int i,j;
    double temp = 0;

    for(i=0;i<nvars;i++) {
        y[i] = 0;
        for(j=0;j<nvars;j++) y[i] += MResult[i][j]*c->x[j];
    }

    for (i = 0; i < nvars; i++) {
        temp -= y[i]*sin(sqrt(fabs(y[i])));
    }

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f109(SOLU *c)
{
    countEval++;
    //F9
    int i,j;
    double temp = 0;

    for(i=0;i<nvars;i++) {
        y[i] = 0;
        for(j=0;j<nvars;j++) y[i] += MResult[i][j]*c->x[j];
    }

    for (i = 0; i < nvars; i++) {
        temp+=(y[i]*y[i]-10*cos(2*PI*y[i])+10);
    }

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f110(SOLU *c)
{
    countEval++;
    //F10
    int i,j;
    double temp = 0, t1=0.0, t2=0.0;

    for(i=0;i<nvars;i++) {
        y[i] = 0;
        for(j=0;j<nvars;j++) y[i] += MResult[i][j]*c->x[j];
    }

    for(i=0;i<nvars;i++) {
        t1+= y[i]*y[i];
        t2+= cos(2*PI*y[i]);
    }
    temp= -20*exp(-0.2*sqrt(t1/nvars)) -exp(t2/nvars) + 20 + exp(1);

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f111(SOLU *c)
{
    countEval++;
    //F11
    int i,j;
    double temp = 0,t1=0.0,t2=1.0;

    for(i=0;i<nvars;i++) {
        y[i] = 0;
        for(j=0;j<nvars;j++) y[i] += MResult[i][j]*c->x[j];
    }

    for(i=0;i<nvars;i++) t1+=y[i]*y[i];
    for(i=0;i<nvars;i++) t2*=cos(y[i]/sqrt(i+1));

    temp+=1/4000.0*t1-t2+1;

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

//F12
double f112(SOLU *c)
{
    countEval++;
    int i,j;
    double temp = 0, t=0.0;

    for(i=0;i<nvars;i++) {
        y[i] = 0;
        for(j=0;j<nvars;j++) y[i] += MResult[i][j]*c->x[j];
    }

    for(i=0;i<nvars;i++) {
        t+=U(y[i],10,100,4);
    }
    double t2=0.0;
    for(i=0;i<nvars-1;i++)
    {
        t2+=pow(Y(y[i])-1,2)*(1+10*pow((sin(PI*Y(y[i+1]))),2));
    }
    temp+=(double)PI/nvars*(10*pow(sin(PI*Y(y[0])),2)+t2+pow(Y(y[nvars-1])-1,2))+t;

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f113(SOLU *c)
{
    countEval++;
    int i,j;
    double temp = 0,temp1=0,temp2=0;

    for(i=0;i<nvars;i++) {
        y[i] = 0;
        for(j=0;j<nvars;j++) y[i] += MResult[i][j]*c->x[j];
    }

    for(i=0;i<nvars-1;i++) {
        temp1+=(y[i]-1)*(y[i]-1)*(1+sin(3*PI*y[i+1])*sin(3*PI*y[i+1]));
    }

    for(i=0;i<nvars;i++) {
        temp2+=U(y[i],5,100,4);
    }
    temp=sin(3*PI*y[0])*sin(3*PI*y[0]);
    temp+=temp1;
    temp+=(y[nvars-1]-1)*(y[nvars-1]-1)*(1+sin(2*PI*y[nvars-1])*sin(2*PI*y[nvars-1]));
    temp*=0.1;
    temp+=temp2;

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

//F14
double f114(SOLU *c)
{
    countEval++;
    int i,j;
    double temp = 0, temp1;

    for(i=0;i<nvars;i++) {
        y[i] = 0;
        for(j=0;j<nvars;j++) y[i] += MResult[i][j]*c->x[j];
    }

    for(j=0;j<25;j++)
    {
        temp1=j+1;

        for(i=0;i<2;i++)
        {
            temp1+=pow((y[i]-a1[i][j]),6);
        }

        temp1=1.0/temp1;
        temp+=temp1;
    }
    temp+=1.0/500;
    temp=1.0/temp;

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f115(SOLU *c)
{
    countEval++;
    //f15        4 dimensions
    int i,j;
    double temp = 0;

    for(i=0;i<nvars;i++) {
        y[i] = 0;
        for(j=0;j<nvars;j++) y[i] += MResult[i][j]*c->x[j];
    }

    for(i=0; i<11; i++)
    {
        temp+=pow((a_kow[i]-((y[0]*(b_kow[i]*b_kow[i]+b_kow[i]*y[1]))
                             /(b_kow[i]*b_kow[i]+b_kow[i]*y[2]+y[3]))) ,2);
    }

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f116(SOLU *c)
{
    countEval++;
    //F16
    int i,j;
    double temp;

    for(i=0;i<nvars;i++) {
        y[i] = 0;
        for(j=0;j<nvars;j++) y[i] += MResult[i][j]*c->x[j];
    }

    temp=4*y[0]*y[0]-2.1*pow(y[0],4)+1/3.0*pow(y[0],6)+
         y[0]*y[1]-4*y[1]*y[1]+4*pow(y[1],4);

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f117(SOLU *c)
{
    countEval++;
    //F17
    int i,j;
    double temp = 0;

    for(i=0;i<nvars;i++) {
        y[i] = 0;
        for(j=0;j<nvars;j++) y[i] += MResult[i][j]*c->x[j];
    }

    temp=pow((y[1]-5.1/(4*PI*PI)*y[0]*y[0]+5/PI*y[0]-6),2)+
         10*(1-1/(8*PI))*cos(y[0])+10;

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f118(SOLU *c)
{
    countEval++;
    //F18
    int i,j;
    double temp = 0;

    for(i=0;i<nvars;i++) {
        y[i] = 0;
        for(j=0;j<nvars;j++) y[i] += MResult[i][j]*c->x[j];
    }

    double X[5][4];

    for(i=0;i<5;i++) {
        X[i][0]=y[0];
        X[i][1]=y[1];
        X[i][2]=y[2];
        X[i][3]=y[3];
    }
    for(i=0;i<5;i++) {
        X[i][0]-=a_shekel[i][0];
        X[i][1]-=a_shekel[i][1];
        X[i][2]-=a_shekel[i][2];
        X[i][3]-=a_shekel[i][3];
    }

    temp=0;
    for(i=0;i<5;i++) {
        temp+=1.0/(X[i][0]*X[i][0]+X[i][1]*X[i][1]+X[i][2]*X[i][2]+X[i][3]*X[i][3]+c_shekel[i]);
    }
    temp=-temp;

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f119(SOLU *c)
{
    countEval++;
    //F19
    int i,j;
    double temp = 0;

    for(i=0;i<nvars;i++) {
        y[i] = 0;
        for(j=0;j<nvars;j++) y[i] += MResult[i][j]*c->x[j];
    }

    double X[7][4];
    for(i=0;i<7;i++) {
        X[i][0]=y[0];
        X[i][1]=y[1];
        X[i][2]=y[2];
        X[i][3]=y[3];
    }
    for(i=0;i<7;i++) {
        X[i][0]-=a_shekel[i][0];
        X[i][1]-=a_shekel[i][1];
        X[i][2]-=a_shekel[i][2];
        X[i][3]-=a_shekel[i][3];
    }

    for(i=0;i<7;i++) {
        temp+=1.0/(X[i][0]*X[i][0]+X[i][1]*X[i][1]+X[i][2]*X[i][2]+X[i][3]*X[i][3]+c_shekel[i]);
    }
    temp=-temp;

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f120(SOLU *c)
{
    countEval++;
    //F20
    int i,j;
    double temp = 0;

    for(i=0;i<nvars;i++) {
        y[i] = 0;
        for(j=0;j<nvars;j++) y[i] += MResult[i][j]*c->x[j];
    }

    double X[10][4];
    for(i=0;i<10;i++) {
        X[i][0]=y[0];
        X[i][1]=y[1];
        X[i][2]=y[2];
        X[i][3]=y[3];
    }
    for(i=0;i<10;i++) {
        X[i][0]-=a_shekel[i][0];
        X[i][1]-=a_shekel[i][1];
        X[i][2]-=a_shekel[i][2];
        X[i][3]-=a_shekel[i][3];
    }

    for(i=0;i<10;i++) {
        temp+=1.0/(X[i][0]*X[i][0]+X[i][1]*X[i][1]+X[i][2]*X[i][2]+X[i][3]*X[i][3]+c_shekel[i]);
    }
    temp=-temp;

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f121(SOLU *c)
{
    countEval++;
    //ogaF7  100NVARS
    int i,j;
    double temp = 0,tmax=0.0;

    for(i=0;i<nvars;i++) {
        y[i] = 0;
        for(j=0;j<nvars;j++) y[i] += MResult[i][j]*c->x[j];
    }

    for(i=0;i<nvars;i++) {
        tmax+=sin(y[i])*pow(sin(i*y[i]*y[i]/(double)PI),20);
    }
    temp=-tmax;

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

double f122(SOLU *c)
{
    countEval++;
    //ogaF9  100NVARS
    int i,j;
    double temp = 0,tmax=0.0;

    for(i=0;i<nvars;i++) {
        y[i] = 0;
        for(j=0;j<nvars;j++) y[i] += MResult[i][j]*c->x[j];
    }

    for(i=0;i<nvars;i++) {
        tmax+=pow(y[i],4)-16*y[i]*y[i]+5*y[i];
    }
    temp=tmax/nvars;

    //record the function values every 'evalStep' function evaluations
    if(countEval%evalStep==0) {
        evalValueTemp[trialNum][evalCount]=bestValue;
        evalValueAvg[evalCount]+=bestValue;
        evalCount++;
    }

    return temp;
}

#endif //GA_FUNCTION_H
