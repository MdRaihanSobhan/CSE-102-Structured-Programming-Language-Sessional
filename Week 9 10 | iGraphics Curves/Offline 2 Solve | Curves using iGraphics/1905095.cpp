#include<stdio.h>
#include<math.h>
# include "iGraphics.h"
#define pie acos(-1)

int shift=0;
int color=3;                    // number of basic colours
int R[] = {255,0,255};          // Red
int G[] = {255,0,0};            // Green
int B[] = {0,255,0};            // Blue
int width=1380;                 // width of screen
int height=770;                // height of screen
int midline = height/2;
int numberofcurves=3;
int ballmode[]={1,1,1};         // 1 means show, 0 means hide
int curvemode[]={1,0,1};        // 1 means sine, 0 means cos

int quit=0, a=0 ;
int image=1;
int ball=1;                     // 1 means show, 0 means hide
int curve=1;                    // 1 means show, 0 means hide
int sumcurve=1;                 // 1 means show, 0 means hide the resultant curve
int mode=1;                     // 1 means  forward, -1 means backward

double changeamp=1;             // coefficient of the amplitude
double changefreq=1;            // coefficient of the frequency
double freq[]={1,0.7,1.5};      // default frequencies of curves
double amp[]={50,75,100};     // default amplitudes of curves

double X= 0, Y=0, sumY=0;       // x and y coordinates of ball, sumY is the Y component of resultant curve
double velocity = 5;            // velocity of the ball
double phase =0;                // phase difference given for shifting curves

double x,y,w,sumy;              // x,y are the coordinates of the points of curves, w is theta
                                // sumy is the y coordinates of points of the resultant curve

                                // icurve function will draw the curves
void icurve()
{

    int i;


    for(x=0;x<=width;x=x+1)
    {
        sumy=0;

        w = x*pie/180;           // converting  into radian

        for(i=0;i<numberofcurves;i++)
        {
            if(curvemode[i])     // 1 for sin , 0 for cos
            {
                y=changeamp*amp[i]*sin(changefreq* freq[i]* w  + phase);  // y= a sin (wt + delta)
            }
            else
            {
                y=changeamp*amp[i]* cos(changefreq* freq[i]* w+ phase);  // y = acos (wt+ delta)
            }
            iSetColor(R[i%color],G[i%color],B[i%color]);  // setting the color of curves

            iPoint(x,y+midline);         // drawing the curves

            sumy+=y;   // summation of all curves
        }

        iSetColor(0,255,0);  // the resultant curve will be green

        iPoint(x,sumy+midline);  // drawing the resultant curve

    }
}
                    // replaceball function will change the position of the ball to give it a velocity
void replaceball()
{
    X+= mode * velocity;
    if(X>width || X<0)
        mode*=-1;   // if the balls touche the screen , the direction will be changed.
}
// iball function will draw the balls, the descriptions are almost same as icurve

void iball()
{
    double W = X * pie/180;  // W is theta , and converting into radian
    Y=0,sumY=0;

    for(int i=0; i<numberofcurves; i++)
    {
        iSetColor(R[i%color],G[i%color], B[i%color]);

        if(curvemode[i])
        {
            Y=changeamp*amp[i]*sin(changefreq* freq[i]* W + phase);
        }
        else
        {
            Y=changeamp*amp[i]* cos(changefreq* freq[i]* W+ phase);
        }
        sumY+= Y;
        if(ballmode[i])
        {
            iFilledCircle(X,Y+midline,5);    // the radius of the balls are 5 unit
        }
    }
    iSetColor(0,255,0);
    if(sumcurve)
    {
        iFilledCircle(X,sumY+midline,7);     // the resultant ball will be a bit larger in size , so r=7 unit
    }
}


// idraw function will be continuously drawing the graphics scenes

