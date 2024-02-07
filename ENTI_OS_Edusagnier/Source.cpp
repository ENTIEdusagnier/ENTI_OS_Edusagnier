#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <windows.h> // Para hacer un Sleep para poder dejar un tiempo y borrar la terminal. (Sacado de mi proyecto hundir la flota).

#include <queue>
#include <vector>
#include <string>

using namespace std; //Permite no utilizar std::


void main()
{

	string menu[5] = { " Gestionar Usuarios"," Cambiar de usuario"," Gestionar directorios"," Gestionar Tareas"," Salir" };
	string menu_gestionar_usuario[4] = { " Crear Usuario"," Modificar Password"," Eliminar Usuario"," Volver" };
	string menu_gestionar_directorios[5] = { " Ver Directorios"," Crear Directorios"," Renombrar Directorios"," Eliminar Directorios"," Volver" };
	string menu_gestionar_tareas[4] = { " Crear Tarea"," Mostrar Siguiente Tarea"," Completar Tarea"," Volver" };

	vector <string> users;
	vector <string> passwords;

	vector  <queue <string>> tareas;
	queue <string> cola;

	tareas.push_back(cola); // Creamos un espacio para admin

	users.push_back("admin");
	passwords.push_back("admin");

	users.push_back("edusagnier");
	passwords.push_back("123456789");
	tareas.push_back(cola);


	string user_insert;
	string password_insert;

	cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
	cout << "               ENTI OS             " << endl;
	cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;

	cout << endl << endl;

	//Esto puede ir dentro del while principal?
	bool user_insert_right = false;


	char user_select_option;
	bool menu_principal = false;
	bool num_menu_right = false;

	bool volver_gestionar_usuario = false;
	bool volver_gestionar_directorios = false;
	bool volver_gestionar_tareas = false;

	while (!menu_principal)
	{
		while (!user_insert_right) // Inicio de Session correcto
		{
			bool user_exsist = false;

			cout << "Introduce Usuario: " << endl; // Introduce el usuario para inicar session
			cin >> user_insert;

			cout << endl;

			cout << "Introduce Password: " << endl; // Introduce la password para inicar session
			cin >> password_insert;


			for (int i = 0; i < users.size(); i++)
			{

				if (users[i] == user_insert)
				{
					cout << "Users Exists" << endl; //DEBUG
					user_exsist = true; // Si existe no sacara el mensaje de que no exsiste

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
			}
			if (!user_exsist) //Deberia ir fuera del for no?
			{
				system("cls");
				cout << "Wrong User" << endl;
			}
		}

		system("cls");
		cout << "Estas logguedo como " << user_insert << endl;

		if (user_insert == "admin") //Detecta si el usuario iniciado es admin o no.
		{
			for (int i = 0; i <= 4; i++) //Saca el menu de admin que son los 5 (0-4)
			{
				cout << i + 1 << "-" << menu[i] << endl;
			}

			num_menu_right = false; //Resetea la variable por si repite.

			while (!num_menu_right) //Para verificar que introduce un numero del 1-5
			{
				cout << endl << "Inserta el numero que quieres" << endl;
				cin >> user_select_option;

				if ((int)user_select_option > 48 && (int)user_select_option < 54)
				{
					cout << "El numero insertado es correcto" << endl; //DEBUG
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

										tareas.push_back(cola); // Creamos un espacio para las tareas para este usuario

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

										passwords.insert(passwords.begin() + i, password_new_modify);

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
								char verification;
								bool user_exisist_delete = false;
								bool verification_correct = false;

								cout << "Inserta el usuario que quieres eliminar" << endl;
								cin >> user_delete;

								for (int i = 0; i < users.size(); i++)
								{

									if (users[i] == user_delete)
									{
										cout << "Users Exists" << endl;
										user_exisist_delete = true;
										cout << endl;

										while (!verification_correct)
										{
											cout << "Seguro que lo quieres eliminar S/N" << endl;
											cin >> verification;

											if ((int)verification == 83 || (int)verification == 78) // Verificamos en la tabla ASCII si es un Y/N
											{
												cout << "verificacion correcta." << endl;
												verification_correct = true;
											}
											else
											{
												cout << "No has introducido un character correcto (S / N)" << endl;
											}
										}

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

			if (user_select_option == '3') // Gestor de Directorios
			{
				system("cls");
				volver_gestionar_directorios = false;
				cout << "Estas logguedo como " << user_insert << endl;

				while (!volver_gestionar_directorios)
				{
					for (int i = 0; i < 5; i++)
					{
						cout << i + 1 << '-' << menu_gestionar_directorios[i] << endl;
					}

					bool numero_directorio_right = false;
					char user_directory;

					while (!numero_directorio_right)
					{
						cout << "Introduce que opcion quieres" << endl;
						cin >> user_directory;


						if ((int)user_directory > 48 && (int)user_directory < 54)
						{
							cout << "El numero insertado es correcto" << endl;
							numero_directorio_right = true;

						}
						else
						{
							cout << "El numero no esta entre el 1-5" << endl;
						}
					}
					if (user_directory == '1') //Ver Directorio
					{
						//Ver Directorio
					}
					if (user_directory == '2') //Crear Directorio
					{
						//Ver Directorio
					}
					if (user_directory == '3') //Renombrar Directorio
					{
						//Ver Directorio
					}
					if (user_directory == '4') //Eliminar Directorio
					{
						//Ver Directorio
					}

					if (user_directory == '5')
					{
						volver_gestionar_directorios = true;
					}


				}


			}
			if (user_select_option == '4') // Gestionar Tareas
			{
				system("cls");
				volver_gestionar_tareas = false;
				cout << "Estas logguedo como " << user_insert << endl;

				while (!volver_gestionar_tareas)
				{
					for (int i = 0; i < 4; i++)
					{
						cout << i + 1 << '-' << menu_gestionar_tareas[i] << endl;
					}
					bool numero_tareas_right = false;
					char user_tarea;

					while (!numero_tareas_right)
					{
						cout << "Introduce que opcion quieres" << endl;
						cin >> user_tarea;


						if ((int)user_tarea > 48 && (int)user_tarea < 53)
						{
							cout << "El numero insertado es correcto" << endl;
							numero_tareas_right = true;

						}
						else
						{
							cout << "El numero no esta entre el 1-4" << endl;
						}
					}

					if (user_tarea == '1')
					{
						string tarea_insertar;
						std::cin.ignore();

						cout << "Que tarea queres insertar" << endl;

						std::getline(std::cin, tarea_insertar);

						for (int i = 0; i < users.size(); i++)
						{
							if (users[i] == user_insert)
							{
								tareas[i].push(tarea_insertar);
							}
						}
						cout << "Tarea Insertada!" << endl;
						Sleep(3000); // Espera 5 SEG
						system("cls"); //Limpia la terminal
					}
					if (user_tarea == '2')
					{
						for (int i = 0; i < users.size(); i++)
						{

							if (users[i] == user_insert)
							{
								if (tareas[i].size() != 0) // Verificacion de que si quedan tareas.
								{
									cout << "Tu siguiente tarea es;" << endl;
									string tarea = tareas[i].front();
									cout << tarea << endl;
									Sleep(2000); // Espera 5 SEG
									system("cls"); //Limpia la terminal
								}
								else
								{
									cout << "No tienes Tareas Pendientes" << endl;
									Sleep(3000); // Espera 5 SEG
									system("cls"); //Limpia la terminal
								}
							}
						}

					}
					if (user_tarea == '3')
					{

						for (int i = 0; i < users.size(); i++)
						{
							if (users[i] == user_insert)
							{

								if (tareas[i].size() != 0)// Verificamos que no este vacio antes de sacar la ultima tarrea para que no de error
								{
									string tarea = tareas[i].front();
									cout << "La tarea completada:" << endl;
									cout << tarea << endl;
									tareas[i].pop();

									if (tareas[i].size() != 0)// Volvemos a verifica que no este vacio antes de sacar la ultima tarrea para que no de error.
									{
										cout << "La proxima tarea sera: " << tareas[i].front() << endl << endl;
										Sleep(3000); // Espera 5 SEG
										system("cls"); //Limpia la terminal 

									}
									else
									{
										cout << "No quedan mas tareas" << endl;
										cout << endl;
										Sleep(3000); // Espera 5 SEG 
										system("cls"); //Limpia la terminal 
									}
								}
								else
								{
									cout << "No quedan mas tareas" << endl;
									cout << endl;
									Sleep(3000); // Espera 5 SEG 
									system("cls"); //Limpia la terminal 
								}
							}

						}
					}

					if (user_tarea == '4')
					{
						volver_gestionar_tareas = true;
					}


				}
			}
			if (user_select_option == '5') // Cierra el panel
			{

				menu_principal = true;

			}
		}
		else // Si no es admin
		{
			for (int i = 1; i <= 4; i++) //Saca el menu desde 1-4 (Saca los 4 ultimos)
			{
				cout << i << "-" << menu[i] << endl;
			}
			num_menu_right = false;
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
			if (user_select_option == '1')
			{
				user_insert_right = false;
				system("cls");
			}
			if (user_select_option == '2')
			{
				cout << "Prova" << endl;
			}
			if (user_select_option == '3')
			{
				system("cls");
				volver_gestionar_tareas = false;
				cout << "Estas logguedo como " << user_insert << endl;

				while (!volver_gestionar_tareas)
				{
					for (int i = 0; i < 4; i++)
					{
						cout << i + 1 << '-' << menu_gestionar_tareas[i] << endl;
					}
					bool numero_tareas_right = false;
					char user_tarea;

					while (!numero_tareas_right)
					{
						cout << "Introduce que opcion quieres" << endl;
						cin >> user_tarea;


						if ((int)user_tarea > 48 && (int)user_tarea < 53)
						{
							cout << "El numero insertado es correcto" << endl;
							numero_tareas_right = true;

						}
						else
						{
							cout << "El numero no esta entre el 1-4" << endl;
						}
					}

					if (user_tarea == '1')
					{
						string tarea_insertar;
						std::cin.ignore();

						cout << "Que tarea queres insertar" << endl;

						std::getline(std::cin, tarea_insertar);

						for (int i = 0; i < users.size(); i++)
						{
							if (users[i] == user_insert)
							{
								tareas[i].push(tarea_insertar);
							}
						}
						cout << "Tarea Insertada!" << endl;
						Sleep(3000); // Espera 5 SEG
						system("cls"); //Limpia la terminal
					}
					if (user_tarea == '2')
					{
						for (int i = 0; i < users.size(); i++)
						{

							if (users[i] == user_insert)
							{
								if (tareas[i].size() != 0)
								{
									cout << "Tu siguiente tarea es;" << endl;
									string tarea = tareas[i].front();
									cout << tarea << endl;
									Sleep(4000); // Espera 5 SEG
									system("cls"); //Limpia la terminal
								}
								else
								{
									cout << "No tienes Tareas Pendientes" << endl;
									Sleep(3000); // Espera 5 SEG
									system("cls"); //Limpia la terminal
								}
							}
						}

					}
					if (user_tarea == '3')
					{
						for (int i = 0; i < users.size(); i++)
						{
							if (users[i] == user_insert)
							{

								if (tareas[i].size() != 0)// Verificamos que no este vacio antes de sacar la ultima tarrea para que no de error
								{
									string tarea = tareas[i].front();
									cout << "La tarea completada:" << endl;
									cout << tarea << endl;
									tareas[i].pop();

									if (tareas[i].size() != 0)// Volvemos a verifica que no este vacio antes de sacar la ultima tarrea para que no de error.
									{
										cout << "La proxima tarea sera: " << tareas[i].front() << endl << endl;
										Sleep(3000); // Espera 5 SEG
										system("cls"); //Limpia la terminal 

									}
									else
									{
										cout << "No quedan mas tareas" << endl;
										cout << endl;
										Sleep(3000); // Espera 5 SEG 
										system("cls"); //Limpia la terminal 
									}
								}
								else
								{
									cout << "No quedan mas tareas" << endl;
									cout << endl;
									Sleep(3000); // Espera 5 SEG 
									system("cls"); //Limpia la terminal 
								}
							}

						}
					}

					if (user_tarea == '4')
					{
						volver_gestionar_tareas = true;
					}


				}
			}

			if (user_select_option == '4')
			{
				menu_principal = true;

			}

		}

	}
}