#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
int main()
{

float merkezx,merkezy;
int yatay=-10;
int dikey=8;
int a=0;
float cap;
float r;
int tempy=0,tempx=0;
 int gd=DETECT,gm;
  initgraph(&gd,&gm,"");
  line(0,270,600,270);//yatay çizgi
  line(300,0,300,600);//dikey çizgi

  for(int i=-1;i<600;i=i+30)//yatay çizgiler
  {
  setfillstyle(1, GREEN);
    bar(i,260,i+3,285);
  }

   for(int x=0;x<=600;x=x+30)//yatay sayýlar
{
  char sayi[3];
  if(x!=300)
  {
  sprintf(sayi,"%d",yatay);
  outtextxy(x-3,240,sayi);
  }
  yatay++;
}

    for(int j=-1;j<600;j=j+30)//dikey çizgiler
  {
  setfillstyle(1, GREEN);
    bar(290,j,310,j+3);
   }
   
   for(int y=30;y<=480;y=y+30)//dikey sayýlar
   {
    char sayi[3];
    if(1)
  {
  sprintf(sayi,"%d",dikey);
  outtextxy(320,y-6,sayi);
  }
  dikey--;
   
   }
   
   //dosya okuma
   
   int dizi[100];
   int n=0;
   int sayilar;
   int sayac=0;
   
  int m;
   FILE *dosya;
   dosya=fopen("noktalar.txt","r");
   while(!feof(dosya))
   {
   fscanf(dosya,"%d",&sayilar);
   dizi[n]=sayilar;
   n++;
   }
   for(int i=0;i<n;i++)
   {printf("%d",dizi[i]);
   
   sayac++;
   }
  printf("\n\n\n");
 
   // x ve y noktalarýný ayýrma
int x[sayac/2];
int y[sayac/2];
for(int i=0;i<sayac/2;i++)
{

x[i]=dizi[a];
y[i]=dizi[a+1];
a+=2;

}
for(int i=0;i<sayac/2;i++)
{

printf("\t");
printf("%d.koordinatlar x:%d",i+1,x[i]);

}
printf("\n");
for(int i=0;i<sayac/2;i++)
{

printf("\t");
printf("%d.koordinatlar y:%d ",i+1,y[i]);

}



 // en buyuk en kucuk nokta bulma
float enkx=x[0];
float enbx=x[0];
float enky=y[0];
float enby=y[0];

for(int i=0;i<sayac/2;i++)
{
if(enbx<x[i])
enbx=x[i];

if(enby<y[i])
enby=y[i];

if(enkx>x[i+1])
enkx=x[i+1];

if(enky>y[i+1])
enky=y[i+1];

}

printf("\n");
printf("%0.1f",enkx);

printf("\n");
printf("%0.1f",enbx);

printf("\n");
printf("%0.1f",enky);

printf("\n");
printf("%0.1f",enby);

//dörtgen köþegeni ile çap oluþturma

cap=sqrt(pow((enbx-enkx),2)+pow((enby-enky),2));
r=cap/2;

for(int i=0;i<sayac/2;i++)
{
if(y[i]==0)
{
tempy++;
}
if(tempy==sayac/2)
{
cap=(enbx-enkx);
r=cap/2;
}
}


for(int i=0;i<sayac/2;i++)
{
if(x[i]==0)
{
tempx++;
}
if(tempx==sayac/2)
{
cap=(enby-enky);
r=cap/2;
}
}



printf("\n yaricap uzunlugu:%0.2f ",r);

//merkez noktasý bulmma

merkezx=(enbx+enkx)/2;
merkezy=(enby+enky)/2;

printf("/merkez noktasi:{%0.1f,%0.1f}",merkezx,merkezy);



//noktalarý çizdirme


for(int i=0;i<sayac/2;i++)
{

if(x[i]>=0)
x[i]=300+(x[i]*30);

if(y[i]>=0)
y[i]=270-(y[i]*30);

if(x[i]<0)
x[i]=300-(x[i]*-30);

if(y[i]<0)
y[i]=270+(y[i]*30*-1);

circle(x[i],y[i],2);
}



//çember çizdirme
if(merkezx>=0)
{
merkezx=300+(merkezx*30);
}

if(merkezx<0)
{
merkezx=300-(merkezx*-30);
}

if(merkezy>=0)
{
merkezy=270-(merkezy*30);
}

if(merkezy<0)
{
merkezy=270+(merkezy*30*-1);
}

r=r*30;

circle(merkezx,merkezy,r);

//b spline

double putx,puty;
double t;


if(sayac/2==3)
{
for(t=0.0;t<=1.0;t+=0.0001)
{
    putx=pow(1-t,2)*x[0]+2*t*(1-t)*x[1]+pow(t,3)*x[2];
puty=pow(1-t,2)*y[0]+2*t*(1-t)*y[1]+pow(t,3)*y[2];
putpixel(putx,puty,RED);
}
}



if(sayac/2==4)
{
for(t=0.0;t<=1.0;t+=0.0001)
{
   putx=pow(1-t,3)*x[0]  +  3*t*pow(1-t,2)*x[1]  +  3*t*t*(1-t)*x[2]  +  pow(t,3)*x[3];
puty=pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*t*t*(1-t)*y[2]+pow(t,3)*y[3];
putpixel(putx,puty,RED);
}
}



if(sayac/2==5)
{
for(t=0.0;t<=1.0;t+=0.0001)
{
   putx= pow(1-t,4)*x[0] + 4*t*pow(1-t,3)*x[1]  +  4*t*t*pow(1-t,2)*x[2]  +  4*t*t*t*(1-t)*x[3]  +  pow(t,3)*x[4];
   puty= pow(1-t,4)*y[0] + 4*t*pow(1-t,3)*y[1]  +  4*t*t*pow(1-t,2)*y[2]  +  4*t*t*t*(1-t)*y[3]  +  pow(t,3)*y[4];
putpixel(putx,puty,RED);
}
}







  getch();
  closegraph();

}
