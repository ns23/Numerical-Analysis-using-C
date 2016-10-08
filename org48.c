#include <stdio.h>
#include <math.h>
#include<conio.h>

#define MAX 20

/*variable to store final answer in each method*/
float apcmAns,mpcmAns,rk2mAns,rk4mAns,absolutValue;

/*Common variables in apcm and mpcm*/
int flag,i,n;
float temp,y_corrected,sign;

/*Common variables in rk2m and rk4m*/
int i,count,selMethod;
float lower,upper,h;
float k,k1,k2,k3,k4;

/*variable to check if a problem is solved using a particular method*/
int apcmCheck=0,mpcmCheck=0,rk2mCheck=0,rk4mCheck=0;


int main()
{
    int flg = 0,ch;
    int f_rk2=0,f_rk4=0,f_apcm=0,f_mpcm=0;

    printf(".....Options....\n");
    do
        {
           // clrscr();

            printf("1.Problem solving Methods\n");
            printf("2.View all the answers\n");
            printf("3.Compare the Answers with\n");
            printf("4.Exit\n\n");

            printf("Enter your choice: ");
            scanf("%d",&ch);

            switch(ch)
            {
            case 1:
                selMethod = dispalyMethod();
                solve(selMethod);
                break;

            case 2:
                viewAnswers();
                break;

            case 3:
                compareAns();
                break;

            case 4:
                flg = 4;
                break;

            default:
                printf("Please enter correct choice\n");
                break;
            }

        }
    while(flg != 4);


}
/*Display methods*/
dispalyMethod()
{
	int choice;

    printf("\nSelect Method\n");
	printf("1.Adams Predictor Corrector Method\n");
	printf("2.Milne's Predictor Corrector Method\n");
	printf("3.Runge-Kutta Second Order\n");
	printf("4.Runge-Kutta fourth Order\n");
	printf("5.Exit\n");

	scanf("%d",&choice);

	return(choice);

}


solve(x)
{
    int cnt;
	switch(x)
	{
		case 1:
			apcm();
			selMethod = dispalyMethod();
            solve(selMethod);
			break;

		case 2:
			mpcm();
			selMethod = dispalyMethod();
            solve(selMethod);
			break;

		case 3:
			rk2o();
			selMethod = dispalyMethod();
            solve(selMethod);
			break;

		case 4:
			rk4o();
			selMethod = dispalyMethod();
            solve(selMethod);
			break;

        case 5:
            break;

		default:
		printf("Wrong Choice\n");
		dispalyMethod();
		break;
	}



}

float equation(float x,float y)
{
	float z;
	z = (x+y);  //calculates value of function and stores it in variable z.
    return(z); //the value of z is returned to s1 and s2;
}


 apcm()
{

    float height,x[10]={},y[10]={},y_dash[10]={};
    sign=1;
    //int i;
    //hight,
    temp=y_corrected = 0;

  //  printf("\n\n************************************************\n\n");
    printf("Adams Bashforth Predictor-Corrector Method \n\n");
    //printf("************************************************\n\n");


    printf("Enter the value of n :");
    scanf("%d",&n);

    printf("Enter the value of height :");
    scanf("%f",&height);

    printf("\nEnter the value of x[0] :");
    scanf("%f",&x[0]);

    printf("\n");

    for(i=1;i<=n+1;i++)
    {
        x[i] = x[i-1]+height;
        printf("The value of X[%d] : %.2f\n",i,x[i]);
    }


    printf("\n");
    for(i=0;i<=n;i++)
    {
        printf("Enter the value of y[%.2f]:",x[i]);
        scanf("%f",&y[i]);
       // printf("\n y:%f",y[i]);
    }

    //temp = i;
    printf("\nWe are suppose to find value of y[%.2f]\n\n",x[i]);

    for(i=0;i<=n;i++)
    {
        //y_dash[i] = (x[i]+y[i])/2;
		y_dash[i] = equation(x[i],y[i]);
        printf("The value of y'%d : %.4f\n",i,y_dash[i]);
    }
    //function to calculate value of y'



temp = (55*y_dash[n]-59*y_dash[n-1]+37*y_dash[n-2]-9*y_dash[n-3]);


y[n+1] = y[n] +(height/24)*temp;

printf("\nThe predicted value is :%.4f\n",y[n+1]);

//correctd value

//y_dash[n+1] = (x[n+1]+y[n+1])/2;
y_dash[n+1] = equation(x[n+1],y[n+1]);
printf("\nThe value of y'%d : %.4f\n",n+1,y_dash[n+1]);


temp = 0;

temp = (9*y_dash[n+1] + 19*y_dash[n] -5*y_dash[n-1] + y_dash[n-2]);

y_corrected = y[n] + (height/24)*temp;

printf("\ncorrected value :%.4f\n",y_corrected);

apcmCheck = 1; // flag that apcm method is executed

apcmAns = y_corrected;
getch();
//return 0 ;
}


