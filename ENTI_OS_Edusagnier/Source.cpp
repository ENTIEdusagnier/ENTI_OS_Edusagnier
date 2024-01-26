#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <queue>
#include <stack>
#include <vector>
#include <list>

using namespace std; //Permite no utilizar std::


void main()
{

	string menu[5] = { " Gestionar Usuarios"," Cambiar de usuario"," Gestionar directorios"," Gestionar Tareas"," Salir" };
	string menu_gestionar_usuario[4] = { " Crear Usuario"," Modificar Password"," Eliminar Usuario"," Volver" };
	string menu_gestionar_directorios[5] = { " Ver Directorios"," Crear Directorios"," Renombrar Directorios"," Eliminar Directorios"," Volver" };
	string menu_gestionar_tareas[4] = { " Crear Tarea"," Mostrar Siguiente Tarea"," Completar Tarea"," Volver" };

	vector <string> users;
	vector <string> passwords;

	users.push_back("admin");
	passwords.push_back("admin");

	users.push_back("edusagnier");
	passwords.push_back("123456789");

	string user_insert;
	string password_insert;

	cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
	cout << "               ENTI OS             " << endl;
	cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;

	cout << endl << endl;

	bool user_insert_right = false;



	while (!user_insert_right)
	{
		bool user_exsist = false;


		cout << "Introduce Usuario: " << endl;
		cin >> user_insert;

		cout << endl;

		cout << "Introduce Password: " << endl;
		cin >> password_insert;


		for (int i = 0; i < users.size(); i++)
		{

			if (users[i] == user_insert)
			{
				cout << "Users Exists" << endl; //DEBUG
				user_exsist = true;

				if (password_insert == passwords[i])
				{
					user_insert_right = true;
					cout << "Good Password" << endl;
				}
				else
				{
					system("cls");
					cout << "Wrong Password" << endl;
				}

			}
			if (!user_exsist)
			{
				system("cls");
				cout << "Wrong User" << endl;
			}
		}
	}


	char user_select_option;
	bool menu_principal = false;
	bool num_menu_right = false;

	bool volver_gestionar_usuario = false;
	bool volver_gestionar_directorios = false;
	bool volver_gestionar_tareas = false;

	while (!menu_principal)
	{
		system("cls");
		cout << "Estas logguedo como " << user_insert << endl;

		if (user_insert == "admin")
		{
			for (int i = 0; i <= 4; i++)
			{
				cout << i + 1 << "-" << menu[i] << endl;
			}

			num_menu_right = false;
			while (!num_menu_right)
			{
				cout << endl << "Inserta el numero que quieres" << endl;
				cin >> user_select_option;

				if ((int)user_select_option > 48 && (int)user_select_option < 54)
				{
					cout << "El numero insertado es correcto" << endl;
					num_menu_right = true;

				}
				else
				{
					cout << "El numero no esta entre el 1-5" << endl;
				}

			}

			if (user_select_option == '1')
			{
				while (!volver_gestionar_usuario)
				{
					system("cls");
					bool insert_menu_1 = false;
					while (!insert_menu_1)
					{
						char insert_gestionar;

						cout << "Estas logguedo como " << user_insert << endl;
						for (int i = 0; i < 4; i++)
						{
							cout << i + 1 << "-" << menu_gestionar_usuario[i] << endl;
						}
						cout << endl;
						cout << endl << "Inserta el numero que quieres" << endl;
						cin >> insert_gestionar;

						if ((int)user_select_option > 48 && (int)user_select_option < 53)
						{
							cout << "El numero insertado es correcto" << endl;
							insert_menu_1 = true;

						}
						else
						{
							cout << "El numero no esta entre el 1-4" << endl;
						}
					}
					

				}
			}
		}
		else
		{
			for (int i = 1; i <= 4; i++)
			{
				cout << i << "-" << menu[i] << endl;
			}
			while (!num_menu_right)
			{
				cout << endl << "Inserta el numero que quieres" << endl;
				cin >> user_select_option;

				if ((int)user_select_option > 48 && (int)user_select_option < 53)
				{
					cout << "El numero insertado es correcto" << endl;
					num_menu_right = true;
				}
				else
				{
					cout << "El numero no esta entre el 1-4" << endl;
				}

			}
		}
	}










}