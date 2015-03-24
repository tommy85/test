#include<iostream>
#include<map>
#include<iterator>
#include <algorithm>
#include <assert.h>
#include <string.h>

using namespace std;

typedef struct _Date
{
	 int year;
	 int month;
	 int day;
	 //int hour;
	 //int min;
	 //int seconds;
	 bool operator<(const _Date &d2) const
	 {
		  if (month == d2.month) 
			   return day < d2.day;
		  else 
			   return month < d2.month;
	 }
	 bool operator<=(const _Date &d2) const
	 {
		  if (month == d2.month) 
			   return day <= d2.day;
		  else 
			   return month < d2.month;
	 }
	 bool operator>(const _Date &d2) const
	 {
		  if (month == d2.month) 
			   return day > d2.day;
		  else 
			   return month > d2.month;
	 }
	 bool operator>=(const _Date &d2) const
	 {
		  if (month == d2.month) 
			   return day >= d2.day;
		  else 
			   return month > d2.month;
	 }
	 bool operator==(const _Date &d2) const
	 {
		  return day == d2.day && month == d2.month;
	 }
	 bool operator!=(const _Date &d2) const
	 {
		  return day != d2.day || month != d2.month;
	 }
} Date;

typedef struct _Timezone
{
	 Date start;
	 Date end;
	 int type;

//	 friend bool operator<(const _Timezone &t1,const _Timezone &t2);
/*
	 bool operator<(const _Timezone &t2) const 
	 {
		  if (type == 1 || t2.type == 1)
		  {
			   _Timezone tmp;
			   //compare time point
			   assert(!(type == 1 && t2.type == 1));
			   tmp = (type == 1)?*this:t2;

			   assert(t2.start != t2.end);
			   if (t2.start > t2.end)
			   {
					return (tmp.start < t2.start);
			   }
			   else
			   {
					return (tmp.start < t2.start);
			   }
			   
		  }
		  else
		  {
			   assert(start != end);
			   assert(t2.start != t2.end);
			   if (start > end || t2.start > t2.end)
			   {
					assert(!(start > end && t2.start > t2.end));
					return (start > end)?false:true;
			   }
			   else
			   {
					return (end < start); 
			   }
		  }
	 }
*/
/*
	 friend bool operator==(_Timezone &t1,_Timezone &t2) 
	 {
		  if (t1.type == 1 || t2.type == 1)
		  {
			   //compare time point
			   _Timezone tmp;
			   assert(!(t1.type == 1 && t2.type == 1));
			   tmp = (t1.type == 1)?t1:t2;

			   assert(t2.start != t2.end);
			   if (t2.start > t2.end)
			   {
					return (tmp.start >= t2.start) || (tmp.start <= t2.end);
			   }
			   else
			   {
					return (tmp.start <= t2.end && tmp.start >= t2.start);
			   }			   
		  }
		  else
		  {
			   //compare time zone
			   assert(t1.start != t1.end);
			   assert(t2.start != t2.end);
			   return (t1.start == t2.start && t1.end == t2.end);
		  }
	 }
*/
} Timezone;


bool operator<(const Timezone &t1,const Timezone &t2)
{
	 if (t1.type == 1 || t2.type == 1)
	 {
		  Timezone tmp1,tmp2;
		  //compare time point
		  assert(!(t1.type == 1 && t2.type == 1));
		  
		  if (t1.type == 1)
		  {
			   return t1.start < t2.start;
		  }
		  else
		  {
			   return t1.end < t2.start;
		  }
	 }
	 else
	 {
		  assert(t1.start < t1.end);
		  assert(t2.start < t2.end);

		  return (t1.end < t2.start); 
	 }
}

class Schedule
{
public:
	 Schedule(Timezone &zone,string &_uri):timezone(zone),uri(_uri){};
	 virtual ~Schedule(){};
	 void do_schedule()
	 {
		  cout<<"timezone,start year month day"<<timezone.start.year<<" "<<
			   timezone.start.month<<" "<<timezone.start.day<<endl;
		  cout<<"timezone,end year month day"<<timezone.end.year<<" "<<
			   timezone.end.month<<" "<<timezone.end.day<<endl;
		  cout<<"play "<<uri<<endl;
	 }
	 inline Timezone & GetTime()
	 {
		  return timezone; 
	 }
private:
	 Timezone timezone;
	 string uri;
};

typedef map<Timezone,Schedule> SchMap;

class ScheduleList
{
public:
	 ScheduleList(){}
	 ~ScheduleList(){}
	 void AddSchedule(Schedule &sch)
	 {
		  if (schmap.find(sch.GetTime()) == schmap.end())
		  {
			   schmap.insert(make_pair(sch.GetTime(),sch));
		  }
		  else
		  {
			   cout<<"Schedule is already exist,Sch day="<<sch.GetTime().start.day<<
					" "<<sch.GetTime().end.day<<endl;
		  }
	 }
	 void Display(Date &date)
	 {
		  Timezone tz;
		  tz.start = date;
		  tz.start.month = 0;
		  tz.type = 1;

		  SchMap::iterator it;
		  cout<<"Display"<<endl;
		  if ((it = schmap.find(tz)) != schmap.end())
		  {
			   it->second.do_schedule();
		  }
		  else
		  {
			   cout<<"find second times"<<endl;
			   tz.start.month = 1;
			   if ((it = schmap.find(tz)) != schmap.end())
			   {
					it->second.do_schedule();
			   }
			   else
			   {
					cout<<"Schedule is not exist,Date day="<<date.day<<endl;
			   }
		  }
	 }
	 void ShowSch()
	 {
		  cout<<"Show Schedule"<<endl;
		  SchMap::iterator it = schmap.begin();
		  for (;it !=schmap.end();it++)
		  {
			   it->second.do_schedule();
		  }
	 }
private:
	 SchMap schmap;
};


int main()
{
	 ScheduleList schlist;
	 Timezone tz1,tz2,tz3;
	 memset(&tz1,0,sizeof(Timezone));
	 memset(&tz2,0,sizeof(Timezone));
	 memset(&tz3,0,sizeof(Timezone));
	 /* 25~3*/
	 tz1.start.day = 25;
	 tz1.end.day = 3;
	 tz1.end.month = 1;
	 /* 7-13*/
	 tz2.start.day = 7;
	 tz2.end.day = 15;
	 /*14-22*/
	 tz3.start.day = 17;
	 tz3.end.day = 22;
/*
	 if (tz2 < tz3)
	 {
		  cout<<"tz2<tz3"<<endl;
	 }

	 less<Timezone> i;
	 if(i(tz2,tz3))
	 {
		  cout<<"tz2<tz3"<<endl;
	 }
*/


	 string str1("uri1");
	 string str2("uri2");
	 string str3("uri3");

	 Schedule sch1(tz1,str1);
	 Schedule sch2(tz2,str2);
	 Schedule sch3(tz3,str3);

	 schlist.AddSchedule(sch1);
	 schlist.AddSchedule(sch2);
	 schlist.AddSchedule(sch3);
	 cout<<"----------------------"<<endl;
	 schlist.ShowSch();
	 cout<<"----------------------"<<endl;
	 Date date;
	 date.year = 1985;
	 date.month = 5;
	 date.day = 18; 

	 schlist.Display(date);

}