mpcm()
{
    //int n,flag;
    sign=1;
    //int i;
    float height,x[10]={},y[10]={},y_dash[10]={};
    temp=y_corrected = 0;

//    printf("***************************************\n\n");
    printf("Milne's Predictor Corrector Method  \n\n");
  //  printf("***************************************\n\n");

    printf("Enter the value of n :");
    scanf("%d",&n);

    printf("Enter the value of height :");
    scanf("%f",&height);

    printf("\nEnter the value of x[0] :");
    scanf("%f",&x[0]);

    printf("\n");

    for(i=1;i<=n+1;i++)
    {
        x[i] = x[i-1]+height;
        printf("The value of x[%d] : %.2f\n",i,x[i]);
    }

    printf("\n");
    for(i=0;i<=n;i++)
    {
        printf("Enter the value of y[%.2f]:",x[i]);
        scanf("%f",&y[i]);

    }

    //temp = i;
    printf("\nWe are suppose to find value of y[%.2f]\n\n",x[i]);
    for(i=1;i<=n;i++)
    {
        //y_dash[i] = (x[i]+y[i])/2;
			y_dash[i] = equation(x[i],y[i]);
       printf("The value of y'%d : %.4f\n",i,y_dash[i]);
    }
    //function to calculate value of y'


temp = (2*y_dash[n-2] - y_dash[n-1] + 2*y_dash[n]);

y[n+1] = y[0] +((4*height)/3)*temp;

printf("\nThe predicted value is :%.4f\n",y[n+1]);

//correctd value

//y_dash[n+1] = (x[n+1]+y[n+1])/2;
y_dash[n+1] = equation(x[n+1],y[n+1]);
printf("\nThe value of y'%d : %.4f\n",n+1,y_dash[n+1]);

temp = 0;

temp = (y_dash[n-1] + 4*y_dash[n] + y_dash[n+1]);
y_corrected = y[n-1] + (height/3)*temp;

printf("\ny corrected :%.4f\n",y_corrected);

mpcmAns = y_corrected;
mpcmCheck = 1;
getch();
}

rk2o()
{

	//variable declarations
    i=count=1;
    float xvalue[MAX],yvalue[MAX];
    float y1;


    printf("\n\n");


    printf("Runge-Kutta Second Order ");


    printf("\n\n");


	//take value of lower bound of x
    printf("\nEnter the lower bound of x :  ");

    scanf("%f",&lower);


	//take value of upper bound of x.
    printf("\nEnter the upper bound of x :  ");
    scanf("%f",&upper);


	//take value of y(x0)..intial value of y
    printf("\nEnter the value of y(lower):  ");

    scanf("%f",&y1);


   //takes the value of h
    printf("\nEnter the value of h       :  ");

    scanf("%f",&h);


	xvalue[i]=lower; //stores the value of x lower in array xvalue[i]
    yvalue[i]=y1;    //store the value of y(lower is the array yvalue[i])

	/*
	it increments the value of xvalue[i] by h.
	*/
    for(i=1;xvalue[i]<upper;i++)
    {

        xvalue[i+1]=xvalue[i]+h;
        count=count+1;

    }

	//function that have all the formula of runga kutta
    for(i=1;i<=count;i++)
    {
        k1=h*equation(xvalue[i],yvalue[i]); //value of k1

        k2=h*equation(xvalue[i]+(h/2),yvalue[i]+(k1/2));

        k=(k1+k2)/2; //calculates value of k

        yvalue[i+1]=yvalue[i]+k;
    }
    printf("\n\n");
    printf("The complete solution of the differential equation is, ");
    printf("\n\n");

    printf(" no \t x \t\t y  \n");
	//printing output on screen and writing it to file Runge-Kutta_2.csv
    for(i=1;i<=count;i++)
    {
        printf(" %d \t %.4f \t %.4f  ",i,xvalue[i],yvalue[i]);
        printf("\n");
    }
    rk2mAns = yvalue[count];
    rk2mCheck = 1;
    getch();

}

rk4o()
{
//variable declarations
    i=count=1;
    float xvalue[MAX],yvalue[MAX];
    float y1;



/*
printf(""):displays message and data on the screen.
fprintf(fp,""):writes the message and data to file.
*/

    printf("\n\n");

    printf("Runge-Kutta fourth Order ");

    printf("\n\n");

	//take value of lower bound of x
    printf("\nEnter the lower bound of x :  ");
    scanf("%f",&lower);

	//take value of upper bound of x.
    printf("\nEnter the upper bound of x :  ");
    scanf("%f",&upper);

	//take value of y(x0)..intial value of y
    printf("\nEnter the value of y(lower):  ");
    scanf("%f",&y1);

   //takes the value of h
    printf("\nEnter the value of h       :  ");
    scanf("%f",&h);

	xvalue[i]=lower; //stores the value of x lower in array xvalue[i]
    yvalue[i]=y1;    //store the value of y(lower is the array yvalue[i])

	/*
	it increments the value of xvalue[i] by h.
	*/
    for(i=1;xvalue[i]<upper;i++)
    {

        xvalue[i+1]=xvalue[i]+h;
        count=count+1;

    }

	//function that have all the formula of runga kutta
    for(i=1;i<=count;i++)
    {
        k1 = h*equation(xvalue[i],yvalue[i]); //value of k1

        k2 = h*equation(xvalue[i]+(h/2),yvalue[i]+(k1/2));

        k3 = h*equation(xvalue[i]+(h/2),yvalue[i]+(k2/2));

        k4 = h*equation(xvalue[i]+h,yvalue[i]+k3);

        k = (k1+(2*k2)+(2*k3)+k4)/8 ;//calculates value of k

        yvalue[i+1] = yvalue[i]+k;
    }
    printf("\n\n");
    printf("The complete solution of the differential equation is, ");
    printf("\n\n");

    printf(" no \t x \t\t y  \n");
	//printing output on screen and writing it to file Runge-Kutta_2.csv
    for(i=1;i<=count;i++)
    {
        printf(" %d \t %.4f \t %.4f  ",i,xvalue[i],yvalue[i]);
        printf("\n");

    }

    rk4mAns = yvalue[count];
    rk4mCheck = 1;
  //  printf("\nThe Output is stored in Runge-Kutta_4.csv\nPress any key to exit\n ");
    getch();

}


