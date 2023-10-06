#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv)
{
//Conector para acceder al servidor de bases de datos
MYSQL *conn;
int err;
MYSQL_RES*resultado;
MYSQL_ROW row;

//creamos una conexion al servidor
conn= mysql_init(NULL);
if(conn==NULL){
	printf ("Error al crear la conexion: %u %s\n", 
			mysql_errno(conn), mysql_error(conn));
	exit (1);
}
//inicializar la conexion, indicando nuestras claves de acceso
// al servidor de bases de datos (user,pass)
conn = mysql_real_connect (conn, "localhost","root", "mysql", NULL, 0, NULL, 0);
if (conn==NULL)
{
	printf ("Error al inicializar la conexion: %u %s\n", 
			mysql_errno(conn), mysql_error(conn));
	exit (1);
}	
//Contar el tiempo jugado de un jugador por su ID
printf ("Dame el ID de un jugador\n");
	scanf("%d",ID);
	strcpy(consulta,"SELECT TIEMPOTOTALJUGADO* FROM JUGADOR WHERE ID='");
	strcat(consulta,ID);
	strcat(consulta,"'");
	err=mysql_query(conn,consulta);
	
	if(err!=0){
		printf("Error al consultar los datos de la base %u%s\n",
			   mysql_errno(conn),mysql_error(conn));
		exit(1);
	}
	resultado=mysql_store_result(conn);
	
	row =mysql_fetch_row(resultado);
	if(row==NULL)
		printf ("No se han obtenido datos\n");
	else 
		while(row!=NULL){
		JUGADORMASRAPIDO=atoi(row[3]);
		
		printf("El tiempo jugado del jugador con id %d és %s\n",ID, row[7]);
		
		//obtenemos la siguiente fila
		row=mysql_fetch_row(resultado);

//cerrar la conexion 
		mysql_close(conn);
		exit(0);
}
}
