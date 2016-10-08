#include <stdio.h>
#include <math.h>

float UT(float a)
{
	return exp(a)-exp(a-1);
}


float switchFunction(int optn,float a)
{
	

 switch(optn)
	 {
	 	case 1:
	 		return sin(a);
	 		break;
	 	case 2:
	 		return exp(a);
	 	case 3:
	 		return a;
	 		break;
	 	default:
	 	return 0;
	 		printf("Error\n");
	 		break;			
	 }

}

int userInput()
{
	int flag=0,optn;

	while(flag==0)
	{
		printf("Enter u[t] valus as\n");
		printf("1.Sin function\n");
		printf("2.Exponential function\n");
		printf("3.u[t] in terms of x\n");
		printf("4.Exit\n");
		scanf("%d",&optn);

		
		// checks if correct optn is selected
		if (optn<1 || optn>4)
		{
			printf("Select correct option\n");
		}
		else
		{
			flag=1;
		}
	}

return optn;

}




	
int main()
{
	/**********All the variable************/
	float uT,tMin,tMax,inncreamentVar,interval;
	int flag,i,count,optn,j,k=1;
	int srno=0;
	float newTmin,newTmax,yCordinate,temp=0,uDashOfT,definiteInt;
	float newuT;//stores value of ut
	
	/**************************************/
	

	// file declaration starts
   FILE *fp;
   fp = fopen("output.csv", "a");

   // file declaration ends

while(k==1)
{
	   fprintf(fp, "\nCount\t,x-coordinate\t,yCordinate\t\n");
	flag=1;
	optn = userInput();
	if(optn==4)
	{
		k=0;
		break;
	}	
	while(flag==1)
	{
		printf("Enter the value of u[t]:");
		scanf("%f",&uT);
		printf("Enter the value of Tmin:");
		scanf("%f",&tMin);

		printf("Enter the value of Tmax:");
		scanf("%f",&tMax);

		if(tMax-tMin>0 && uT<tMax && uT>=tMin )
		{
			flag=0;
		}
		else
		{
			printf("Values are not correct.Enter again!!\n");	
		}
	}



	printf("Enter the value of count:");
	scanf("%d",&count);

	interval = tMax-tMin;
	printf("interval is %f \n",interval);
	
	/*
	 calculate the value of x,for more info refer algorithm
	*/

	 inncreamentVar = (33*interval)/100;
	 // printf("inncreamentVar is %f\n",inncreamentVar);

	 temp = tMin;

	//SWITCH STATEMENT
	 uT = switchFunction(optn,uT);
	 
	 printf(" ut value is :%f\n",uT );
	 for (j = 0; j < 3; j++)
	 {
	

	 	yCordinate=uT;
	 	
	 	srno++; 
	 	printf("%d \t %f \t %f\n",srno,temp,yCordinate );
	 	fprintf(fp, "%d \t,%f\t,%f\t\n",srno,temp,yCordinate);
	 	temp  = temp +inncreamentVar;
	 }

	 srno++;
	 printf("%d \t %f \t %f\n",srno,tMax,yCordinate );
	 fprintf(fp,"%d \t ,%f \t ,%f\t\n",srno,tMax,yCordinate );
		

	for (i = 0; i < count; i++)
	{
		newTmax = tMax+interval ;
		newTmin = tMin+interval	;

		/* *************The function***********/
		
		newuT = UT(newTmin+0.2);                //newut is actullay u(t)
		uDashOfT = uT+newuT;					//here uT is actually u(t-1)
												//use proper random function
		//uDashOfT = 1+ uT;
		//uDashOfT = uT;													
		
		/*************************************/
		temp = newTmin +inncreamentVar;

		

		for (j = 0; j < 3; j++)
		 {
			srno++;
		 	yCordinate = uDashOfT*(temp-newTmin);
		 	printf("%d \t %f \t %f\n",srno,temp,yCordinate );
		 	fprintf(fp,"%d \t ,%f \t, %f\n",srno,temp,yCordinate );
		 	temp  = temp +inncreamentVar;
		 }

		 //new value of uT

		 //finding definite integral using value tmin and tmax
		 srno++;
		 definiteInt = uDashOfT*(newTmax - newTmin);
		 printf("%d \t %f \t %f\n",srno,newTmax,definiteInt );
		  fprintf(fp,"%d \t, %f \t, %f\n",srno,newTmax,definiteInt );	

		 uT = uT+ definiteInt;

	  uT = switchFunction(optn,uT);
	

		 tMax = newTmax;
		 tMin  = newTmin;

	}

	
}
	fclose(fp);
}


