#include "button.h"

void check_button(void){
	int e=-1;
	if ((BUTTON & (1<<PC0))) {
		e=0;
	}
	if ((BUTTON & (1<<PC1))) {
		e=1;
	}
	if ((BUTTON & (1<<PC2))) {
		e=2;
	}
	if ((BUTTON & (1<<PC3))) {
		e=3;
	}
	//if (e==-1) return 0;
	if (e==0){
		dir_x = -1;
		dir_y = 0;
		}else if (e==1){
		dir_x = 0;
		dir_y = -1;
		}else if (e==2){
		dir_x = 0;
		dir_y = 1;
		}else if (e==3){
		dir_x = 1;
		dir_y = 0;
	}
}
