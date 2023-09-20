Vim�UnDo� �k�f�7K��1�o4�kJ�z/�����ؒ5�&   '   +InputManager::~InputManager(){ delete db; }                             e
:B    _�                     "        ����                                                                                                                                                                                                                                                                                                                            '          #          v       e
�     �       "   K          }    �   !   #   K       5��                          �                     5�_�                    !       ����                                                                                                                                                                                                                                                                                                                            &          "          v       e
�    �          L      #include "inputManager.h"       #include <ncurses.h>   4InputManager::InputManager(Database *db) : db(db) {}�         M      "void InputManager::InputThread() {         initscr();�   '   +   L      }   )void InputManager::ProcessInput(int ch) {�   7   ;   K      }   -void InputManager::ProcessEditInput(int ch) {�   A   E   J      }   "int InputManager::GetNextInput() {5��    A                    0                    �    7                    �                    �    '                    �                    �       "               �                    �                                  0       0       5�_�                    (        ����                                                                                                                                                                                                                                                                                                                            (           L           v        e
�     �   '           %       )void InputManager::ProcessInput(int ch) {     switch (ch) {     case KEY_UP:       db->MoveUp();   
    break;     case KEY_DOWN:       db->MoveDown();   
    break;     case KEY_LEFT:       db->MoveLeft();   
    break;     case KEY_RIGHT:       db->MoveRight();   
    break;     }   }       -void InputManager::ProcessEditInput(int ch) {     switch (ch) {     case KEY_LEFT:       db->MoveCardLeft();   
    break;     case KEY_RIGHT:       db->MoveCardRight();   
    break;     }   }       "int InputManager::GetNextInput() {     if (inputBuffer.empty()) {       return -1;     }     int ch = inputBuffer.front();     inputBuffer.pop();     return ch;   }5��    '       $              �      E              5�_�                    '        ����                                                                                                                                                                                                                                                                                                                            (           (           v        e
�    �   '               �   &              }    5��    &                    �                    �    '                      �                     5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             e
:      �         (    �                InputManager::~InputManager() {   }�         '       InputManager::~InputManager() {}5��                         �                      �                          �                      �                          �                      �                         �                      �                          �                      5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             e
:3     �         )       5��                          �                      �                         �                      �                        �                     �                         �                      5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             e
:5     �         )      D5��                         �                      5�_�      	                     ����                                                                                                                                                                                                                                                                                                                                                             e
:5     �         )      InputManager::~InputManager() {    �         )      D[]5��                         �                      �                         �                      �                         �                      �                         �                      �                          �                      �                         �                      �                         �                      �                          �                      �                          �                      5�_�      
           	           ����                                                                                                                                                                                                                                                                                                                                                             e
:<     �         )       InputManager::~InputManager() {d5��                         �                      5�_�   	              
          ����                                                                                                                                                                                                                                                                                                                                                             e
:=     �         )      InputManager::~InputManager() {5��                         �                      5�_�   
                        ����                                                                                                                                                                                                                                                                                                                                                             e
:>     �         )        delete db;5��                         �                      5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             e
:A    �         '      +InputManager::~InputManager(){ delete db; }�         (      InputManager::~InputManager(){       delete db; }�         )          delete db;   }5��                        �                     �                       �                     �                         �                      5��