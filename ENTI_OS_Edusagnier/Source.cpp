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






	char user_select_option;
	bool menu_principal = false;
	bool num_menu_right = false;

	bool volver_gestionar_usuario = false;
	bool volver_gestionar_directorios = false;
	bool volver_gestionar_tareas = false;

	while (!menu_principal)
	{
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

			if (user_select_option == '1') // Entra al menu de gestionar usuario
			{
				volver_gestionar_usuario = false;
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

						if ((int)insert_gestionar > 48 && (int)insert_gestionar < 53)
						{
							cout << "El numero insertado es correcto" << endl;
							insert_menu_1 = true;

						}
						else
						{
							cout << "El numero no esta entre el 1-4" << endl;
						}

						if (insert_gestionar == '1') // Crear un usuario nuevo
						{

							bool user_created = false;

							while (!user_created)
							{
								bool exsiste_user = false;
								string new_user;
								string new_password;
								string new_password_verification;

								cout << "Introduce el usuario que quieres crear" << endl;
								cin >> new_user;

								for (int i = 0; i < users.size(); i++)
								{

									if (users[i] != new_user)
									{
										cout << "User No Existe" << endl;
									}
									else
									{
										cout << "User Existe" << endl;
										exsiste_user = true;
									}
								}
								if (!exsiste_user)
								{
									cout << "Introduce la password del usuario que quieres crear" << endl;
									cin >> new_password;
									cout << endl;
									cout << "Vuelve a introducir la password" << endl;
									cin >> new_password_verification;

									if (new_password == new_password_verification)
									{
										cout << "Passwords Coinciden" << endl;
										users.push_back(new_user);
										passwords.push_back(new_password_verification);
										cout << "Usuario Creado" << endl;
										user_created = true;
									}
									else
									{
										cout << "Passwords NO Coinciden" << endl;
									}
								}
							}
						}
						if (insert_gestionar == '2') // Para Modificar password
						{
							bool modify_correctly = false;

							while (!modify_correctly)
							{
								string user_to_modify;
								string password_new_modify;
								bool user_exisist_modify = false;

								cout << "Inserta el usuario que quieres modificar" << endl;
								cin >> user_to_modify;

								for (int i = 0; i < users.size(); i++)
								{

									if (users[i] == user_to_modify)
									{
										cout << "Users Exists" << endl;
										user_exisist_modify = true;
										cout << endl;

										cout << "Inserta la password que quieres que tenga el usuario" << endl;
										cin >> password_new_modify;

										passwords[i] = password_new_modify;

										cout << "Password Cambiada" << endl;

										modify_correctly = true;

									}
									if (!user_exisist_modify)
									{
										cout << "Users Does Not Exist" << endl;
									}
								}

							}
						}
						if (insert_gestionar == '3') //Borrar Usuario
						{
							bool deleted_correctly = false;

							while (!deleted_correctly)
							{
								string user_delete;
								string verification;
								bool user_exisist_delete = false;

								cout << "Inserta el usuario que quieres eliminar" << endl;
								cin >> user_delete;

								for (int i = 0; i < users.size(); i++)
								{

									if (users[i] == user_delete)
									{
										cout << "Users Exists" << endl;
										user_exisist_delete = true;
										cout << endl;

										users.erase(users.begin() + i); //Boramos el usuario
										passwords.erase(passwords.begin() + i);//Boramos la contraseña

										/*for (int y = 0; y < users.size(); y++) //DEBUG
										{
											cout << users[y] << endl;
										}
										*/
										cout << "Users DELETED" << endl;
										deleted_correctly = true;
									}
									if (!user_exisist_delete)
									{
										cout << "Users Does Not Exists" << endl;
									}
								}

							}
						}

						if (insert_gestionar == '4') // Para Salir del menu de gestionar Usuarios
						{
							volver_gestionar_usuario = true;
						}
					}


				}
			}
			if (user_select_option == '2') // Cambia de usuario
			{

				user_insert_right = false;
				system("cls");

			}
			
			if (user_select_option == '3') // Cambia de usuario
			{
				system("cls");


			}


			if (user_select_option == '5') // Entra al menu de gestionar usuario
			{

				menu_principal = true;

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