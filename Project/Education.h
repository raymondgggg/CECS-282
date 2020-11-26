#ifndef EDUCATION_H
#define EDUCATION_H
#include <string>
#include <fstream>

class Education{
    private:
        std::string degree;
        std::string major;
        int research; //number of researches

    public:
        Education(std::string degree, std::string major, int research);
        Education();

        std::string getDegree();
        std::string getMajor();
        int getResearch();
        void setDegree(std::string degree);
        void setMajor(std::string major);
        void setResearch(int r);

        void write(std::ofstream& out);
        void read(std::ifstream& in);
};
#endif //EDUCATION_H