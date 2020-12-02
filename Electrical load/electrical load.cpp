#include<stdio.h>
main()
{
printf("------THIS PROGRAM CAN CALCULATE THE TOTAL ELECTRICAL LOAD OF ANY BUILDING----\n");
printf("==============================================================================\n\n");
float floor[500],f_cable[500],u_cable[100];
int floors,h,d,data,z,power;
float build,load_building,extra_section_load,cable_building,extra_current,total_current_ext;
printf("How many floors: ");
scanf("%d",& floors);
if(floors==0)
printf("Impossible");
else
{
for(h=1;h<=floors;h++)
{
int units,b,a,unit_count,sec_load,units_load[100];
float parti_unit[500],s,floor_cable,floor_load,unit_load,unit_cable;
printf("For floor %d how many units:",h);
scanf("%d",& units);
if(units==0)
printf("Impossible\n");
else
{
for(unit_count=1;unit_count<=units;unit_count++)
{
printf("For unit %d\n==============\n\a",unit_count);
{
printf("How many categories of electrical equepment:");
int cat,load,cat_load[100];
scanf("%d",& cat);
if(cat==0)
printf("NO Loads\n");
else
{
int cat_count;
float sec_load,unit_cable,unit_load;
for(cat_count=1;cat_count<=cat;cat_count++)
{
printf("Enter name of catagory %d\a:  ",cat_count);
char equepment[200];
scanf("%s",equepment);
printf("How many %s:",equepment);
int f,e,t,load;
scanf("%d",& f);
printf("If all the %s are same load then press 1 otherwise press 0 :",equepment);
scanf("%d",&z);
if(z==1)
{
printf("Power: ");
scanf("%d",& power);
load=power*f;
}
else
{
int c[100];
for(e=1;e<=f;e++)
{
printf("%s %d power: ",equepment,e);
scanf("%d",& c[e]);
}
load=0;
for(t=1;t<=f;t++)
{
load=load+c[t];
}
}
cat_load[cat_count]=load;
printf("Total %s load =%d Watt\a\n\n",equepment,cat_load[cat_count]);
}
sec_load=0;
int m;
for(m=1;m<=cat;m++)
{
sec_load=sec_load+cat_load[m];
}
unit_cable=sec_load/220;
u_cable[unit_count]=unit_cable;
unit_load=sec_load/1000;
parti_unit[unit_count]=sec_load;
printf("Total unit %d load is %f KW\nCable capacity %f AMP(min)\n\n",unit_count,unit_load,unit_cable);
}
}
}
}
s=0;
for(b=1;b<=units;b++)
{
s=s+parti_unit[b];
}
floor_load=s/1000;
floor_cable=s/220;
printf("     -------Data table----------\n\n");
printf("Unit      Load       Cable(min)\a\a\n\n");
for(data=1;data<=units;data++)
{
printf(" %d    %f KW    %f Amp\n",data,(parti_unit[data])/1000,u_cable[data]);
}
printf("Floor %d load= %f KW cable capacity= %f AMP(min)\a\a\n\n\n\n",h,floor_load,floor_cable);
printf("If voltage drops below 220 then use\ntransformer for necessary adjustment\n\n");
floor[h]=s;
f_cable[h]=floor_cable;
}
build=0;
for(d=1;d<=floors;d++)
{
build=build+floor[d];
}
float extra_load;
printf("If there is any extra electrical system\nlike Elevator, Moving stears etc\nenter there number, name and category below\a\a\n");
int ex;
printf("=================Extra system============\n\n\n");
printf("Number of extra system :");
scanf("%d",& ex);
printf("\n");
if(ex==0)
{
printf("No Extra loads\n\n");
extra_load=0;
load_building=build/1000;
cable_building=build/220;
}
else
{
int k,s,cont, syst_count;
float q,syst_load[100],syst_current[100],extra_current;
for(syst_count=1;syst_count<=ex;syst_count++)
{
printf("Name of system %d :\a",syst_count);
char extra[50];
scanf("%s",extra);
printf("Number of %s :",extra);
scanf("%d",& k);
float current_ext[100],total_current_ext,extra_current;
float q[100],current,v,volt_ext;
for(s=1;s<=k;s++)
{
printf("%s %d power:",extra,s);
scanf("%f",& q[s]);
printf("Voltage: ");
scanf("%f",& volt_ext);
current_ext[s]=q[s]/volt_ext;
printf("%s %d current: %f\n ",extra,s,current_ext[s]);
}
current=0,v=0;
for(cont=1;cont<=k;cont++)
{
current=current+current_ext[cont];
v=v+q[cont];
}
syst_load[syst_count]=v;
syst_current[syst_count]=current;
printf("Total %s load %f KW current %f Amp \a\n\n",extra,syst_load[syst_count]/1000,syst_current[syst_count]);
}
int extra_load=0,total_current_ext=0,w;
for(w=1;w<=ex;w++)
{
extra_load=extra_load+syst_load[w];
total_current_ext=total_current_ext+syst_current[w];
}
extra_section_load=extra_load;
extra_current=total_current_ext;
printf("Total Extra section Load= %f KW Current %f Amp\n\n",extra_section_load/1000,extra_current);
cable_building=extra_current+build/220;
load_building=(build+extra_section_load)/1000;
}
printf("==============================================\n");
printf("Total load of this %d stored building is %f KW\n",floors,load_building);
printf("The minimum current carring capacity needs to be\n %f AMP for main line cable\n\n\n",cable_building);
printf("     -------Data table----------\n\n");
printf("Floor      Load       Cable\n\n");
for(data=1;data<=floors;data++)
{
printf(" %d    %f KW    %f Amp(min)\n",data,(floor[data])/1000,f_cable[data]);
}
printf("-----------------------------------Prepared by (N.J Tamanna)\n\n\n\a\a\a\n");
}
}



