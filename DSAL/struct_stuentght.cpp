#include <iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
struct se11{
	string name;
	int roll;
	int scgpa;
};
class division{
	
	se11 s[15];
    int n=15;
	public :
	
	void setdata();
	void getdata();
	void sortroll();       // linear sort
	void searchroll();    // linear search
	void sortscgpa();    //bubble sort
	void seachscgpa();  //binary search
	void sortname();    // Insertion sort
	void searchName();  // linear 
	void topten();       
	void sortcgpaq();  //quick sort
	int partition(int l,int u);
    void (int l,int u);
	void common();
};

void division::setdata(){
	cout<<"enter the data of students "<<endl;
	for(int i=0;i<n;i++){
		cout<<"student " << (1+i)<<endl;
		cout<<"Enter Name : ";
		cin>>s[i].name;	
		cout<<"Enter roll no : ";
		cin>>s[i].roll;	
		cout<<"Enter student SCGPA  : ";
		cin>>s[i].scgpa;	
	}
	cout<<"\n Data Entered Successfully " <<endl<< char(1)<<endl;
}
void division::getdata(){
	cout<<"Details of student are listed below :"<<endl;
	for(int i=0;i<n;i++){
		cout<<"Name : "<< s[i].name << " Roll no. : " << s[i].roll << " SCGPA is : "<< s[i].scgpa<<endl;
	}
}
void division::sortroll(){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(s[i].roll >= s[j].roll ){
				se11 temp;
				temp = s[j];
				s[j]=s[i];
				s[i]=temp;				
				}
		}
}
	cout<<"sorting of ROll no. Done"<<endl;
}
void division::searchroll(){
	int troll;
    cout<<"Enter roll no to be searched "<<endl;
	bool b = true;
	cin>>troll;  // troll is the roll no to be searched
	for(int i=0;i<n;i++){
		if(s[i].roll == troll){
		cout<<"Name : "<< s[i].name << " Roll no. : " << s[i].roll << " SCGPA is : "<< s[i].scgpa<<endl;
		b= false;	
		}
	}
	if(b){
	cout<<"Entered roll no is not present here "<<endl;}
}
void division::sortscgpa(){
	int temp_scgpa;
	
	for(int i=0 ;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if( s[j].scgpa >s[j+1].scgpa){
				se11 temp;
				temp = s[j+1];
				s[j+1]=s[j];
				s[j]=temp; 								
			}
		}
	}
	cout<<"Sorting of SCGPA completed"<<endl;
}
void division::seachscgpa(){
	 cout << "enter SCGPA of the  student \n";
	int sname;
	cin >> sname;
	int strat = 0, endpnt = n-1;
	while (strat <= endpnt)
	{
		int mid = (strat + endpnt) / 2;
		if (strat == endpnt && s[mid].scgpa != sname)
		{
			cout << "SCGPA not found " << endl;
	            break;
	        }
	        if (s[mid].scgpa == sname)
	        {
	            cout << " index no is " << mid << " name : " << s[mid].name << " roll no is : " << s[mid].roll << " scgpa is  " << s[mid].scgpa << endl;
	            break;
	        }
	        if (s[mid].scgpa > sname)
	        {
	            endpnt = mid - 1;
	        }
	        if (s[mid].scgpa < sname)
	        {
	            strat = mid + 1;
	        }
	    }
}
void division::sortname(){
    for (int i = 1; i < n; i++)
    {
        se11 tempa ;
        tempa= s[i];
        string temp = s[i].name;
        int j = i - 1;
        while (s[j].name > temp && j >= 0)
        {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = tempa;
    }
    cout << "sorting according to Name is completed \n";	
}
void division::searchName(){
	cout<<"enter name to search "<<endl;
	string tname;
	cin>>tname;
	int i;
	for(int i=0;i<n;i++){
		if(s[i].name == tname){
			cout<<"Name : "<< s[i].name << " Roll no. : " << s[i].roll << " SCGPA is : "<< s[i].scgpa<<endl;
		}
	}
	if(i==n){
		cout<<"Name Not Found "<<endl;
	}
}
void division::topten(){
	sortscgpa();
	cout<<"top 10 students are "<<endl;
	for(int i=14;i>=5;i--){
	cout<<"Name : "<< s[i].name << " Roll no. : " << s[i].roll << " SCGPA is : "<< s[i].scgpa<<endl;	
	}
	cout<<endl;
}
int division::partition(int l,int u){
	int i=l;
    int j=u;
    int pivot= s[l].scgpa;
    while(i<=j){
        while(pivot>=s[i].scgpa  && i<= u){
            i++;
        }
        while(pivot < s[j].scgpa  && j>=0){
            j--;
        }
        if(i<j){
            swap(s[i],s[j]);
        }
    }
      if (i >= j)
    {
        swap(s[l], s[j]);
    }

    return j;
}
void division ::quicksort(int l,int u){
	 if(l>=u){
        return;
    }
    if(l<u){
        int pi = partition(l,u);
        quicksort(0,pi-1);
        quicksort(pi+1,u);
    }
}
void division ::sortcgpaq(){
	 quicksort(0,14);
}
void division ::common(){
	cout<<"Students with same marks are :"<<endl;
	int counter;
	for(int i=0;i<n;i++){
		int counter=0;
		int a=s[i].scgpa;
		for(int j=i;j<n;j++){
			if(a==s[j].scgpa){
				counter ++;
			if(counter >1){
			cout<<"Name : "<< s[j].name << " Roll no. : " << s[j].roll << " SCGPA is : "<< s[j].scgpa<<endl;
			}
		}
		}
		if(counter >1){
			cout<<"Name : "<< s[i].name << " Roll no. : " << s[i].roll << " SCGPA is : "<< s[i].scgpa<<endl;
		}
	}
	cout<<endl;
}
	int main() {

	cout<<"press \n 0 for exit \n 1 for setting data \n 2 for getting data \n 3 sorting roll no wise \n 4 search roll "<<
			"\n 5 sort cgpa \n 6 search cgpa \n 7 sort name \n 8 search name \n 9 top ten performers \n 10 Scgpa sorting using Quick Search "<<endl;
	cout<<"11 for commonstudent mark "<<endl;
	division p;
	while(1){
		int k;
		cout<<"enter the operation : ";
		cin>>k;
		if(k==0){
			cout<<"You sure to exit "<<char(2)<<endl;
			int confirm;
			cout<<"Press 1 to confirm exit OR 0 "<<endl;
			cin>>confirm;
			if(confirm==1){
				break;
			}
		}
		switch(k){
		case 1:
			p.setdata();
			break;
		case 2:
			p.getdata();
			break;
		case 3:
			p.sortroll();
			break;
		case 4: 
			p.searchroll();
			break;
		case 5:
			p.sortscgpa();
			break;
		case 6:
			cout<<"To BE AVOIDED IF DATA CONTAIN SIMILIAR OCCURANCE"<<endl;
			p.seachscgpa();
			break;
		case 7:
			p.sortname();
			break;
		case 8:
			p.searchName();
			break;
		case 9:
			p.topten();
			break;
		case 10:
			cout<<"\n Sorting Using Quicksort"<<endl;
			p.sortcgpaq();
			break;
		case 11 :
		  	p.common();
	}
    }
		cout<<"Program Terminated "<<endl;
	return 0;
}