viewAnswers()
{

	if(apcmCheck==1)
	{
		printf("1.apcm method corrected answer is %f \n",apcmAns);
	}
	else
	{
		printf("1.No problem solved using apcm \n");
	}
	//////////
	if(mpcmCheck==1)
	{
		printf("2.mpcm method corrected answer is %f \n",mpcmAns);
	}
	else
	{
		printf("2.No problem solved using mpcm \n");
	}
	///////////
		if(rk2mCheck==1)
	{
		printf("3.rk2m method corrected answer is %f \n",rk2mAns);
	}
	else
	{
		printf("3.No problem solved using rk2m \n");
	}
	/////////
		if(rk4mCheck==1)
	{
		printf("4.rk2m method corrected answer is %f \n",rk4mAns);
	}
	else
	{
		printf("4.No problem solved using rk4m \n");
	}

getch();
printf("\n\n");

}

compareAns()
{
    FILE *fp; //pointer to file.
	fp=fopen("finalOp.csv","w"); //opens file in write mode

	printf("\nEnter the absolute value :");
	scanf("%f",&absolutValue);

    fprintf(fp,"\n\n");

     fprintf(fp,"The final Observation\n ");

	printf("\nSr.\t Method name \t machine value \t absolute value \t error\n");
	  fprintf(fp,"Sr., Method name ,machine value,absolute value , error ");
	   fprintf(fp,"\n");

	if(apcmCheck==1)
	{
		printf("1. \t apcm \t\t %.4f \t %.4f \t\t  %.4f \n",apcmAns,absolutValue,apcmAns-absolutValue);
		fprintf(fp,"1,apcm,%.4f,%.4f,%.4f ",apcmAns,absolutValue,apcmAns-absolutValue);
		fprintf(fp,"\n");
	}
	else
	{
		printf("1. \t apcm \t\t NUll \t\t NULL \t\t\t  NULL \n");
		fprintf(fp,"1.,apcm,NUll,NULL,NULL");
		fprintf(fp,"\n");
	}
	//////////
	if(mpcmCheck==1)
	{
		printf("2. \t mpcm \t\t %.4f \t %.4f \t\t  %.4f \n",mpcmAns,absolutValue,mpcmAns-absolutValue);
        fprintf(fp,"2,mpcm,%.4f,%.4f,%.4f ",mpcmAns,absolutValue,mpcmAns-absolutValue);
		fprintf(fp,"\n");
	}
	else
	{
		printf("2. \t mpcm \t\t NUll \t\t NULL \t\t\t  NULL \n");
        fprintf(fp,"2.,mpcm,NUll,NULL,NULL");
        fprintf(fp,"\n");
	}
	///////////
		if(rk2mCheck==1)
	{
		printf("3. \t rk2m \t\t %.4f \t %.4f \t\t  %.4f \n",rk2mAns,absolutValue,rk2mAns-absolutValue);
        fprintf(fp,"3,rk2m,%.4f,%.4f,%.4f ",rk2mAns,absolutValue,rk2mAns-absolutValue);
		fprintf(fp,"\n");
	}
	else
	{
		printf("3. \t rk2m \t\t NUll \t\t NULL \t\t\t  NULL \n");\
		 fprintf(fp,"3.,rk2m,NUll,NULL,NULL");
        fprintf(fp,"\n");
	}
	/////////
		if(rk4mCheck==1)
	{
		printf("4. \t rk4m \t\t %.4f \t %.4f \t\t  %.4f \n",rk4mAns,absolutValue,rk4mAns-absolutValue);
        fprintf(fp,"4,rk4m,%.4f,%.4f,%.4f ",rk4mAns,absolutValue,rk4mAns-absolutValue);
		fprintf(fp,"\n");
	}
	else
	{
		printf("1. \t rk4m \t\t NUll \t\t NULL \t\t\t  NULL \n");
         fprintf(fp,"4.,rk4m,NUll,NULL,NULL");
        fprintf(fp,"\n");
	}

    fclose(fp);
	getch();
}





