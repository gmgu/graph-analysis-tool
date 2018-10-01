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


   int check_vertice=0;
   int check_arc=0;

   while(getline(in, line)){

     std::string f1="*Vertices";
     std::string f2="*vertices";
     std::string f3="*arcs";
     std::string f4="*Arcs";

     ssize_t pos;
     if((pos=line.find(f1)) !=std::string::npos || (pos=line.find(f2)) !=std::string::npos){
        check_vertice=1;
        continue;
     }
     else if((pos=line.find(f3)) !=std::string::npos || (pos=line.find(f4)) !=std::string::npos){
       check_arc=1;
       check_vertice=0;
       continue;
     }

     if(check_vertice==1){
       std::istringstream iss_vertice(line);
       int order_vertice=0;
       do {
         std::string sub;
         iss_vertice>>sub;
         std::regex num("[0-9]+");
         std::sregex_iterator it(sub.begin(), sub.end(), num);
         std::sregex_iterator end;

         while(it !=end){
           std::smatch m=*it;
           int one=atoi(m.str(0).c_str()); // 숫자매치되면 one에 저장
           std::cout<<one;   // test용 출력
           ++it;
         }


         if(order_vertice<1) std::cout<<" ";  // test용 출력
         else std::cout<<std::endl;   // test용 출력
         order_vertice++;

       } while(iss_vertice && order_vertice<=1); //order가 0, 1인 것만 추출할 것임 -> order 0 = VId, order 1 = Vlabel

     }

     if(check_arc==1){
       // arcs 받아들이는 부분
       // label이 문자열인 자료형이 많아 label 전처리 과정 필요
       // label 받아들이는 부분은 아직
       std::istringstream iss_arc(line);
       int order_arc=0;
       do {
         std::string sub;
         iss_arc>>sub;
         std::regex num("[0-9]+");
         std::sregex_iterator it(sub.begin(), sub.end(), num);
         std::sregex_iterator end;

         while(it !=end){
           std::smatch m=*it;
           int one=atoi(m.str(0).c_str());
           std::cout<<one;            // test용 출력
           ++it;
         }
         if(order_arc<2) std::cout<<" ";   // test용 출력
         else std::cout<<std::endl;   // test용 출력
         order_arc++;

       } while(iss_arc && order_arc<=2); //order 0, 1, 2 추출
       // order 0 = 시작vertex Id, order 1 = 도착vertex Id, order 3= weight, order 4=label..
       /* TO DO:
       1. 라벨 전처리는 어떻게?
       2. 여러개의 라벨을 받을 때는 어떻게?
       */
     }

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
