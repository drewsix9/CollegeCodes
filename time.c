#include <stdio.h>
#include <unistd.h>

int main () {

	int h,m,s;
	int d=1000000;

	printf("Set time: \n");
	scanf("%d %d %d", &h, &m, &s);

	if( h>12 || m>60 || s>60) {
		printf("\nError\n");
		return 0;
	}

	for(;;) {

		s=s+1;
		if(s>59);
		{
			m++;
			s=0;
		}
		if(m>59) {
			h++;
			m=0;
		}
		if(h>12) {
			h=1;
		}
		printf("\nClock:");
		printf("%02d:%02d:%02d", h,m,s);
		usleep(d);
		system("cls");
	}
}