#include <stdio.h>

int main(/*@unused@*/ int argc, /*@unused@*/ char *argv[])
{
#pragma unused(argc)
#pragma unused(argv)

	int distance = 100;
	float power = 2.345f;
	double super_power = 5678.4532;
	char initial = 'A';
	char first_name[] = "Zed";
	char last_name[] = "Shaw";
	int bugs = 100;
	double bug_rate = 1.2;
	long universe_of_defects = 1L * 1024L * 1024L * 1024L;
	double expected_bugs = bugs * bug_rate;
	double part_of_universe = expected_bugs / universe_of_defects;

	// this make no sense, just a demo of something weird
	char nul_byte = '\0';
	int care_percentage = bugs * nul_byte;

	printf("You are %d miles away.\n", distance);
	printf("You have %f levels of powerr.\n", power);
	printf("You have %f awesome super powers.\n", super_power);
	printf("I have an initial %c.\n", initial);
	printf("I have a first name %s.\n", first_name);
	printf("I have a last name %s.\n", last_name);
	printf("My whole name is %s %c. %s.\n",	first_name, initial, last_name);


	printf("You have %d bugs at the imaginary rate of %f.\n",
					bugs, bug_rate);

	printf("The entire universe has %ld bugs.\n", universe_of_defects);

	printf("You are expected to have %f bugs.\n", expected_bugs);

	printf("That is only a %e portion of the universe.\n",
			part_of_universe);

	printf("Wich means you should care %d%%.\n", care_percentage);
		
	return 0;
}
