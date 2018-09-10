/*************************************************************************
    > File Name: main.c
    > Author: yy
    > Mail: yy@ityy520.com 
    > Created Time: Mon 10 Sep 2018 09:14:07 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<mysql/mysql.h>

void delay(int);
int main()
{

	MYSQL mysql;
	mysql_init(&mysql);
	if(!mysql_real_connect(&mysql,"localhost","root","","yy",0,NULL,0))
		fprintf(stderr,"link error:%s\n",mysql_error(&mysql));
	mysql_query(&mysql,"set names utf8");
	char str[100];
	int id;
	srand(time(NULL));
	int i,j;
	for( i=0;i<50;i++)
	{

		system("clear");
		id=rand()%6+1;
		sprintf(str,"select name from student where id = %d",id);
		if(mysql_query(&mysql,str))
			fprintf(stderr,"error select:%s\n",mysql_error(&mysql));
		else
		{
			MYSQL_RES* res;
			res = mysql_store_result(&mysql);
			MYSQL_ROW row;
			while(row=mysql_fetch_row(res))
				printf("最终人选是:%s!\n",row[0]);
			mysql_free_result(res);
		}
		delay(i*i/6);

	}
	mysql_close(&mysql);
	return 0;
}

void delay(int n)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<500000;j++);
}
