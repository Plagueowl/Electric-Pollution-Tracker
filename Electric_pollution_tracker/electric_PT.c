#include <stdio.h>
 #include<string.h>
//each appliance has 4 variable
//char name,float power rating,float time,float energy consumed,coal burned,carbon pollution
int filehandler();
int calculator();
struct appliance
{
  char name[30];
  float time_used;
  double energy_consumed;
  float power_rating;
  float coal_burned;
  float carbon_pollution;
};

struct appliance a[13];

//Declaring empty list for user input
int arr[13];
int num_devices;
double net_energy_consumed=0;
float net_coal_burned=0,net_CO2_produced=0;


int main()
{
  char choice[4];
  //Defining all appliances
  strcpy(a[0].name,"Cieling Fan");
  strcpy(a[1].name,"Refrigerator");
  strcpy(a[2].name,"Washing Machine");
  strcpy(a[3].name,"LED TV");
  strcpy(a[4].name,"Water Filter");
  strcpy(a[5].name,"electric Iron");
  strcpy(a[6].name,"Vacuum Cleaner");
  strcpy(a[7].name,"Lamp");
  strcpy(a[8].name,"Air Conditioner");
  strcpy(a[9].name,"Food Blender/ Grinder");
  strcpy(a[10].name,"gaming pc");
  strcpy(a[11].name,"Water Heater");
  strcpy(a[12].name,"Normal PC");
  
  //Defining power rating of all appliances
  a[0].power_rating=66;
  a[1].power_rating=104;
  a[2].power_rating=220;
  a[3].power_rating=60;
  a[4].power_rating=20;
  a[5].power_rating=1000;
  a[6].power_rating=1000;
  a[7].power_rating=20;
  a[8].power_rating=2500;
  a[9].power_rating=250;
  a[10].power_rating=400;
  a[11].power_rating=2000;
  a[12].power_rating=300;

  // Start
  printf("\n-----------------------------------------------------\n");
  printf("\n\n\t\t\tELECTRIC  POLLUTION  TRACKER\t\t\t\n\n");
  printf("\nLets play with Electric Pollution Tracker and know some facts about our Energy Consumption\n\n");
  printf("\n-----------------------------------------------------\n");
  
  //Making list of appliance and asking input
 printf("\nList of common Electrical Appliances used in home with average power rating : \n\n");
 
  for(int i=0;i<13;i++)
  {
    printf("%2d. %s  (%0.0f Watts)\n",i+1,a[i].name,a[i].power_rating);
  }
  printf("\n-----------------------------------------------------\n");


  printf("\nEnter number of devices you use\n");
  scanf("%d",&num_devices);
  printf("\nEnter the device number of appliances you use from above list: \n\n");
  
  for(int j=0;j<num_devices;j++)
  {
    printf("Enter device number of appliance %d: ",j+1);
    scanf("%d",&arr[j]);
  }
  printf("\n-------------------------------------------------\n");
  
  //Printing entered devices
  printf("\nThe devices you entered are:\n");
  for(int k=0;k<num_devices;k++)
  {
    printf("%2d. %s\n",k+1,a[arr[k]-1].name);
  }
  printf("\n--------------------------------------------------\n");
  
  //Taking time input
  for (int i=0;i<num_devices;i++)
  {
    printf(" Enter amount of time you used the %s in hours:  ",a[arr[i]-1].name);
    scanf("%f",&a[arr[i]-1].time_used);
  }
  printf("\n---------------------------------------------------\n");
  
  //Function call
  calculator(); 
   
  //Suggestion
  
  if(net_energy_consumed>720000)
  {
    printf("\nYou are using more electricity than an average household usage, please try to keep the consumption under control.\n ");
  }
  else
  {
    printf("\nYou are using right amount of electricity. \n");
  }
  //Call text file function on user demand
  printf("Do you want a txt file of your report?(Yes/No): ");
  scanf("%s",choice);
  if(strcmp(choice,"yes")==0)
  {
    filehandler();
  }
  else if(strcmp(choice,"yes")!=0)
  {
    printf("\nOkay");
  }
  return 0;
}


