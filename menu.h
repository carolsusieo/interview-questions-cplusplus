/*
 * menu.h
 *
 *  Created on: Feb 2, 2016
 *      Author: carolsusieo
 */

#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include <iomanip>
using namespace std;

class Menu {

  private:
       const char ** menu;
       char choice[3];
  public:
       Menu( const char ** mu ) { menu = mu; }
       void show() {
          cout << endl;
          for ( int i = 0; menu[i] != 0 ; i ++ )
              cout << "\t\t" << menu[i] << endl;
       }
       char select() {
              cout << "\t\t" << "Enter a selection : ";
              cin.getline(choice, 5);
              return choice[0];
       }
       char prompt(const char * msg) {
              cout << "\t\t" << msg;
              cin.getline(choice, 5);
              return choice[0];
       }
};




#endif /* MENU_H_ */
