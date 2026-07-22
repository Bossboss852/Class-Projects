#include <iostream>
#include <cmath>

int main();
double percent_calc(double finalexam_grade, double test_grade, double test_maxgrade);

int main(){
   double finalexam_maxgrade;
   double finalexam_grade;
   double midterm_maxgrade;
   double midterm_grade;
   double project_maxgrade1;
   double project_grade1;
   double project_maxgrade2;
   double project_grade2;
   double project_grade3;
   double project_maxgrade3;
   double project_grade4;
   double project_maxgrade4;
   double project_grade5;
   double project_maxgrade5;
   double projectoverall;
   double finalgrade{0};
   do {
   std::cout << "What was the maximum grade achievable on the final exam? ";
   std::cin >> finalexam_maxgrade;
   } while (finalexam_maxgrade <= 0 || finalexam_maxgrade != std::round(finalexam_maxgrade));

   do {
   std::cout << "What was the grade you achieved on the final exam? ";
   std::cin >> finalexam_grade;
   } while (finalexam_grade < 0 || finalexam_grade > finalexam_maxgrade);

   do {
   std::cout << "What was the maximum grade achievable on the midterm? ";
   std::cin >> midterm_maxgrade;
   } while (midterm_maxgrade <= 0 || midterm_maxgrade != std::round(midterm_maxgrade));

   do {
   std::cout << "What was the grade you achieved on the midterm? ";
   std::cin >> midterm_grade;
   } while (midterm_grade < 0 || midterm_grade > midterm_maxgrade);

   do {
   std::cout << "What was the maximum grade achievable on Project1? ";
   std::cin >> project_maxgrade1;
   } while (project_maxgrade1 <= 0 || project_maxgrade1 != std::round(project_maxgrade1));
   
   do {
   std::cout << "What was the grade you achieved on Project1? ";
   std::cin >> project_grade1;
   } while (project_grade1 < 0 || project_grade1 > project_maxgrade1);

   do {
   std::cout << "What was the maximum grade achievable on Project2? ";
   std::cin >> project_maxgrade2;
   } while (project_maxgrade2 <= 0 || project_maxgrade2 != std::round(project_maxgrade2));

   do {
   std::cout << "What was the grade you achieved on Project2? ";
   std::cin >> project_grade2;
   } while (project_grade2 < 0 || project_grade2 > project_maxgrade2);

   do {
   std::cout << "What was the maximum grade achievable on Project3? ";
   std::cin >> project_maxgrade3;
   } while (project_maxgrade3 <= 0 || project_maxgrade3 != std::round(project_maxgrade3));

   do {
   std::cout << "What was the grade you achieved on Project3? ";
   std::cin >> project_grade3;
   } while (project_grade3 < 0 || project_grade3 > project_maxgrade3);

   do {
   std::cout << "What was the maximum grade achievable on Project4? ";
   std::cin >> project_maxgrade4;
   } while (project_maxgrade4 <= 0 || project_maxgrade4 != std::round(project_maxgrade4));

   do {
   std::cout << "What was the grade you achieved on Project4? ";
   std::cin >> project_grade4;
   } while (project_grade4 < 0 || project_grade4 > project_maxgrade4);

   do {
   std::cout << "What was the maximum grade achievable on Project5? ";
   std::cin >> project_maxgrade5;
   } while (project_maxgrade5 <= 0 || project_maxgrade5 != std::round(project_maxgrade5));

   do {
   std::cout << "What was the grade you achieved on Project5? ";
   std::cin >> project_grade5;
   } while (project_grade5 < 0 || project_grade5 > project_maxgrade5);

   // Determine all of the percentage grades
   finalexam_grade = 100*(finalexam_grade/finalexam_maxgrade);
   midterm_grade = percent_calc(finalexam_grade, midterm_grade, midterm_maxgrade);
   project_grade1 = percent_calc(finalexam_grade, project_grade1, project_maxgrade1);
   project_grade2 = percent_calc(finalexam_grade, project_grade2, project_maxgrade2);
   project_grade3 = percent_calc(finalexam_grade, project_grade3, project_maxgrade3);
   project_grade4 = percent_calc(finalexam_grade, project_grade4, project_maxgrade4);
   project_grade5 = percent_calc(finalexam_grade, project_grade5, project_maxgrade5);
   std::cout << "Final exam_grade " << finalexam_grade;
   std::cout << "midterm_grade " << midterm_grade;
   std::cout << "project_grade1 " << project_grade1;
   std::cout << "project_grade2 " << project_grade2;
   std::cout << "project_grade3 " << project_grade3;
   std::cout << "project_grade4 " << project_grade4;
   std::cout << "project_grade5 " << project_grade5;
   // Calculate the final grade and output it to the terminal
   finalgrade = ((3.0/4.0)*finalexam_grade) + ((1.0/4.0)*midterm_grade);
   projectoverall = (project_grade1+project_grade2+project_grade3+project_grade4+project_grade5)/5.0;
   if (finalgrade <= 40.0){
   } else if(finalgrade >= 60.0){
    finalgrade = (2.0/3.0)*finalgrade + (1.0/3.0)*projectoverall;
   } else {
    finalgrade = projectoverall*((1.0/3.0)*((finalgrade-40.0)/20.0)) + finalgrade*(1.0-((1.0/3.0)*((finalgrade-40.0)/20.0)));
   }
   std::cout << finalgrade;
   finalgrade = std::round(finalgrade + 1e-12);
   std::cout << "Final Grade: ";
   std::cout << finalgrade;
   return 0; 
}

double percent_calc(double finalexam_grade, double test_grade, double test_maxgrade){
    if (finalexam_grade > 100.0*(test_grade/test_maxgrade)){
        test_grade = (double)finalexam_grade;
    } else{
        test_grade = 100.0*((double)test_grade/(double)test_maxgrade);
    }
    return (double)test_grade;
}