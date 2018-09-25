/*
intput : file pointer
output : Graph
Graph a = new Graph() -> a.add_ve....
*/
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include "graph.h"
#include <regex>

//snu::Graph producegraph(std::string filepath){
void producegraph(std::string filepath){
   std::ifstream in(filepath);
   std::string line;
   int test=0;
while(getline(in, line)){
     std::string dis="*";
     ssize_t pos;
     if((pos=line.find(dis)) !=std::string::npos){
       if(test==0){
         test++;
         continue;
       }
       else break;
     }

     std::istringstream iss(line);
     int temp=0;
     do {
       std::string sub;
       iss>>sub;
       std::regex num("[0-9]+");
       std::sregex_iterator it(sub.begin(), sub.end(), num);
       std::sregex_iterator end;

       while(it !=end){
         std::smatch m=*it;
         int one=atoi(m.str(0).c_str());
         std::cout<<one;
         ++it;
       }
       if(temp==0) std::cout<<" ";
       else std::cout<<std::endl;
       temp++;

     } while(iss && temp<=1);

   }


   // arcs 받아들이는 부분
   // label이 문자열인 자료형이 많아 label 전처리 과정 필요
   // label 받아들이는 부분은 아직
   while(getline(in, line)){
        std::istringstream iss(line);
        int temp=0;
        do {
          std::string sub;
          iss>>sub;
          std::regex num("[0-9]+");
          std::sregex_iterator it(sub.begin(), sub.end(), num);
          std::sregex_iterator end;

          while(it !=end){
            std::smatch m=*it;
            int one=atoi(m.str(0).c_str());
            std::cout<<one;
            ++it;
          }
          if(temp<2) std::cout<<" ";
          else std::cout<<std::endl;
          temp++;

        } while(iss && temp<=2);

      }


   //snu::Graph a= new Graph();
   //return a
 }

int main(){
  //Graph a =
  producegraph("A96.net");
  //snu::Graph data = new DSGraph()
  return 0;

}
