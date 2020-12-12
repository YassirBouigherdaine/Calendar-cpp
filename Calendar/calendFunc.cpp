#include"calendar.h"





void draw_calend(int year)
{
	std::string months[] = { "January", "February", "March","April","May","June","July",
							"August","September","October","November","December" };

	static char daysOfMon[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int days, w;

	int y = year - 1;

	int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };                    // leading number of days values 

	int weekDay = (y + y / 4 - y / 100 + y / 400 + t[0] + 1) % 7;       // to determine the day of the week (sunday = 0)

	for (int i = 0; i < sizeof(daysOfMon); i++)
	{
		if (i == 1)      // fabruary
		{
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)    // leap year
			{
				days = 29;
			}

			else
			{
				days = daysOfMon[i];
			}

		}

		else
		{
			days = daysOfMon[i];
		}

		std::cout << "\n------------------------------------\n";
		std::cout << "\t    "<< months[i]<<" "<<year<< "\n";
		std::cout << "------------------------------------\n";

		std::cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

		for (w = 0; w < weekDay; w++)
		{
			std::cout << "     ";                        // start of month
		}

		for (int j = 1; j <= days; j++)
		{
			w++;

			std::cout << std::setw(5) << j;

			if (w > 6)                                  // start of the week 
			{
				w = 0;
				std::cout << "\n";
			}
		}

		weekDay = w;

		std::cout << "\n";
	}
}


void display_calend()
{
	system("cls");

	const time_t ttime = time(NULL);
	tm local_time;
	localtime_s(&local_time, &ttime);

	int year = 1900 + (&local_time)->tm_year;

	int choice;

	do
	{
		system("cls");

		std::cout << "************************************\n";
		std::cout << "\t   CALENDAR\n";
		std::cout << "************************************\n";
	
		draw_calend(year);

		std::cout << "\n\n************************************\n";
		std::cout << "\t   Options: \n";
		std::cout << "************************************\n";
		std::cout << "\n Press [1] to see the next year\n";
		std::cout << "\n Press [2] to see the previous year\n";
		std::cout << "\n Press [3] to quit\n";
		std::cout << "\nEnter your choice : ";

		std::cin >> choice;

		if (choice == 1)
		{
			year++;
		}

		else if (choice == 2)
		{
			year--;
		}

	} while (choice != 3);
}