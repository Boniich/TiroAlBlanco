#include "gun.h"
#include <iostream>
#include "../../../helpers/move_across_screen/move_across_screen.h"

struct GunTDA {
	int x;
	int y;
};

Gun create(int x, int y) {
	GunTDA* gun = new GunTDA;
    gun->x = x;
    gun->y = y;
	return gun;
}

void addAtInitialPosition(const Gun gun) {
    //Boca arma
    moveAcrossScreen(gun->x, gun->y - 2); printf("%c%c", 218, 191);
    //Cañon
    moveAcrossScreen(gun->x, gun->y - 1); printf("%c", 179);
    moveAcrossScreen(gun->x + 1, gun->y - 1); printf("%c", 195);
    //Mango
    moveAcrossScreen(gun->x + 2, gun->y - 1); printf("%c%c", 196, 191);
    //Aparte de atras, mango y culo del arma
    moveAcrossScreen(gun->x, gun->y); printf("%c%c%c%c", 192, 193, 196, 217);
}
void moveToLeft(const Gun gun) {

    cleanGunFromScreen(gun);

    gun->x--;
    //Se puede meter las siguientes funciones en una funcion propia y hacerlas re utilizables
    //Boca arma
    moveAcrossScreen(gun->x, gun->y - 2); printf("%c%c", 218, 191);
    //Cañon
    moveAcrossScreen(gun->x, gun->y - 1); printf("%c", 179);
    moveAcrossScreen(gun->x + 1, gun->y - 1); printf("%c", 195);
    //Mango
    moveAcrossScreen(gun->x + 2, gun->y - 1); printf("%c%c", 196, 191);
    //Aparte de atras, mango y culo del arma
    moveAcrossScreen(gun->x, gun->y); printf("%c%c%c%c", 192, 193, 196, 217);

}
void moveToRight(const Gun gun) {

    cleanGunFromScreen(gun);
    gun->x++;
    //Boca arma
    moveAcrossScreen(gun->x, gun->y - 2); printf("%c%c", 218, 191);
    //Cañon
    moveAcrossScreen(gun->x, gun->y - 1); printf("%c", 179);
    moveAcrossScreen(gun->x + 1, gun->y - 1); printf("%c", 195);
    //Mango
    moveAcrossScreen(gun->x + 2, gun->y - 1); printf("%c%c", 196, 191);
    //Aparte de atras, mango y culo del arma
    moveAcrossScreen(gun->x, gun->y); printf("%c%c%c%c", 192, 193, 196, 217);
}

void cleanGunFromScreen(const Gun gun) {
    //Boca arma
    moveAcrossScreen(gun->x, gun->y - 2); printf("   ");
    //Cañon
    moveAcrossScreen(gun->x, gun->y - 1); printf("   ");
    moveAcrossScreen(gun->x + 1, gun->y - 1); printf("   ");
    //Mango
    moveAcrossScreen(gun->x + 2, gun->y - 1); printf("  ");
                                              //printf("%c%c");
    //Aparte de atras, mango y culo del arma
  
    moveAcrossScreen(gun->x, gun->y); printf("    ");
                                      //printf("%c%c%c%c");
}