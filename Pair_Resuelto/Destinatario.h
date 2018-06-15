/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _DESTINATARIO_H
#define _DESTINATARIO_H
struct
{

    char name[128];
    char mail[128];


}typedef Destinatario;


Destinatario* destinatario_new(void);
Destinatario* destinatario_newParametros(char* name, char* mail);
void destinatario_delete(Destinatario* this);
int destinatario_setName(Destinatario* this, char* name);
int destinatario_getName(Destinatario* this, char* name);
int destinatario_setMail(Destinatario* this, char* mail);
int destinatario_getMail(Destinatario* this, char* mail);
int destinatario_compare(Destinatario* pDestinatarioA,Destinatario* pDestinatarioB);
void destinatario_print(Destinatario* this);
int destinatario_compareName(Destinatario* pDestinatarioA,Destinatario* pDestinatarioB);
int comparoDest(void* el0, void* el1);
#endif // _DESTINATARIO_H