// Calculator function
int calculator()
{
  printf("\n---------------------------------------------------\n");

  //Calculating energy consumption and pollution
  for (int j=0;j<num_devices;j++)
  {
    a[arr[j]-1].energy_consumed=(a[arr[j]-1].power_rating)*(a[arr[j]-1].time_used)*3.6;
    
    //coal equivalent calculation
    a[arr[j]-1].coal_burned=(a[arr[j]-1].energy_consumed)/30000;
    
    //CO2 equivalent calculation
    a[arr[j]-1].carbon_pollution=a[arr[j]-1].coal_burned*2.42;

    //Net energy calculation
    net_energy_consumed += a[arr[j]-1].energy_consumed;
    
    //Net coal burned calculatoion
    net_coal_burned += a[arr[j]-1].coal_burned;
    
    //Net CO2 produced calculation
    net_CO2_produced += a[arr[j]-1].carbon_pollution;
  }

  printf("\n");
  
  //Display  energy consumed 
  for(int k=0;k<num_devices;k++)
  {
    printf("The Energy consumed by %s is : %0.2lf kilo-joules or %0.2lf kilo-calories\n",a[arr[k]-1].name,a[arr[k]-1].energy_consumed,a[arr[k]-1].energy_consumed/4.18);
  }
  printf("\nTotal Energy you consumed is :  %0.2lf kilo-joules or %0.2lf kilo-calories\n\n",net_energy_consumed, net_energy_consumed/4.18);
  
  printf("[ This much energy is equivalent to running %0.1f km at speed of 10km/h ]",net_energy_consumed/294);
  printf("\n---------------------------------------------------------\n");

  
  // Display of coal burnt 
  printf("\n 1 kg of COAL burnt = 30,000 kJ of energy \n");
  printf("\n---------------------------------------------------------\n");
  for(int l=0;l<num_devices;l++)
  {
    printf("\nCOAL burnt by %s is %0.2f kg\n",a[arr[l]-1].name,a[arr[l]-1].coal_burned);
  }
  printf("\nTotal COAL burned by all your devices is %0.2f kg\n",net_coal_burned);
  printf("\n---------------------------------------------------------\n");


   //Display of CO2 produced
  printf("\n#### 1 kg of COAL burned = 2.42 kg of CARBON DIOXIDE produce ####\n\n");
  printf("\n---------------------------------------------------------\n");
  for(int z=0;z<num_devices;z++)
  {
    printf("\nCARBON DIOXIDE produced by %s is %0.2f kg\n",a[arr[z]-1].name,a[arr[z]-1].carbon_pollution);
  }
  printf("\nTotal CARBON DIOXIDE produced by all your devices is %0.2f kg\n",net_CO2_produced);
  
  printf("\n---------------------------------------------------------\n");
 
  return 0;
  
}

//Text file function
int filehandler()
{
  FILE *ptr;
  ptr=fopen("Your_EPT_Report.txt","w");
  fprintf(ptr,"\n\t\t\tELECTRIC POLLUTION TRACKER\t\t\t\n\n");
  fprintf(ptr,"\nThe devices you entered are:\n\n");
  for(int k=0;k<num_devices;k++)
  {
    fprintf(ptr,"%2d. %s,\tTime used: %0.1f Hours \n",k+1,a[arr[k]-1].name,a[arr[k]-1].time_used);
  }
  fprintf(ptr,"\n-----------------------------------------------------\n");
  for(int k=0;k<num_devices;k++)
  {
    fprintf(ptr,"*The Energy consumed by %s is : %0.2lf kilo-joules or %0.2lf kilo-calories\n",a[arr[k]-1].name,a[arr[k]-1].energy_consumed,a[arr[k]-1].energy_consumed/4.18);
  }
  fprintf(ptr,"\n-----------------------------------------------------\n");
  fprintf(ptr,"\nTotal Energy you consumed is :  %0.2lf kilo-joules or %0.2lf kilo-calories\n",net_energy_consumed, net_energy_consumed/4.18);
  fprintf(ptr,"This much energy is equivalent to running %0.1f km at speed of 10km/h\n\n",net_energy_consumed/294);
  fprintf(ptr,"\n-----------------------------------------------------\n");
  
  for(int l=0;l<num_devices;l++)
  {
    fprintf(ptr,"\nCOAL burnt by %s is %0.2f kg\n",a[arr[l]-1].name,a[arr[l]-1].coal_burned);
  }
   fprintf(ptr,"\n----------------------------------------------------\n");
  fprintf(ptr,"\nTotal COAL burned by all your devices is %0.2f kg\n",net_coal_burned);
  fprintf(ptr,"\n-----------------------------------------------------\n");


   //Display of CO2 produced
  
  fprintf(ptr,"\n-----------------------------------------------------\n");
  for(int z=0;z<num_devices;z++)
  {
    fprintf(ptr,"\nCARBON DIOXIDE produced by %s is %0.2f kg\n",a[arr[z]-1].name,a[arr[z]-1].carbon_pollution);
  }
  fprintf(ptr,"\n-----------------------------------------------------\n");
  fprintf(ptr,"\nTotal CARBON DIOXIDE produced by all your devices is %0.2f kg\n",net_CO2_produced);
  fprintf(ptr,"\n-----------------------------------------------------\n");
 
  fprintf(ptr,"\nAn average human produces 0.9 kg of carbon dioxide by breathing in a day.\n");
  fprintf(ptr,"\nAverage consumption of energy per day per house in India is 720 MJ \n");
  if(net_energy_consumed>720000)
  {
    fprintf(ptr,"\nYou are using more electricity than an average household usage, please try to keep the consumption under control.\n ");
  }
  else
  {
    fprintf(ptr,"\nYou are using right amount of electricity. \n");
  }
  fprintf(ptr,"\n------------------------------------------------------\n");
  fprintf(ptr,"\nFew tips for using electricity wisely:\n\n");
  fprintf(ptr,"1. Switch off your fan for sometime,you'll get a practice of bearing the heat. \n2.Use devices that consume less power, yes they could be expensive but they save the environment\n3.Turn off the switches when not in use. ");
  fclose(ptr);
  return 0;
}