void iDraw()
{

    iClear();

    if(a>=0 && a<=1500)
    {
        iSetColor(0,0,0);
        iFilledRectangle(0,0, width, height);
        iSetColor(0,255,0);
        iText(width/3,height/2," As Salamu Alaikum, Welcome to the world of curves ",GLUT_BITMAP_TIMES_ROMAN_24 );
        a++;
    }
    else if(quit==0)
    {
        if(image==1)
        {
            iClear();
            iShowBMP(30,30,"forhelp.bmp");
        }
        else
        {
            iSetColor(255,255,255); // the mid axis line of the curves will be white
            iLine(0,midline,width,midline);   // x1,y1,x2,y2

            if(curve)
                icurve();     // curves will appear if curve==1
            if(ball)
                iball();       // balls will appear if ball == 1
            iSetColor(255,255,255);
            iText(width/3,50, "press F1 for help");
            if(shift==1)
                phase+=pie/400,velocity=0;   // for left shifting continuously
            if(shift==-1)
                phase-=pie/400,velocity=0;  // for right shifting continuously

        }

    }
    else if(a<=3000 && quit==1)
    {

        iSetColor(255,255,0);
        iText(width/3,height/2," Thanks for watching, As Salamu Alaikum ",GLUT_BITMAP_TIMES_ROMAN_24 );
        a++;
    }
    else
    {
        exit(0);
    }
}

void iMouseMove(int mx, int my)
{

}


void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        shift=1;  // left button is used for continuously shifting left
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        shift=-1; // right button is used for continuously shifting right
    }
}


void iKeyboard(unsigned char K)
{
    if(K=='q' || K=='Q')
    {
        // exit(0);           // press q to quit
        quit=1;
    }
    if(K=='p' || K=='P')
        iPauseTimer(0);    // press p to pause the balls movement
    if(K=='r' || K=='R')
        iResumeTimer(0);   // press r to resume the balls movement
    if(K=='B' || K=='b')                    // press b to toggle the balls show
    {
        if(ball)
            ball=0;
        else
            ball=1;
    }

    if(K=='S' || K=='s')                    // press s to toggle the curves show
    {
        if(curve) curve=0;
        else curve=1;
    }

    if(K=='+')                              // press + to increase the velocity of the balls
    {
        velocity+=0.5;
    }
    if(K=='-')                              // press - to decrease the velocity of the balls
    {
        velocity-=0.5;
        if(velocity<0) velocity=0;          // I don't want to toggle the direction by this operation
    }
    if(K=='a')                              // press a to increase the amplitudes of the curves
    {
        changeamp*=1.025;
        if(changeamp*200>=height) changeamp/=1.025; // I will not increase the amplitude after crossing range
    }
    if(K=='A')                              // press A to decrease the amplitudes
    {
        changeamp/=1.025;
    }
    if(K=='f')                              // press f to increase the frequency
    {
        changefreq*=1.01;
    }
    if(K=='F')
    {
        changefreq/=1.01;                    // press F to decrease the frequency
    }
    if(K>='0' && K<='9')                     // press individual numbers to toggle the ball show
    {
        int b= K-'0'-1;
        if(b<numberofcurves)
        {
            if(ballmode[b]) ballmode[b]=0;
            else ballmode[b]=1;
        }
        if(b==numberofcurves)
        {
            if(sumcurve) sumcurve=0;
            else sumcurve=1;
        }
    }
    if(K== ' ') shift=0;                     // hit space to stop continuous shifting
    if(K=='<') phase+= pie/4;                // press < to shift 45 degree left
    if(K=='>') phase-=pie/4;                 // press >  to shift 45 degree right
    if(K=='t' || K=='T')                     // press t to change the direction of the balls
    {
        if(mode==1) mode=-1;
        else mode=1;
    }
}

void iSpecialKeyboard(unsigned char key)
{
    if(key == GLUT_KEY_UP) // press up arrow to elevating the curves
    {
        midline+=10;
        if(midline>=height) midline-=10;
    }
    if(key== GLUT_KEY_DOWN)  // press down arrow to scroll down the curves
    {
        midline-=10;
        if(midline<=0) midline+=10;
    }

    if(key== GLUT_KEY_LEFT)     // press left arrow to continuously left shifting
    {
        shift=1;  // 1 means left shifting
    }
    if(key== GLUT_KEY_RIGHT)    // press right arrow to continuously right shifting
    {
        shift=-1;   // -1 means right shifting
    }

    if(key == GLUT_KEY_END)     // press end key to exit
    {
        exit(0);
    }
    if(key== GLUT_KEY_F1)
    {
        if(image==0)
            image=1;
        else
            image=0;
    }
}


int main()
{
    iSetTimer(20,replaceball);
    iInitialize(width,height,"1905095");
    return 0;
}


