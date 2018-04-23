#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<ctype.h>
#include<stdlib.h>
#include<string>

using namespace std;
string line;
ifstream  file ("data.txt");

int ln = 0;
int counter =0;

string arr[51050];
float arr_stamp[51050];
float arr_sec[51050];
float arr_nsec[51050];

float arr_x[51050];
float arr_y[51050];
float arr_w[51050];
float arr_z[51050];

float arr_x_a[51050];
float arr_y_a[51050];
float arr_z_a[51050];
float arr_w_a[51050];

float arr_x_lin[51050];
float arr_y_lin[51050];
float arr_z_lin[51050];
float arr_w_lin[51050];

float total_sec = 0;
float total_nsec = 0;
float Time = 0;

float orien_x = 0;
float orien_y = 0;
float orien_z = 0;
float orien_w = 0;

float ang_x = 0;
float ang_y = 0;
float ang_z = 0;
float ang_w = 0;

float lin_x = 0;
float lin_y = 0;
float lin_z = 0;
float lin_w = 0;

int main()
{




if(file.is_open())
	{
	 
	 while(getline(file,line))
	 {
		 
		arr[ln] = line;
		ln++;
			 
     }
     file.close();
     
     ln=0;
     int sec_count = 0;
	 int nsec_count = 0;
	 
	 int x_count = 0;
	 int z_count = 0;
	 int y_count = 0;
	 int w_count = 0;
	 
	 int x_count_a = 0;
	 int y_count_a = 0;
	 int z_count_a = 0;
	 int w_count_a = 0;
	 
	 int x_count_lin = 0;
	 int y_count_lin = 0;
	 int z_count_lin = 0;
	 int w_count_lin = 0;

	 
	for(int l=0;l<51050;l++){ 
	 
     float stmp = arr[ln].find("stamp");
		if(stmp != std::string::npos)
			ln++;
		
		float sec = arr[ln].find(" sec: ");
		float p2;
		string number = arr[ln].substr(7,5);
	    arr_sec[sec_count] = std::stof(number);
	    ln++;
	    total_sec += arr_sec[sec_count];
	    sec_count++;
    
		float nsec = arr[ln].find(" ");
	    number = arr[ln].substr(8,10);
	    arr_nsec[nsec_count] = std::stof(number);
	    ln++;
	    total_nsec += arr_nsec[nsec_count];
	    nsec_count++;
       
     float br = arr[ln].find("}");  
       if(stmp != std::string::npos)
			ln++;
		
	 float entity = arr[ln].find("entity");  
       if(stmp != std::string::npos)
			ln++;		
			
	 float orien = arr[ln].find("orientation");  
       if(stmp != std::string::npos)
			ln++;		
		
	 float x = arr[ln].find(" ");
	    number = arr[ln].substr(4,25);
	    arr_x[x_count] = std::stof(number);		
	    orien_x += arr_x[x_count];
	    x_count++;
	    ln++;
	    
	 float y = arr[ln].find(" ");
	    number = arr[ln].substr(4,25);
	    arr_y[y_count] = std::stof(number);
	    orien_y += arr_y[y_count];	
	    y_count++;
	    ln++;  
	    
	 float z = arr[ln].find(" ");
	    number = arr[ln].substr(4,25);
	    arr_z[z_count] = std::stof(number);	
	    orien_z += arr_z[z_count];	
	    z_count++;
	    ln++;    
	    
	 float w = arr[ln].find(" ");
	    number = arr[ln].substr(4,25);
	    arr_w[w_count] = std::stof(number);	
	    orien_w += arr_w[w_count];	
	    w_count++;
	    ln++;
	       
	  br = arr[ln].find("}");  
       if(stmp != std::string::npos)
			ln++;
		
	  float ang = arr[ln].find("angular");  
       if(stmp != std::string::npos)
			ln++;
	  			
			      
	   float x_a = arr[ln].find(" ");
	    number = arr[ln].substr(4,25);
	    arr_x_a[x_count_a] = std::stof(number);		
	    ang_x += arr_x_a[x_count_a];
	    x_count_a++;
	    ln++;
	   
	   float y_a = arr[ln].find(" ");
	    number = arr[ln].substr(4,25);
	    arr_y_a[y_count_a] = std::stof(number);	
	    ang_y += arr_y_a[y_count_a];	
	    y_count_a++;
	    ln++; 
	    	     
	    float z_a = arr[ln].find(" ");
	    number = arr[ln].substr(4,25);
	    arr_z_a[z_count_a] = std::stof(number);	
	    ang_z += arr_z_a[z_count_a];	
	    z_count_a++;
	    ln++; 	  
	    
	    br = arr[ln].find("}");  
        if(stmp != std::string::npos)
			ln++;   
	    
	    float lin = arr[ln].find("linear");  
        if(stmp != std::string::npos)
			ln++;
		
		float x_lin = arr[ln].find(" ");
	    number = arr[ln].substr(4,25);
	    arr_x_lin[x_count_lin] = std::stof(number);	
	    lin_x += arr_x_lin[x_count_lin];	
	    x_count_lin++;
	    ln++;	
		
		float y_lin = arr[ln].find(" ");
	    number = arr[ln].substr(4,25);
	    arr_y_lin[y_count_lin] = std::stof(number);	
	    lin_y += arr_y_lin[y_count_lin];		
	    y_count_lin++;
	    ln++;
	    
	    float z_lin = arr[ln].find(" ");
	    number = arr[ln].substr(4,25);
	    arr_z_lin[z_count_lin] = std::stof(number);	
	    lin_z += arr_z_lin[z_count_lin];		
	    z_count_lin++;
	    ln++;	
	    
	    br = arr[ln].find("}");  
        if(stmp != std::string::npos)
			ln++;
			
		br = arr[ln].find(" ");  
        if(stmp != std::string::npos)
			ln++;
	
		
			cout<<"stamp{"<<'\n';
			cout<<"  "<<"sec:"<<'\n';
		    cout<<"  "<<total_sec<<'\n';
		    cout<<"  "<<"nsec:"<<'\n';
		    cout<<"  "<<total_nsec<<'\n';
		    cout<<"}"<<'\n';
		    
		    
		    
		    cout<<"orientatio{"<<'\n';
			cout<<"  "<<"x:"<<'\n';
		    cout<<"  "<<orien_x<<'\n';
		    cout<<"  "<<"y:"<<'\n';
		    cout<<"  "<<orien_y<<'\n';
		    cout<<"  "<<"z:"<<'\n';
		    cout<<"  "<<orien_z<<'\n';
		    cout<<"  "<<"w:"<<'\n';
		    cout<<"  "<<orien_w<<'\n';
		    cout<<"}"<<'\n';
		    
		    
		    
		    cout<<"angular_velocity{"<<'\n';
			cout<<"  "<<"x:"<<'\n';
		    cout<<"  "<<ang_x<<'\n';
		    cout<<"  "<<"y:"<<'\n';
		    cout<<"  "<<ang_y<<'\n';
		    cout<<"  "<<"z:"<<'\n';
		    cout<<"  "<<ang_z<<'\n';
		    
		    
		    cout<<"linear_acceleration{"<<'\n';
			cout<<"  "<<"x:"<<'\n';
		    cout<<"  "<<lin_x<<'\n';
		    cout<<"  "<<"y:"<<'\n';
		    cout<<"  "<<lin_y<<'\n';
		    cout<<"  "<<"z:"<<'\n';
		    cout<<"  "<<lin_z<<'\n';
		    cout<<"}"<<'\n';
		    cout<<'\n';
		    cout<<'\n';
		    
	
		
		} //---------------for loop
		
		
	   
	   } 
	   
}

