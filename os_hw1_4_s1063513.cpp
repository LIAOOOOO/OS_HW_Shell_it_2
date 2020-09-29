#include <stdio.h>
#include <string>
#include <cstring>
#include <sstream>
#include <sys/wait.h>
#include <unistd.h>
#include<errno.h>
#include <pwd.h>
#include<iostream>
#include<vector>
#include<readline/readline.h>
#include<readline/history.h>
#define RED "\033[0;32;31m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define GRAY "\033[1;30m"
#define WHITE "\033[1;37m"
using namespace std;

int main()
{
   
	while(1)
       {
        string cmd;
        char cwd[100];
        getcwd(cwd, sizeof(cwd));
        string output;
        output += GREEN;
        output += getenv("USER");
        output.append("@");
        output += BLUE;
        output += cwd;  
        output.append("> ");
        output += WHITE;
        cmd = readline(output.c_str());
        add_history(&cmd[0]);
        stringstream ss(cmd);
        string cut; 
        getline(ss,cut,' ');
        if(cut == "exit")
        {
        	cout << "\033[1;30m" << "ByeBye!" << endl;
        	break;
        }

        else if(cut == "cd")
        {
        	getline(ss,cut,' ');
        	if(cut == "..")
        	{
        		chdir("..");
        	}
        	else if(cut[0] == '/')
        	{
                        char tmp[100];
                        strcpy(tmp,cut.c_str());
                        chdir(tmp);                        
        		
        	}
        	else
        	{
                        char temp[100];
                        strcpy(temp,cut.c_str());
                        chdir(temp);
        	}
           
        }
        else
        {
               vector<string> store;
               pid_t pid;
               pid=fork();
               int counter = 0;
               store.push_back(cut);
        	while(getline(ss,cut,' '))
        	{
        		store.push_back(cut);
                        counter++;
                      
        	}
         if(pid == 0)
         {
              
                if(counter == 0)
                        execlp(store[0].c_str(),store[0].c_str(),NULL);
                else
                      execlp(store[0].c_str(),store[0].c_str(),store[1].c_str(),NULL);          
          }
         
          else
                wait(NULL); 
        }
      
    }
}
