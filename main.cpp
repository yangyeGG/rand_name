/*************************************************************************
    > File Name: main.cpp
    > Author: yy
    > Mail: yy@ityy520.com 
    > Created Time: Thu 13 Sep 2018 01:47:31 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include "Vector"
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<unistd.h>

int main(int argc, char** argv)
{

	if(argc != 2)
	{
		std::cerr<<"Usage error!"<<std::endl;
		return 1;
	}

	srand(time(NULL));
	std::ifstream in(argv[1]);

	if(!in)
	{
		std::cerr<<"打开 "<<argv[1]<<" 失败!"<<std::endl;
		return 1;
	}
	
	std::string name;
	Vector<std::string> names;

	while(!in.eof())
	{
		if(in >> name)
		names.push_back(name);
	}

	std::cout<<"共有"<<names.size()<<"人！"<<std::endl;

	int n,i;
	
	for(i = 0 ; i < 30;++i)
	{
		system("clear");
		n = rand()% names.size();
		std::cout<<"最终:"<<names[n]<<"!"<<std::endl;
		usleep(i*i*300);
	}

	return 0;
}
