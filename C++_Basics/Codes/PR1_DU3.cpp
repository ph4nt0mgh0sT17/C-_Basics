#ifndef __PROGTEST__
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

#define EASTER_OK                0
#define EASTER_INVALID_FILENAME  1
#define EASTER_INVALID_YEARS     2
#define EASTER_IO_ERROR          3


#endif /* __PROGTEST__ */

string header = "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">\n"
"<html>\n"
"<head>\n"
"<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">\n"
"<title>C++</title>\n"
"</head>\n"
"<body>\n"
"<table width=\"300\">\n"
"<tr><th width=\"99\">den</th><th width=\"99\">mesic</th><th width=\"99\">rok</th></tr>\n";

string trailer = "</table>\n"
"</body>\n"
"</html>";

int easterReport(const char * years, const char * outFileName)
{


	

	string fileName = outFileName;

	string extension = "";

	bool startExtension = false;
	for (unsigned int i = 0; i < fileName.length(); i++)
	{
		if (fileName.at(i) == '.')
		{
			extension = fileName.at(i);
			startExtension = true;
			continue;
		}

		if (startExtension)
		{
			extension += fileName.at(i);
		}
	}

	if (extension != ".html")
	{
		
		return EASTER_INVALID_FILENAME;
	}

	stringstream ss("");
	string year = years;

	

	int index = 0;

	bool isInterval = false;
	bool isNextYear = false;
	int intervalStart, intervalEnd;

	int yearNum;

	if (year.length() == 5)
	{
		return EASTER_INVALID_YEARS;
	}

	ofstream outfile;

	outfile.open(outFileName);
	if (!outfile.is_open())
	{
		
		return EASTER_IO_ERROR;
	}
	outfile << header;
	outfile.close();

	if (outfile.fail())
	{
		
		return EASTER_IO_ERROR;
	}

	for (unsigned int i = 0; i < year.length(); i++)
	{
		if (year.at(i) == ',')
		{
			if (isNextYear)
			{
				
				return EASTER_INVALID_YEARS;
			}
			isNextYear = true;
			if (isInterval)
			{
				ss >> intervalEnd;

				if (intervalStart > intervalEnd || intervalStart >= 2200 || intervalEnd >= 2200)
				{
					
					return EASTER_INVALID_YEARS;
				}

				while (intervalStart <= intervalEnd)
				{
					
					if (intervalStart != 0)
					{
						int y = intervalStart;
						int a = y % 19;
						int b = y / 100;
						int c = y % 100;
						int d = b / 4;
						int e = b % 4;
						int f = (b + 8) / 25;
						int g = (b - f + 1) / 3;
						int h = ((19 * a) + b - d - g + 15) % 30;
						int i = c / 4;
						int k = c % 4;
						int l = (32 + (2 * e) + (2 * i) - h - k) % 7;
						int m = (a + (11 * h) + (22 * l)) / 451;
						int n = (h + l - (7 * m) + 114) / 31;
						int p = (h + l - (7 * m) + 114) % 31;

						string month;
						if (n == 3)
						{
							month = "brezen";
						}

						if (n == 4)
						{
							month = "duben";
						}


						outfile.open(outFileName, ios_base::app);

						if (!outfile.is_open())
						{
						
							return EASTER_IO_ERROR;
						}

						outfile << "<tr><td>" << (p + 1) << "</td><td>" << month << "</td><td>" << y << "</td></tr>\n";
						outfile.close();

						if (outfile.fail())
						{
							
							return EASTER_IO_ERROR;

						}
					}
					
					
					intervalStart++;
				}
				isInterval = false;
				ss.clear();
				ss.str("");
				intervalStart = intervalEnd = 0;
				continue;
			}
			ss >> yearNum;

			if (yearNum >= 2200 || yearNum <= 1582)
			{
				
				return EASTER_INVALID_YEARS;
			}

			if (yearNum != 0)
			{
				int y = yearNum;
				int a = y % 19;
				int b = y / 100;
				int c = y % 100;
				int d = b / 4;
				int e = b % 4;
				int f = (b + 8) / 25;
				int g = (b - f + 1) / 3;
				int h = ((19 * a) + b - d - g + 15) % 30;
				int i = c / 4;
				int k = c % 4;
				int l = (32 + (2 * e) + (2 * i) - h - k) % 7;
				int m = (a + (11 * h) + (22 * l)) / 451;
				int n = (h + l - (7 * m) + 114) / 31;
				int p = (h + l - (7 * m) + 114) % 31;

				string month;
				if (n == 3)
				{
					month = "brezen";
				}

				if (n == 4)
				{
					month = "duben";
				}


				outfile.open(outFileName, ios_base::app);

				if (!outfile.is_open())
				{
					
					return EASTER_IO_ERROR;
				}

				outfile << "<tr><td>" << (p + 1) << "</td><td>" << month << "</td><td>" << y << "</td></tr>\n";
				outfile.close();

				if (outfile.fail())
				{
					
					return EASTER_IO_ERROR;

				}
			}


			
			index++;
			ss.clear();
			ss.str("");
			continue;
		}

		if (year.at(i) == '-')
		{
			if (isInterval)
			{
				
				return EASTER_INVALID_YEARS;
			}
			ss >> intervalStart;
			isInterval = true;
			ss.str("");
			ss.clear();
			continue;
		}

		// skip space
		if (year.at(i) == ' ')
		{
			continue;
		}

		if (!(((char)year.at(i) > 47 && (char)year.at(i) < 58) || year.at(i) == '-' || year.at(i) == ',' || year.at(i) == ' '))
		{
			
			return EASTER_INVALID_YEARS;
		}

		ss << year.at(i);
		isNextYear = false;
	}

	if (isInterval)
	{
		ss >> intervalEnd;

		if (intervalStart > intervalEnd || intervalStart >= 2200 || intervalEnd >= 2200)
		{

			return EASTER_INVALID_YEARS;
		}

		while (intervalStart <= intervalEnd)
		{
			if (intervalStart != 0)
			{
				int y = intervalStart;
				int a = y % 19;
				int b = y / 100;
				int c = y % 100;
				int d = b / 4;
				int e = b % 4;
				int f = (b + 8) / 25;
				int g = (b - f + 1) / 3;
				int h = ((19 * a) + b - d - g + 15) % 30;
				int i = c / 4;
				int k = c % 4;
				int l = (32 + (2 * e) + (2 * i) - h - k) % 7;
				int m = (a + (11 * h) + (22 * l)) / 451;
				int n = (h + l - (7 * m) + 114) / 31;
				int p = (h + l - (7 * m) + 114) % 31;

				string month;
				if (n == 3)
				{
					month = "brezen";
				}

				if (n == 4)
				{
					month = "duben";
				}


				outfile.open(outFileName, ios_base::app);

				if (!outfile.is_open())
				{
					
					return EASTER_IO_ERROR;
				}

				outfile << "<tr><td>" << (p + 1) << "</td><td>" << month << "</td><td>" << y << "</td></tr>\n";
				outfile.close();

				if (outfile.fail())
				{
					
					return EASTER_IO_ERROR;

				}
			}
			
			
			intervalStart++;
		}
		isInterval = false;
		ss.clear();
		ss.str("");
		intervalStart = intervalEnd = 0;
		
	}

	int endYear = 0;

	ss >> endYear;

	if (endYear != 0)
	{
		if (endYear <= 1582 || endYear >= 2200)
		{
			return EASTER_INVALID_YEARS;
		}
		if (endYear != 0)
		{
			int y = endYear;
			int a = y % 19;
			int b = y / 100;
			int c = y % 100;
			int d = b / 4;
			int e = b % 4;
			int f = (b + 8) / 25;
			int g = (b - f + 1) / 3;
			int h = ((19 * a) + b - d - g + 15) % 30;
			int i = c / 4;
			int k = c % 4;
			int l = (32 + (2 * e) + (2 * i) - h - k) % 7;
			int m = (a + (11 * h) + (22 * l)) / 451;
			int n = (h + l - (7 * m) + 114) / 31;
			int p = (h + l - (7 * m) + 114) % 31;

			string month;
			if (n == 3)
			{
				month = "brezen";
			}

			if (n == 4)
			{
				month = "duben";
			}


			outfile.open(outFileName, ios_base::app);

			if (!outfile.is_open())
			{
				
				return EASTER_IO_ERROR;
			}

			outfile << "<tr><td>" << (p + 1) << "</td><td>" << month << "</td><td>" << y << "</td></tr>\n";
			outfile.close();

			if (outfile.fail())
			{
				
				return EASTER_IO_ERROR;

			}
		}
	}





	outfile.open(outFileName, ios_base::app);

	if (!outfile.is_open())
	{
		return EASTER_IO_ERROR;
	}

	outfile << trailer;
	outfile.close();

	if (outfile.fail())
	{
		return EASTER_IO_ERROR;
	}
	


	
	return 0;
}


#ifndef __PROGTEST__
int main()
{
	/* tests */
	int stat = easterReport("", "out1.html");
		
	cout << "Status: " << stat << endl;

	system("pause");

	return 0;
}
#endif /* __PROGTEST__ */